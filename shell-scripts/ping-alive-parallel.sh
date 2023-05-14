#!/usr/bin/env bash

NET="192.168.2."

# 定义并发数量
thread=16
# 以当前进程 pid 创建 fifo 文件, 防止冲突
FIFO_PATH=/tmp/$$.fifo
mkfifo ${FIFO_PATH}
# 定义当前进程打开管道文件（手动指定打开的文件描述符为8）
exec 8<> ${FIFO_PATH}
# 删除管道文件（当前进程没有释放文件描述符8, 不影响）
rm ${FIFO_PATH}

# 往管道文件（文件描述符8）里循环写入内容
for i in $(seq ${thread}); do
    # 给管道文件（文件描述符8）输入${thread}个回车
    #（写入任何记录都可以, 内容不重要, 添加${thread}条记录.
    # 重定向, 追加都可以,管道文件内容不会被覆盖）
    echo >&8
done

for i in {1..254}; do
    # read -u 读取一次文件描述符的内容
    #（read 读取不到内容就停止, 管道文件只能读取一次, 限制读取${thread}次）
    read -u 8
    {
        IP="$NET$i"
        ping -c1 -W1 $IP &>/dev/null && echo "$IP is up"
        # 给管道文件（描述符号8）写入一个回车（内容随意）
        echo >&8
    } &
done
wait

exec 8<&-
echo "complete"
