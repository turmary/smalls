/*****************************************************************************
Programmer:	Tary
Company:        Loyscol
Ver:		1.2
LastModified:	1/15/2007
Envirenment:	Turbo C2.0
Function:       Demostrate a 3D cube, which can translate, rotate, zoom in,
		zoom out...
		You are a viewer,
		use key j,k,l,i to change states, including your position
		, your view degree and so on...
		use key q,w,e,r to change mode, like move forward/back,
		move up/down, ratate up/down or rotate left/right...
		use key Esc to quit this program...

resolved in 1.2	Now it has a problem, that is memory allocation linked
		with use of pointer, if you can solve it, please contact
		to me...
*****************************************************************************/

#include <graphics.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
#define COUNT 2			/* the number of cube in this program */
#define KEY_ESC 27
#define DEBUG 0			/*condition compiling..... */
#undef	DEBUG
#define VIEW_FOOT 0

int VIEW_P;
typedef int color;
typedef enum {
	FORWARD,
	BACK,
	LEFT,
	RIGHT,
	UP,
	DOWN
} DIRECTION;
typedef enum {
	MOVEHORIZONTAL,
	MOVEVERTICAL,
	ROTATEUPDOWN,
	ROTATELEFTRIGHT
} MODE;
typedef struct {
	double d[3];
	color c;
} point;
typedef struct {
	point p[2][4];
	point basep;
	color linec;
} cube;
typedef struct {
	double d[3];
} vect;
int basex, basey;
point viewpoint;
vect viewvect;

double vectmul2(vect, vect);
void vectprint(vect *);
vect *vectadd(vect v1, vect v2)
{
	static vect v3;
	vect *vp3 = &v3;
	int i;

	/*printf("function vectadd\n"); */
	for (i = 0; i < 3; i++)
		vp3->d[i] = v1.d[i] + v2.d[i];
	return vp3;
}

double vectlong(vect v1)
{
	double t, s = 0.0f;
	int i;

	/*printf("function vectlong\n"); */
	for (i = 0; i < 3; i++)
		if (3e100 > fabs(s)) {
			s += pow(v1.d[i], 2);
#ifdef DEBUG
			printf("%d\n", (int) v1.d[i]);
#endif
		}
	t = sqrt(s);
	return t;
}

double vectmul2(vect v1, vect v2)
{
	double t = 0;
	int i;

	/*printf("function vectmul2\n"); */
	for (i = 0; i < 3; i++)
		t += v1.d[i] * v2.d[i];
	return t;
}

double vectdeg(vect v1, vect v2)
{
	double t, s;

	/*printf("function vectdeg\n"); */
	s = vectlong(v1) * vectlong(v2);
	if (fabs(s) < 1e-10)
		return 0.0;
	t = vectmul2(v1, v2) / s;
	s = acos(t);
	return s;
}

double vectdegs(vect v1, int ty)
{
	/*printf("function vectdegs\n"); */
	if (0 <= ty && ty < 3)
		return v1.d[ty] / vectlong(v1);
	else
		return 0;
}

vect *vectmulc(double l, vect v1)
{
	static vect v3;
	vect *vp3 = &v3;
	int i = 0;

	/*printf("function vectmulc\n"); */
	for (; i < 3; i++)
		vp3->d[i] = v1.d[i] * l;
	return vp3;
}

vect *vectmul(vect v1, vect v2)
{
	static vect v3;
	vect *vp3 = &v3;

	/*printf("function vectmul\n"); */
	vp3->d[0] = v1.d[1] * v2.d[2] - v1.d[2] * v2.d[1];
	vp3->d[1] = v1.d[2] * v2.d[0] - v1.d[0] * v2.d[2];
	vp3->d[2] = v1.d[0] * v2.d[1] - v1.d[1] * v2.d[0];
	return vp3;
}

vect *vectrotate(vect v1, vect v2, int m)
{
	static vect v3;
	vect *vp3 = &v3;

	/*printf("function vectrotate\n"); */
	switch (m) {
	case 0:
		vp3->d[0] = v1.d[0];
		vp3->d[1] = v1.d[1] * v2.d[1] - v1.d[2] * v2.d[2];
		vp3->d[2] = v1.d[1] * v2.d[2] + v1.d[2] * v2.d[1];
		break;
	case 1:
		vp3->d[0] = v1.d[0] * v2.d[0] - v1.d[2] * v2.d[2];
		vp3->d[1] = v1.d[1];
		vp3->d[2] = v1.d[0] * v2.d[2] + v1.d[2] * v2.d[0];
		break;
	default:
		vp3->d[0] = v1.d[0] * v2.d[0] - v1.d[1] * v2.d[1];
		vp3->d[1] = v1.d[0] * v2.d[1] + v1.d[1] * v2.d[0];
		vp3->d[2] = v1.d[2];
		break;
	}
	return vp3;
}

void paintcube(cube c)
{
	int i = 0;
	/*printf("function paintcube\n"); */
	/*line(0, 0, 640, 480); */
	for (; i < 4; i++) {
		line((int) (basex + c.p[0][i].d[0]),
		     (int) (basey + c.p[0][i].d[1]),
		     (int) (basex + c.p[1][i].d[0]),
		     (int) (basey + c.p[1][i].d[1]));
		/*printf("%d %d %d %d\n", (int)(basex + c.p[0][i].d[0]),
		   (int)(basey + c.p[0][i].d[1]),
		   (int)(basex + c.p[1][i].d[0]),
		   (int)(basey + c.p[1][i].d[1]));
		   line(0, 0,
		   (int)(basex + c.p[1][i].d[0]),
		   (int)(basey + c.p[1][i].d[1])); */
		line((int) (basex + c.p[0][i].d[0]),
		     (int) (basey + c.p[0][i].d[1]),
		     (int) (basex + c.p[0][(i + 1) % 4].d[0]),
		     (int) (basey + c.p[0][(i + 1) % 4].d[1]));
		line((int) (basex + c.p[1][i].d[0]),
		     (int) (basey + c.p[1][i].d[1]),
		     (int) (basex + c.p[1][(i + 1) % 4].d[0]),
		     (int) (basey + c.p[1][(i + 1) % 4].d[1]));
	}
}

vect *point2vect(point * p)
{
	static vect v3;
	vect *vpt = &v3;
	int i;

	/*printf("function point2vect\n"); */
	for (i = 0; i < 3; i++) {
		(*vpt).d[i] = p->d[i];
	}
	return vpt;
}

point *vect2point(vect v1)
{
	static point p3;
	point *ppt = &p3;
	int i;

	/*printf("function vect2point\n"); */
	for (i = 0; i < 3; i++)
		(*ppt).d[i] = v1.d[i];
	return ppt;
}

/*convert a point to a plane */
point *convert2d(vect * p)
{
	static point p3;
	/*the core code of my program */
	vect ptx, pty, *vpt1 = NULL;
	point *ppt = &p3;
	double t;

	/*printf("function convert2d\n"); */
	t = sqrt(pow(viewvect.d[0], 2) + pow(viewvect.d[1], 2));
	ptx.d[0] = viewvect.d[1] / t;
	ptx.d[1] = viewvect.d[0] / t;
	ptx.d[2] = 0;
	pty = *vectmul(viewvect, ptx);
#ifdef DEBUG
	vectprint(&ptx);
	vectprint(&pty);
#endif
	vpt1 = vectmulc(-1, viewvect);
	vpt1 = vectadd(*vpt1, *p);
	ppt->d[0] = vectlong(*vpt1) * cos(vectdeg(ptx, *vpt1)) * basex * 2;
	ppt->d[1] = vectlong(*vpt1) * cos(vectdeg(pty, *vpt1)) * basey * 2;
	ppt->d[2] = 0;
	return ppt;
}

/*convert every point of the spcified cube
to a plane */
cube *convertcube2d(cube c)
{
	static cube c3;
	cube *ct = &c3;
	vect *vpt = NULL;

	int i, j;
	/*printf("function convertcube2d\n"); */
	for (i = 0; i < 2; i++)
		for (j = 0; j < 4; j++) {
			vpt = point2vect(&c.p[i][j]);
			ct->p[i][j] = *convert2d(vpt);
		}
	return ct;
}

/* convert every point of cube
to a new cube set of a point of intersection*/
void *convertcube(cube c)
{
	static cube c3;
	cube *cpt = &c3;
	int i, j, k;

	/*printf("function convertcube\n"); */
	for (i = 0; i < 2; i++)
		for (j = 0; j < 4; j++) {
			vect tij;
			double deta;

			tij = *vectadd(*point2vect(&c.p[i][j]),
				 *vectmulc(-1, *point2vect(&viewpoint)));
			deta = vectdeg(viewvect, tij);
			tij =
			    *vectmulc(vectlong(viewvect) / cos(deta) /
				      vectlong(tij), tij);
			/*tij = *vectadd(*point2vect(&viewpoint), tij); */
			cpt->p[i][j] = *((point *) vect2point(tij));
		}
	return cpt;
}

void vectprint(vect * v1)
{
	printf("(%lf,%lf,%lf)\n", v1->d[0], (*v1).d[1], (*v1).d[2]);
}

void cubeprint(cube c)
{
	int i, j;
	static vect v3;
	vect *vt = &v3;

	printf("The cube C:\n");
	for (i = 0; i < 2; i++)
		for (j = 0; j < 4; j++) {
			printf("Point (%d,%d) = ", i, j);
			vt = point2vect(&c.p[i][j]);
			vectprint(vt);
		}
	return;
}

void paint(cube *, int);
void move(int);
void rotate(int);

int savepic(char *);
int showpic(char *);

int main(int argc, char *argv[])
{
	int driver = VGA, mode = VGAHI, CMode = MOVEHORIZONTAL;
	char t;

	vect v3, *vpt = &v3;
	/*vect v1[3]; */

	point p3, *pp = &p3;
	cube c[3], s;
	FILE *fp = NULL;

	if (argc > 2) {
		printf("Parameter Error!\n");
		printf("Example: -foot or null\n");
		exit(2);
	} else if (argc == 2 && !strcmp(argv[1], "-foot"))
		VIEW_P = 1;
	else
		VIEW_P = 0;
	/*printf("%d %s \n", strcmp(argv[1], "-foot"), argv[1]); */

	getch();
	registerbgidriver(EGAVGA_driver);
	initgraph(&driver, &mode, "");
	printf("\n\n");
	cleardevice();
	setcolor(YELLOW);
	setbkcolor(BLACK);

#ifdef DEBUG
	/*line(-5000, -5000, 5000, 5000);
	   while((t = getch()))
	   printf("%02x\n", t); */
#endif

	basex = getmaxx() / 2;
	basey = getmaxy() / 2;
	viewpoint.d[0] = 500;
	viewpoint.d[1] = 0;
	viewpoint.d[2] = 0;
	if (NULL != (fp = fopen("GRAP_Y5.TXT", "rb"))) {
		fread(pp, sizeof(point), 1, fp);
		fread(&viewvect, sizeof(vect), 1, fp);
		fclose(fp);
	}
	viewpoint = *pp;

	/*vectprint(point2vect(&viewpoint)); */

	viewvect.d[0] = 0;
	viewvect.d[1] = 1;
	viewvect.d[2] = 0;

#ifdef DEBUG
	v1[0] = *point2vect(&viewpoint);
	vectprint(&v1[0]);
	v1[1] = *vectadd(v1[0], viewvect);
	vectprint(&v1[1]);
	{
		double ft;
		int i;
		point pt;
		printf("%f \n", vectlong(v1[1]));
		vectprint(&v1[0]);
		vectprint(&v1[1] s);
		printf("%f \n", vectmul2(v1[1], v1[0]));
		ft = vectdeg(viewvect, v1[1]);
		ft = 180 / PI;
		printf("%lf \n", ft);
		vectprint(&v1[1]);
		for (i = 0; i < 3; i++) {
			ft = acos(vectdegs(v1[1], i));
			ft *= 180 / PI;
			printf("%c %lf \n", 88 + i, ft);
		}
		vectprint(&v1[1]);
		v1[1] = *vectmulc(2, v1[1]);
		vectprint(&v1[1]);
		vectprint(&viewvect);
		v1[2] = *vectmul(v1[1], viewvect);
		vectprint(&v1[2]);
		pt = *(point *) vect2point(v1[2]);
		vectprint(point2vect(&pt));
	}
	/*exit(1); */
#endif

	c[0].p[0][0].d[0] = 490;
	c[0].p[0][0].d[1] = 490;
	c[0].p[0][0].d[2] = 70;
	c[0].p[0][1].d[0] = 510;
	c[0].p[0][1].d[1] = 490;
	c[0].p[0][1].d[2] = 70;
	c[0].p[0][2].d[0] = 510;
	c[0].p[0][2].d[1] = 510;
	c[0].p[0][2].d[2] = 70;
	c[0].p[0][3].d[0] = 490;
	c[0].p[0][3].d[1] = 510;
	c[0].p[0][3].d[2] = 70;
	c[0].p[1][0].d[0] = 490;
	c[0].p[1][0].d[1] = 490;
	c[0].p[1][0].d[2] = 100;
	c[0].p[1][1].d[0] = 510;
	c[0].p[1][1].d[1] = 490;
	c[0].p[1][1].d[2] = 100;
	c[0].p[1][2].d[0] = 510;
	c[0].p[1][2].d[1] = 510;
	c[0].p[1][2].d[2] = 100;
	c[0].p[1][3].d[0] = 490;
	c[0].p[1][3].d[1] = 510;
	c[0].p[1][3].d[2] = 100;

	c[1].p[0][0].d[0] = 490;
	c[1].p[0][0].d[1] = 490;
	c[1].p[0][0].d[2] = 100;
	c[1].p[0][1].d[0] = 510;
	c[1].p[0][1].d[1] = 490;
	c[1].p[0][1].d[2] = 100;
	c[1].p[0][2].d[0] = 510;
	c[1].p[0][2].d[1] = 510;
	c[1].p[0][2].d[2] = 100;
	c[1].p[0][3].d[0] = 490;
	c[1].p[0][3].d[1] = 510;
	c[1].p[0][3].d[2] = 100;
	c[1].p[1][0].d[0] = 500;
	c[1].p[1][0].d[1] = 500;
	c[1].p[1][0].d[2] = 120;
	c[1].p[1][1].d[0] = 500;
	c[1].p[1][1].d[1] = 500;
	c[1].p[1][1].d[2] = 120;
	c[1].p[1][2].d[0] = 500;
	c[1].p[1][2].d[1] = 500;
	c[1].p[1][2].d[2] = 120;
	c[1].p[1][3].d[0] = 500;
	c[1].p[1][3].d[1] = 500;
	c[1].p[1][3].d[2] = 120;

#ifdef DEBUG
	{
		cubeprint(c[0]);
		cp = (cube *) convertcube(c[0]);
		cubeprint(*cp);
		c[1] = *cp;
		cp = (cube *) convertcube2d(c[1]);
		cubeprint(*cp);
		paintcube(c[0]);
	}
	printf("%d %d %d %d",
	       sizeof(char), sizeof(vect), sizeof(point), sizeof(cube));
#endif

	while ((t = getch()) != KEY_ESC && t != 'y') {
		int i;

		/*printf("%d\n", t); */

		switch (t) {
		case 'q':
			CMode = MOVEHORIZONTAL;
#ifdef DEBUG
			printf("Move Horizontal\n");
#endif
			break;
		case 'w':
			CMode = MOVEVERTICAL;
#ifdef DEBUG
			printf("Move Vertical\n");
#endif
			break;
		case 'e':
			CMode = ROTATEUPDOWN;
#ifdef DEBUG
			printf("Rotate UpDown\n");
#endif
			break;
		case 'r':
			CMode = ROTATELEFTRIGHT;
#ifdef DEBUG
			printf("Rotate LeftRight\n");
#endif
			break;
		case 'a':
#ifdef DEBUG
			printf("Viewpoint Reset");
#endif
			viewpoint.d[0] = 500;
			viewpoint.d[1] = 300;
			viewpoint.d[2] = 75;
			break;
		case 's':
#ifdef DEBUG
			printf("Viewvect Reset->");
#endif
			viewvect.d[0] = 0;
			viewvect.d[1] = 1;
			viewvect.d[2] = 0;
			break;
		case 'd':
			vectprint(&viewvect);
			break;
		case 'f':
			vpt = point2vect(&viewpoint);
			vectprint(vpt);
			break;
		case 'x':
			savepic("VRAM.DAT");
			break;
		case 'c':
			cleardevice();
			break;
		case 'v':
			showpic("VRAM.DAT");
			break;
		case 'j':
			if (CMode == MOVEHORIZONTAL) {
				move(LEFT);
			} else if (CMode == MOVEVERTICAL) {
				move(LEFT);
			} else if (CMode == ROTATEUPDOWN || CMode == ROTATELEFTRIGHT) {
				rotate(LEFT);
			}
			break;
		case 'k':
			if (CMode == MOVEHORIZONTAL) {
				move(BACK);
			} else if (CMode == MOVEVERTICAL) {
				move(DOWN);
			} else if (CMode == ROTATEUPDOWN) {
				rotate(DOWN);
			} else if (CMode == ROTATELEFTRIGHT) {
				move(BACK);
			}
			break;
		case 'l':
			if (CMode == MOVEHORIZONTAL) {
				move(RIGHT);
			} else if (CMode == MOVEVERTICAL) {
				move(RIGHT);
			} else if (CMode == ROTATEUPDOWN || CMode == ROTATELEFTRIGHT) {
				rotate(RIGHT);
			}
			break;
		case 'i':
			if (CMode == MOVEHORIZONTAL || CMode == ROTATELEFTRIGHT) {
				move(FORWARD);
			} else if (CMode == MOVEVERTICAL) {
				move(UP);
			} else if (CMode == ROTATEUPDOWN) {
				rotate(UP);
			}
			break;
		default:
			printf("\007");
			break;
		}
		for (i = 0; i < 1; i++)
			paint(c, COUNT);
	}
	setcolor(YELLOW);
	setbkcolor(BLACK);
	closegraph();
	printf("\nPress any key to end this program.");
	getch();
	if (NULL != (fp = fopen("GRAP_Y5.TXT", "wb"))) {
		fwrite((void*)&viewpoint, sizeof(point), 1, fp);
		fwrite((void*)&viewvect, sizeof(vect), 1, fp);
		fclose(fp);
	}
	return 0;
}

void paint(cube * cp, int count)
{
	int i, j;
	double t;
	static int sct, o_color;
	cube *cpt = NULL;
	vect *vpt[2] = { NULL, NULL };

	if (sct++ % 10 == 0)
		setcolor((o_color = (int) (rand() / 32767.0 * 15 + 1)));
	else
		setcolor(o_color);
	/*printf("function paint\n"); */
	for (i = 0; i < count; i++) {
		vpt[0] = vectmulc(-1, *point2vect(&viewpoint));
		vpt[1] = point2vect(&cp[i].p[0][0]);
		if ((t = vectdeg(*vectadd(*vpt[0], *vpt[1]),
				 viewvect)) > 80 * PI / 180) {
#ifdef DEBUG
			printf("Degree -> Over Flow!\n");
			printf("%f \n", t * 180 / PI);
#endif
			continue;
		}
		cpt = (cube *) convertcube(cp[i]);
		cpt = (cube *) convertcube2d(*cpt);
		paintcube(*cpt);
	}
#ifdef DEBUG
	/*vectprint(vpt1); */

	printf("\nviewpoint:\t");
	vectprint(vpt2);

	/*vectprint(vpt3);
	   vectprint(vpt4); */

	printf("viewvect:\t");
	vectprint(&viewvect);
	/*printf("%f %f %f\n",
	   vectlong(*vpt4),
	   vectlong(viewvect),
	   vectmul2(*vpt4, viewvect)); */
#endif
	if (!VIEW_P) {
#ifdef DEBUG
		printf("VIEW_P: %d \n", VIEW_P);
#endif
		goto End_Sub;
	}
#if !(VIEW_FOOT)
	delay(65535);
#endif
#if !(VIEW_FOOT)
	setcolor(getbkcolor());
	for (i = 0; i < count; i++) {
		vpt[0] = vectmulc(-1, *point2vect(&viewpoint));
		vpt[1] = point2vect(&cp[i].p[0][0]);
		if ((t = vectdeg(*vectadd(*vpt[0], *vpt[1]),
				 viewvect)) > 80 * PI / 180) {
			t = t * 1.0;
			continue;
		}
		cpt = (cube *) convertcube(cp[i]);
		cpt = (cube *) convertcube2d(*cpt);
		paintcube(*cpt);
	}
#endif
      End_Sub:;
}

void move(int dirp) {
	double t;
	vect ptx;

	switch (dirp) {
	case FORWARD:
#ifdef DEBUG
		printf("\t\t\tMove to Forward--------->\n");
#endif
		viewpoint =
		    *(vect2point(*vectadd(*point2vect(&viewpoint),
					  *vectmulc(5.0, viewvect)
						/**(&viewvect)*/
					  /*if here only use viewvect, it can be wrong */
				 )
		      )
		    );
		break;
	case BACK:
#ifdef DEBUG
		printf("\t\t\tMove to Back--------->\n");
#endif
		viewpoint = *vect2point(*vectadd(*point2vect(&viewpoint),
						 *vectmulc(-5.0, viewvect))
		    );
		break;
	case LEFT:
#ifdef DEBUG
		printf("\t\t\tMove to Left--------->\n");
#endif
		t = sqrt(pow(viewvect.d[0], 2) + pow(viewvect.d[1], 2));
		ptx.d[0] = viewvect.d[1] / t;
		ptx.d[1] = viewvect.d[0] / t;
		ptx.d[2] = 0;
		viewpoint = *vect2point(*vectadd(*point2vect(&viewpoint),
						 *vectmulc(-5.0, ptx)
					)
		    );
		break;
	case RIGHT:
#ifdef DEBUG
		printf("\t\t\tMove to Right--------->\n");
#endif
		t = sqrt(pow(viewvect.d[0], 2) + pow(viewvect.d[1], 2));
		ptx.d[0] = viewvect.d[1] / t;
		ptx.d[1] = viewvect.d[0] / t;
		ptx.d[2] = 0;
		viewpoint = *vect2point(*vectadd(*point2vect(&viewpoint),
						 *vectmulc(5.0, ptx))
		    );
		break;
	case UP:
#ifdef DEBUG
		printf("\t\t\tMove to Up--------->\n");
#endif
		t = sqrt(pow(viewvect.d[1], 2) + pow(viewvect.d[2], 2));
		ptx.d[0] = 0;
		ptx.d[1] = viewvect.d[2] / t;
		ptx.d[2] = viewvect.d[1] / t;
		viewpoint = *vect2point(*vectadd(*point2vect(&viewpoint),
						 *vectmulc(5.0, ptx))
		    );
		break;
	case DOWN:
#ifdef DEBUG
		printf("\t\t\tMove to Down--------->\n");
#endif
		t = sqrt(pow(viewvect.d[1], 2) + pow(viewvect.d[2], 2));
		ptx.d[0] = 0;
		ptx.d[1] = viewvect.d[2] / t;
		ptx.d[2] = viewvect.d[1] / t;
		viewpoint = *vect2point(*vectadd(*point2vect(&viewpoint),
						 *vectmulc(-5.0, ptx))
		    );
		break;
	}
}

void rotate(int dirp)
{
	double t = 5.0;
	vect ptx;

	/*gotoxy(0, 0);
	   vectprint(&viewvect); */
	switch (dirp) {
	case LEFT:
#ifdef DEBUG
		printf("\t\t\tRotate to Left--------->\n");
#endif
		ptx.d[0] = cos(PI * t / 180);
		ptx.d[1] = sin(PI * t / 180);
		ptx.d[2] = 0;
		viewvect = *vectrotate(viewvect, ptx, 2);
		break;
	case RIGHT:
#ifdef DEBUG
		printf("\t\t\tRotate to Right--------->\n");
#endif
		ptx.d[0] = cos(PI * t / 180);
		ptx.d[1] = sin(-PI * t / 180);
		ptx.d[2] = 0;
		viewvect = *vectrotate(viewvect, ptx, 2);
		break;
	case UP:
#ifdef DEBUG
		printf("\t\t\tRotate to Up--------->\n");
#endif
		ptx.d[0] = cos(PI * t / 180);
		ptx.d[1] = 0;
		ptx.d[2] = sin(PI * t / 180);
		viewvect = *vectrotate(viewvect, ptx, 1);
		break;
	case DOWN:
#ifdef DEBUG
		printf("\t\t\tRotate to Down--------->\n");
#endif
		ptx.d[0] = cos(PI * t / 180);
		ptx.d[1] = 0;
		ptx.d[2] = sin(-PI * t / 180);
		viewvect = *vectrotate(viewvect, ptx, 1);
		break;
	}

	/*vectprint(&viewvect); */
}

int savepic(char *fname)
{
	FILE *fp;
	char far *ptr;
	unsigned int k, i;

	if (NULL == (fp = fopen(fname, "wb")))
		return 1;
	for (k = 0; k < 4; k++) {
		outportb(0x3CE, 4);
		outportb(0x3CF, k);
		ptr = (char far *) 0xA0000000L;
		for (i = 0; i < 38400; i++, ptr++)
			putc(*ptr, fp);
	}
	fclose(fp);
	return 0;
}

int showpic(char *fname)
{
	FILE *fp;
	char far *ptr;
	unsigned int k, i;

	if (NULL == (fp = fopen(fname, "rb")))
		return 1;
	for (k = 0; k < 4; k++) {
		outportb(0x3C4, 2);
		outportb(0x3C5, 0x0001 << k);
		ptr = (char far *) 0xA0000000L;
		for (i = 0; i < 38400; i++, ptr++)
			*ptr = getc(fp);
	}
	fclose(fp);
	return 0;

}
