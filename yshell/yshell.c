/*
 * Original Author: unknown
 *
 * TAB Size: 8
 */
// #define _DEBUG 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#if defined(_DEBUG) && _DEBUG
	#define DPRINT(...)	do { fprintf(stderr, __VA_ARGS__); } while(0)
#else
	#define DPRINT(...)	do { ; } while(0)
#endif

int sig_z;
int sig_flag;
int pid1;
char *input;

#define CMD_SZ_MAX	1023
#define HISNUM		128

typedef struct ENV_HISTORY
{
	int start;
	int end;
	char his_cmd[HISNUM][CMD_SZ_MAX + 1];
} ENV_HISTORY;

typedef struct NODE
{
	pid_t pid;
	char cmd[CMD_SZ_MAX + 1];
	char state[10];
	struct NODE *link;
} NODE;
NODE *head, *end;
ENV_HISTORY envhis;

char *envpath[CMD_SZ_MAX + 1];
char buf[CMD_SZ_MAX + 1];

#define NO_PIPE		-1
#define FD_READ		0
#define FD_WRITE	1

int is_found();		/*查找命令的函数 */

int main(int argc, const char* argv[])
{
/****************************声明程序中用到的函数*****************************/
	int redirect();		/*重定向命令的处理函数 */
	int pipel();		/*管道命令的处理函数 */
	int get_line();		/*读取一行的函数 */
	void init_environ();	/*初始化环境变量的函数 */
	void getenviron();	/*初始化查找路径的函数 */
	void add_history();	/*记录history命令的函数 */
	void history_cmd();	/*显示history命令的函数 */
	void cd_cmd();		/*处理cd命令的函数 */
	void echo_cmd();	/*do echo command */
	void jobs_cmd();	/*处理jobs命令的函数 */
	void add_node();	/*向jobs命令的链表中增加节点函数 */
	void del_node();	/*向jobs命令的链表中删除节点函数 */
	void ctrl_z();		/*处理用户按下ctrl_z时的函数 */
	void setflag();		/*将标志位置一的函数 */
	void bg_cmd();		/*处理bg命令的函数 */
	void fg_cmd();		/*处理fg命令的函数 */

	init_environ();		/*初始化环境变量，将查找路径至于envpath[]中,
				   初始化history，和jobs的头尾指针 */

	/****************************    设置signal信号  *****************************/
	struct sigaction action;

	action.sa_sigaction = del_node;
	sigfillset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGCHLD, &action, NULL);
	signal(SIGTSTP, ctrl_z);

	while (1) {
		int c;
		char *arg[20];
		int i = 0, j = 0, k = 0, is_pr = 0, is_bg = 0, input_len = 0, pid = 0, status = 0;

	/****************************      打印提示符    *****************************/
		getcwd(buf, CMD_SZ_MAX);
		printf("ysh@%s> ", buf);

	/****************************     获取用户输入   *****************************/
		/*跳过空格等无用信息 */
		while ((c = getchar()) == ' ' || c == '\t' || c == EOF);
		if (c == '\n' || c == EOF)
			continue;				/*输入为空时结束本次循环打印提示符 */
		while (c != '\n') {
			buf[input_len++] = c;
			c = getchar();
		}
		buf[input_len] = '\0';	/*加上串结束符 */
		/*分配动态存储空间，将命令从缓存拷贝到input中 */
		input = (char *) malloc(sizeof(char) * (input_len + 1));
		strcpy(input, buf);

	/****************************       解析指令     *****************************/
		/******************管道和重定向命令单独处理**************/
		for (i = 0, j = 0, k = 0; i <= input_len; i++) {
			if (input[i] == '<' || input[i] == '>' || input[i] == '|') {
				if (input[i] == '|') {
					pipel(input, input_len);	/*管道命令 */
					add_history(input);
					free(input);
				} else {
					redirect(input, input_len);	/*重定向命令 */
					add_history(input);
					free(input);
				}
				is_pr = 1;
				break;
			}
		}

		/**********************   普通命令   ***********************/
		if (is_pr == 1)
			continue;
		for (i = 0, j = 0, k = 0; i <= input_len; i++) {
			if (input[i] == ' ' || input[i] == '\0') {
				if (j == 0)			/*这个条件略去连在一起的多个空格 */
					continue;
				else {
					buf[j++] = '\0';
					arg[k] = (char *) malloc(sizeof(char) * j);
					strcpy(arg[k++], buf);	/*将指令或参数拷到arg中 */
					j = 0;			/*准备取下一参数 */
				}
			} else {
				/*如果字符串最后是"&"，将后台命令标志置一 */
				if (input[i] == '&' && input[i + 1] == '\0') {
					DPRINT("background '%s'\n", input);
					is_bg = 1;
					continue;
				}
				buf[j++] = input[i];
			}
		}

		for (i = 0; i < k; i++) {
			DPRINT("arg[%d] = %s\n", i, arg[i]);
		}

		/**********************  内部命令的处理  ********************/
		/*exit命令，退出 */
		if (strcmp(arg[0], "exit") == 0) {
			add_history(input);
			printf("yshell exit now!\n");
			free(input);
			break;
		}

		/*history命令，显示history数组中保存的历史命令 */
		if (strcmp(arg[0], "history") == 0) {
			add_history(input);
			history_cmd();
			free(input);
			continue;
		}

		/*cd命令，改变当前路径 */
		if (strcmp(arg[0], "cd") == 0) {
			add_history(input);
			for (i = 3, j = 0; i <= input_len; i++)	/*获取路径 */
				buf[j++] = input[i];
			buf[j] = '\0';
			arg[1] = (char *) malloc(sizeof(char) * j);
			strcpy(arg[1], buf);			/*将路径保存到arg[1]中 */
			cd_cmd(arg[1]);				/*cd_cmd()函数，改变路径到指定路径 */
			free(input);
			continue;
		}

		/*echo command to print what you have just input */
		if (strcmp(arg[0], "echo") == 0) {
			add_history(input);
			for (i = 5, j = 0; i <= input_len; i++)	/*get the input of what you input */
				buf[j++] = input[i];
			buf[j] = '\0';
			arg[1] = (char *) malloc(sizeof(char) * j);
			strcpy(arg[1], buf);			/*save the context to arg[1] */
			echo_cmd(arg[1]);			/*echo_cmd()函数，print */
			free(input);
			continue;
		}

		/*jobs命令，显示现有工作 */
		if (strcmp(arg[0], "jobs") == 0) {
			add_history(input);
			jobs_cmd();				/*jobs_cmd()函数，遍历链表，显示所有工作 */
			free(input);
			continue;
		}

		/*bg命令，将作业放到后台执行 */
		if (strcmp(arg[0], "bg") == 0) {
			add_history(input);
			/* 获取制定的作业号，作业号在%后 */
			for (i = 0; i < input_len;) {
				if (input[i++] == '%')
					break;
			}
			for (; i <= input_len; i++)
				buf[j++] = input[i];
			buf[j] = '\0';
			arg[1] = (char *) malloc(sizeof(char) * j);
			strcpy(arg[1], buf);			/*将作业号保存在arg[1]中 */
			bg_cmd(atoi(arg[1]));			/*bg_cmd命令，将指定作业放到后台运行 */
			free(input);
			continue;
		}

		/*fg命令，将作业放到前台执行 */
		if (strcmp(arg[0], "fg") == 0) {
			add_history(input);
			/*获取制定的作业号，作业号在%后 */
			for (i = 0; i < input_len;) {
				if (input[i++] == '%')
					break;
			}
			for (; i <= input_len; i++)
				buf[j++] = input[i];
			buf[j] = '\0';
			arg[1] = (char *) malloc(sizeof(char) * j);
			strcpy(arg[1], buf);			/*将作业号保存在arg[1]中 */
			fg_cmd(atoi(arg[1]));			/*fg_cmd命令，将指定作业放到后台运行 */
			free(input);
			continue;
		}

	/****************************    寻找命令文件    *****************************/
		if (is_pr == 0) {				/*非管道、重定向命令 */
			/*在使用exec执行命令时，最后的参数必须是NULL指针，所以将其置空 */
			arg[k] = NULL;
			if (is_found(arg[0]) == 0) {		/*查找arg[0]中的命令是否存在 */
				printf("command '%s' not found!\n", arg[0]);
				for (i = 0; i < k; i++)
					free(arg[i]);
				continue;
			}
		}
		add_history(input);

	/****************************      执行命令      ******************************/
		if (is_bg == 1)	{				/*若为后台命令，等待父进程增加节点 */
			sig_flag = 0;				/*置零，为下一命令作准备 */
			/*若sig_flag==0，等待父进程完成增加节点 */
			/*等待父进程SIGUSR1信号，表示节点已加到链表中 */
			signal(SIGUSR1, setflag);
		}
		if ((pid = fork()) == 0) {			/*子进程 */
			if (is_bg == 1)	{			/*若为后台命令，等待父进程增加节点 */
				/* 收到信号，setflag函数将sig_flag
				 * 置一，以跳出循环
				 */
				while (sig_flag == 0)
					sleep(0);
			}
			execv(buf, arg);			/*执行命令 */
		} else {					/*父进程 */
			pid1 = pid;				/*保存子进程进程号 */
			if (is_bg == 1) {			/*后台命令 */
				add_node(input, pid1);		/*增加节点 */
				kill(pid, SIGUSR1);		/*向子进程发信号，表示节点已加进链表 */
				pid1 = 0;			/*pid1置零，为下一命令作准备 */
			}
			if (is_bg == 0)				/*前台命令 */
				/* WUNTRACED, return if the waited process stopped */
				waitpid(pid, &status, WUNTRACED);
		}
		if (is_bg == 1)
			/*等待命令（如：ls &）输出后,再打印shell提示符 */
			;//sleep(1);
		for (i = 0; i < k; i++)				/*释放空间 */
			free(arg[i]);
		free(input);
	}
}

/****************************      主程序完      *****************************/

/****************************    重定向的处理    *****************************/
int redirect(char *in, int len)
{
	char *argv[20], *filename[20];
	pid_t pid;
	int i, j, k, fd_in, fd_out, is_in = -1, is_out = -1, num = 0;
	int is_back = 0, status = 0;

	/************************命令解析*************************/
	/*argv[]用于存放命令和参数，filename用于存放重定向文件名，
	   is_in,is_out分别是重定向输入标记和输出标记 */
	for (i = 0, j = 0, k = 0; i <= len; i++) {
		if (in[i] == ' ' || in[i] == '\t' || in[i] == '\0' || in[i] == '<' || in[i] == '>') {
			if (in[i] == '>' || in[i] == '<') {
				if (num < 3) {	/*num存放重定向符号的出现次数 */
					num++;
					if (in[i] == '<')
						is_in = num - 1;	/*存在重定向输入is_in置-1 */
					else
						is_out = num - 1;	/*存在重定向输出is_out置-1 */

					if (j > 0 && num == 1) {	/*处理命令和重定向符号相连的问题 */
						buf[j++] = '\0';
						argv[k] = (char *) malloc(sizeof(char) * j);
						strcpy(argv[k++], buf);
						j = 0;			/*为读取下一命令或参数作准备 */
					}
				} else {
					printf("Error command!\n");
					return 0;
				}
			}
			if (j == 0)
				continue;
			else {
				buf[j++] = '\0';
				if (num == 0) {			/*尚未遇到重定向符号，字符串是参数或命令 */
					argv[k] = (char *) malloc(sizeof(char) * j);
					strcpy(argv[k++], buf);
					j = 0;
				} else {			/*遇到重定向符号，字符串是文件名 */
					filename[status] = (char *) malloc(sizeof(char) * j);
					strcpy(filename[status++], buf);
					j = 0;
				}
			}
		} else {					/*父进程 */
			if (in[i] == '&' && in[i + 1] == '\0') {/*是否为后台命令 */
				is_back = 1;
				continue;
			}
			buf[j++] = in[i];
		}
	}

	/*************************寻找命令文件*************************/
	argv[k] = (char *) 0;					/*最后一参数置空 */

	if (is_found(argv[0]) == 0) {	/*查找命令文件 */
		printf("command '%s' not found !\n", argv[0]);
		for (i = 0; i <= k; i++)
			free(argv[i]);
		return 0;
	}

	/************************命令的执行**************************/
	if ((pid = fork()) == 0) {
		if (is_out != -1) {				/*存在输出重定向 */
			if ((fd_out = open(filename[is_out],	/*将文件描述符fd_out指向文件 */
					   O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) == -1) {
				printf("Can not open %s \n", filename[is_out]);
				return 0;
			}
		}

		if (is_in != -1) {				/*存在输入重定向 */
			if ((fd_in = open(filename[is_in],	/*将文件描述符fd_in指向文件 */
					  O_RDONLY, S_IRUSR | S_IWUSR)) == -1) {
				printf("Can not open %s \n", filename[is_in]);
				return 0;
			}
		}

		if (is_out != -1) {
			/*使用dup2函数将标准输出重定向到fd_out上，
			   这样原来输出到标准输出的内容，将输出到fd_out
			   所指向的文件。这就达到了重定向的目的 */
			if (dup2(fd_out, STDOUT_FILENO) == -1) {
				printf("Redirect standard out error!\n");
				exit(1);
			}
		}

		if (is_in != -1) {
			/*使用dup2函数将标准输入重定向到fd_in上，
			   这样原来从标准输入输入的内容，将从fd_in
			   所指向的文件输入。这就达到了重定向的目的 */
			if (dup2(fd_in, STDIN_FILENO) == -1) {
				printf("Redirect standard in error!\n");
				exit(1);
			}
		}

		execv(buf, argv);
	} else {
		/*父进程,判断是否需要等待子进程的完成 */
		if (is_back == 0)
			waitpid(pid, &status, 0);
	}

	/**************************释放空间*************************/
	for (i = 0; i <= k; i++)
		free(argv[i]);
	if (is_out != -1) {
		free(filename[is_out]);
		close(fd_out);
	}
	if (is_in != -1) {
		free(filename[is_in]);
		close(fd_in);
	}
	return 0;
}

/****************************     管道的处理     *****************************/
#define PIPES_MAX 10
int pipel(char *input, int len)
{
	char *argv[PIPES_MAX][30], *filename[1];
	int i, j, k, is_bg = 0;
	int li_cmd = 0, fd[PIPES_MAX][2], pipe_in = -1, pipe_out = -1, flag = 0;
	pid_t pid;

	/************************命令解析*************************/
	/*此部分功能和结构与重定向时的命令解析相似 */
	for (i = 0, j = 0, k = 0; i <= len; i++) {
		if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n'
		|| input[i] == '\0' || input[i] == '|' || input[i] == '>'
		) {
			if (input[i] == '|' || input[i] == '>') {
				if (input[i] == '>')
					flag = 1;
				if (j > 0) {
					buf[j++] = '\0';
					argv[li_cmd][k] = (char *) malloc(sizeof(char) * j);
					DPRINT("argv[%d][%d] = %s\n", li_cmd, k, buf);
					strcpy(argv[li_cmd][k++], buf);
				}
				argv[li_cmd++][k] = (char *) 0;
				k = 0;
				j = 0;
			}
			if (j == 0)
				continue;
			else {
				buf[j++] = '\0';
				if (flag == 0) {
					/* 命令中不含">","<"重定向命令 */
					argv[li_cmd][k] = (char *) malloc(sizeof(char) * j);
					DPRINT("argv[%d][%d] = %s\n", li_cmd, k, buf);
					strcpy(argv[li_cmd][k++], buf);
				} else {
					/* 命令中包含">","<"重定向命令,重定向命令后为文件名 */
					filename[0] = (char *) malloc(sizeof(char) * j);
					strcpy(filename[0], buf);
				}
			}
			j = 0;
		} else {
			if (input[i] == '&' && input[i++] == '\0') {	/*带后台符号的命令 */
				is_bg = 1;
				continue;
			}
			buf[j++] = input[i];
		}
	}

	argv[li_cmd][k++] = (char *) 0;				/*最后一参数置空 */

	for (i = 0; i < PIPES_MAX; i++) {			/*初始化文件描述符 */
		fd[i][FD_READ] = NO_PIPE;
		fd[i][FD_WRITE] = NO_PIPE;
	}

	for (i = 0; i < li_cmd; i++) {				/*为命令建立相应的管道 */
		if (pipe(fd[i]) == -1) {
			printf("can not open pipe!\n");
			return 0;
		}
	}

	/*************************寻找命令文件,执行命令*************************/
	for (i = 0; i <= li_cmd; i++) {
		if (is_found(argv[i][0]) == 0) {
			printf("could not found command '%s'!\n", argv[i][0]);
			break;
		}
		DPRINT("pipe-cmd[%d] = %s\n", i, argv[i][0]);

		/*********将pipe_in指向到管道的读端（第一条命令除外）***********/
		if (i != 0)
			pipe_in = fd[i - 1][FD_READ];
		else
			pipe_in = NO_PIPE;	/*第一条命令除外 */

		/*********将pipe_out指向到管道的写端（最后一条命令除外）*********/
		if (i != li_cmd)
			pipe_out = fd[i][FD_WRITE];
		else if (flag == 1) {		/*包含重定向命令 */
			/*将pipe_out指向到文件 */
			if ((pipe_out = open(filename[0],
			                     O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)
			) == -1) {
				printf("Can not open %s \n", filename[0]);
				break;
			}
		} else
			pipe_out = NO_PIPE;			/*最后一条命令除外 */

		if ((pid = fork()) < 0) {
			printf("fork failed!\n");
			return 0;
		}

		if (pid == 0) {
			if (pipe_in == NO_PIPE)
				close(pipe_in);
			if (pipe_out == NO_PIPE)
				close(pipe_out);

			if (pipe_out != NO_PIPE) {
				/*将标准输出重定向到管道的写端，
				   这样该子进程的输出就写入管道了 */
				dup2(pipe_out, 1);
				close(pipe_out);
			}

			if (pipe_in != NO_PIPE) {
				/*将标准输入重定向到管道的读端，
				   这样管道的数据就可以被读到了 */
				dup2(pipe_in, 0);
				close(pipe_in);
			}
			execv(buf, argv[i]);
		} else {
			if (is_bg == 0)
				waitpid(pid, NULL, 0);
			close(pipe_in);
			close(pipe_out);
		}
	}
	return 0;
}

/****************************     初始化函数     *****************************/
int get_line(int fd, char *buf)
{	/*按行读取 */
	int i = 0;
	char c;

	while (read(fd, &c, 1)) {
		buf[i++] = c;
		if (c == '\n') {
			buf[i - 1] = '\0';
			return i;
		}
	}
	buf[i] = '\0';
	return i;
}

void getenviron(int n, char *s)
{
	int i = 0, j = 0, k = 0;
	char c, buff[80], *p;

	while ((c = s[i]) && c != '=') {
		buff[i++] = c;
	}
	buff[i++] = '\0';
	if (strcmp(buff, "PATH") == 0) {
		for (;;i++) {
			/*将以":"分隔的查找路径分别设置到envpath[]中 */
			if (s[i] == ':' || s[i] == '\0') {
				buff[j++] = '/';
				buff[j] = '\0';
				p = (char *) malloc(strlen(buff) + 1);
				strcpy(p, buff);
				envpath[k++] = p;	/*将路径保存在envpath[k]中 */
				envpath[k] = NULL;	/*字符串尾置空 */
				j = 0;			/*为下一个envpath[i]作准备 */
				if (s[i] == '\0') {
					break;
				}
			} else {
				buff[j++] = s[i];
			}
		}
	} else
		DPRINT("No match '%s'\n", s);
}

void init_environ()
{
	int fd, n, i;
	char buf[80];

	/*打开保存查找路径的ysh_profile文件 */
	if ((fd = open("ysh_profile", O_RDONLY, 660)) == -1) {
		printf("init environ variable error\n");
		exit(1);
	}
	while (n = get_line(fd, buf)) {
		getenviron(n, buf);		/*getenviron()函数 */
	}
	envhis.start = 0;			/*初始化history循环数组 */
	envhis.end = 0;
	head = end = NULL;			/*初始化jobs链表指针 */
}

/****************************  查找命令文件函数  *****************************/
int is_found(char *cmd)
{
	int k = 0;

	if (cmd[0] == '/' && access(cmd, F_OK) == 0) {
		return 1;
	}

	/*查找路径已在程序初始化时设定在envpath[i]中 */
	while (envpath[k] != NULL) {
		strcpy(buf, envpath[k++]);
		strcat(buf, cmd);
		if (access(buf, F_OK) == 0) {	/*文件被找到 */
			DPRINT("found %s\n", buf);
			return 1;
		}
	}
	return 0;
}

/****************************     history命令    *****************************/
void add_history(char *inputcmd)
{
	envhis.end = (envhis.end + 1) % HISNUM;			/*end前移一位 */
	if (envhis.end == envhis.start) {			/*end和start指向同一数组 */
		envhis.start = (envhis.start + 1) % HISNUM;	/*start前移一位 */
	}
	strcpy(envhis.his_cmd[envhis.end], inputcmd);		/*将命令复制到end指向的数组中 */
}

void history_cmd()
{
	int i, j = 0;

	if (envhis.start == envhis.end)				/*循环数组为空 */
		return;
	else if (envhis.start < envhis.end) {			/*start<end时 */
		/*显示start+1到end数组中的命令 */
		for (i = envhis.start + 1; i <= envhis.end; i++) {
			printf("%d\t%s\n", j++, envhis.his_cmd[i]);
		}
	} else {						/*start>end时 */
		/*显示start+1到HISNUN数组中的命令 */
		for (i = envhis.start + 1; i < HISNUM; i++) {
			printf("%d\t%s\n", j++, envhis.his_cmd[i]);
		}
		/*显示0到end数组中的命令 */
		for (i = 0; i <= envhis.end; i++) {
			printf("%d\t%s\n", j++, envhis.his_cmd[i]);
		}
	}
}

/****************************        cd命令      *****************************/
void cd_cmd(char *route)
{
	if (route != NULL) {			/*路径不为空 */
		if (chdir(route) < 0) {		/*chdir()系统调用，改变当前路径 */
			printf("'cd %s': error file or directory!\n", route);
		}
	}
}

/**************************************************************/
void echo_cmd(char *contest)
{
	if (contest != NULL) {
		printf("%s\n", contest);
	}
}

/**************************** jobs命令 *****************************/
void jobs_cmd()
{
	NODE *p;
	int i = 1;

	p = head;
	/*遍历链表，显示相关内容 */
	if (head != NULL) {			/*链表不为空 */
		do {
			printf("%d  %d  %s\t%s\n", i++, p->pid, p->state, p->cmd);
			p = p->link;
		} while (p != NULL);
	} else
		printf("no jobs!\n");		/*链表为空 */
}

void add_node(char *input_cmd, int node_pid)
{
	NODE *p;

	p = (NODE *) malloc(sizeof(NODE));	/*申请新节点 */
	p->pid = node_pid;			/*设置节点信息 */
	strcpy(p->cmd, input_cmd);		/*保存命令信息 */
	strcpy(p->state, "running");		/*设置工作状态 */
	p->link = NULL;
	if (head == NULL) {			/*若链表为空 */
		head = p;
		end = p;
	} else {				/*链表不为空 */
		end->link = p;			/*将链表尾节点指针指向新节点 */
		end = p;			/*将end指向链表尾 */
	}
}

void del_node(int sig, siginfo_t * sip)
{						/*删除节点 */
	NODE *q, *p;
	int id;

	/*当按下ctrl-z时，也会收到SIGCHLD信号，这种情况不删除节点 */
	if (sig_z == 1) {
		sig_z = 0;
		goto out;
	}

	id = sip->si_pid;			/*获得(发出SIGCHLD信号的)进程号 */
	p = q = head;
	if (head == NULL)
		goto out;			/*链表为空 */

	/*遍历链表找到相应节点 */
	while (p->pid != id && p->link != NULL)	/*找到要删除的节点p */
		p = p->link;
	if (p->pid != id) {
		goto out;
	}
	if (p == head) {			/*p为头节点 */
		head = head->link;
	} else {
		while (q->link != p)		/*找到p的前驱节点q */
			q = q->link;
		if (p == end) {			/*p为尾节点 */
			end = q;
			q->link = NULL;
		} else
			q->link = p->link;
	}
	free(p);
out:
	return;
}

void setflag()
{
	sig_flag = 1;
}

/****************************   前后台切换命令   *****************************/
void ctrl_z()
{
	NODE *p;
	int i;

	if (pid1 == 0)
		goto out;				/*前台没有工作 */

	/*改变链表中的相应节点的状态 */
	if (head != NULL) {				/*链表不为空 */
		p = head;
		/*遍历链表，看该工作是否已经在链表中 */
		while (p->pid != pid1 && p->link != NULL)
			p = p->link;
		if (p->pid == pid1) {			/*工作已在链表中 */
			strcpy(p->state, "stopped");
		} else {				/*工作不在链表中 */
			add_node(input, pid1);		/*增加新节点 */
			strcpy(end->state, "stopped");	/*设置节点状态 */
		}
	} else {					/*连标为空 */
		add_node(input, pid1);			/*增加新节点 */
		strcpy(end->state, "stopped");		/*设置节点状态 */
	}

	/*sig_z标志置一，del_node()函数中不用删除节点 */
	sig_z = 1;
	/*发送SIGSTOP信号给正在前台运行的工作，将其停止 */
	kill(pid1, SIGSTOP);
	for (i = 1, p = head; p->pid != pid1; p = p->link)
		i++;
	printf("[%d]\t%s\t%s\n", i, end->state, end->cmd);/*显示提示信息 */
	pid1 = 0;
out:
	return;
}

void bg_cmd(int job_num)
{
	NODE *p;
	int i;

	p = head;
	/*根据作业号，遍历链表，找到指定节点 */
	for (i = 1; p && i < job_num; i++)
		p = p->link;
	if (!p) {
		printf("no job %%%d\n",  job_num);
		return;
	}
	kill(p->pid, SIGCONT);		/*向对应工作发送SIGCONT信号，使其在后台运行 */
	strcpy(p->state, "running");	/*修改对应节点状态 */
}

void fg_cmd(int job_num)
{
	NODE *p;
	int i;

	p = head;
	/*根据作业号，遍历链表，找到指定节点 */
	for (i = 1; p && i < job_num; i++)
		p = p->link;
	if (!p) {
		printf("no job %%%d\n",  job_num);
		return;
	}
	strcpy(p->state, "running");	/*修改对应节点状态 */
	strcpy(input, p->cmd);		/*将命令名复制到input中，为下一次按下ctrl-z作准备 */
	pid1 = p->pid;			/*获取该节点对应工作的进程号 */
	kill(p->pid, SIGCONT);		/*向对应工作发送SIGCONT信号，使其运行 */
	sleep(0);			/*Give the chance to start run the job */
	waitpid(p->pid, NULL, 0);	/*父进程等待前台进程的运行 */
}
