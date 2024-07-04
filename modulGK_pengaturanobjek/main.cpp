#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>



------- MEMBUAT TITIK & MEMPERBESAR UKURANNYA -----------------


   //glPointSize(5); erorr
void drawPoint (void){
    glPointSize(5);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

   //glPointSize(5); running, tapi point tidak berubah

    glVertex2i(0,0);
    glVertex2i(50,50);
    glVertex2i(100,100);
    glVertex2i(150,150);
    glVertex2i(200,200);
    glVertex2i(-200,-200);
    glVertex2i(-150,-150);
    glVertex2i(-100,-100);
    glVertex2i(-50,-50);
    glEnd();

    //glPointSize(5); running, tapi point tidak berubah

glFlush();
}

int main (int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("Pemrograman Grafis GLUT");
    gluOrtho2D(-320,320,-240,240);
    glutDisplayFunc(drawPoint);
    glutMainLoop();
}


-------------------------------------------------------------------------------------------

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>


------- MEMBUAT GARIS & MEMBERIKAN KETEBALANNYA -----------------

//glLineWidth(10); erorr
   void drawLine (void){

	glLineWidth(5);

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);

	glVertex2d(0.,0.);
	glVertex2d(150.,150.);
	glVertex2d(200.,200.);
	glVertex2d(-100.,-100.);
	glVertex2d(-150.,-150.);
	glEnd();


	//glLineWidth(10); tidak ada perubahan


	glFlush();
}

int main (int argc, char **argv){
	glutInit(&argc, argv);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("Pemrograman Grafis GLUT");
	gluOrtho2D(-320,320,-240,240);
	glutDisplayFunc(drawLine);
	glutMainLoop();
}



------------------------------------------------------------------------------------------------

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>



-------------- MEMBUAT PERSEGI TIDAK TERTUTUP -------------------

	void drawPoliline (void){
	    //glLineWidth(5);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
		glVertex2d(0.,0.);
		glVertex2d(140.,0.);
		glVertex2d(140.0,140.0);
		glVertex2d(0.0,140.);
	glEnd();
	glFlush();
}

int main (int argc, char **argv){
	glutInit(&argc, argv);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("Pemrograman Grafis GLUT");
	gluOrtho2D(-320,320,-240,240);
	glutDisplayFunc(drawPoliline);
	glutMainLoop();
}


---------------------------------------------------------------------------------------------------

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

-------------- MEMBUAT PERSEGI TERTUTUP -------------------

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void drawPoligon (void){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glVertex2d(0.0,0.0);
	glVertex2d(0.0,150.0);
	glVertex2d(150.,150.0);
	glVertex2d(150.0,0.);
	glEnd();
	glFlush();
}

int main (int argc, char **argv){
	glutInit(&argc, argv);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("Pemrograman Grafis GLUT");
	gluOrtho2D(-320,320,-240,240);
	glutDisplayFunc(drawPoligon);
	glutMainLoop();
}


-------------------------------------------------------------------------------------------------
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>


 -------- OBJEK 2 DIMENSI (PERSEGI) -------------

void segiempat(int x, int y, int w, int h){
	glBegin(GL_QUADS);
	glVertex2i(x,y); // 1       (-200,200)   (100,200)   (0,0)
	glVertex2i(w+x,y); // 2     (-100,200)   (250,200)   (50,0)
	glVertex2i(w+x,y-h); // 3   (-100,100)   (250,50)    (50,-50)
	glVertex2i(x,y-h); // 4     (-200,100)   (100,50)    (0,-50)
	glEnd();
}

void renderScene(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1,0,0);
	segiempat(-200,200,100,100);
	glColor3d(0,1,0);
	segiempat(100,200,150,150);
	glColor3d(0,0,1);
	segiempat(0,0,50,50);
	glFlush();
}

int main(int argc, char  **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,640);
	glutCreateWindow("Kubus");
	glClearColor(1,1,1,0);
	gluOrtho2D(-320,320,-320,320);
	glutDisplayFunc(renderScene);
	glutMainLoop();
}

--------------------------------------------------------------------------------------------------------


#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

 -------- OBJEK 2 DIMENSI (TRAPESIUM) -------------

void trapesium(int x, int y, int w1,int w2, int h)
{
	glBegin(GL_QUADS);
	glVertex2i(x,y); // 1 (-200,200)        (100,200)
	glVertex2i(w1+x,y); // 2 (-150, 200)    (200,200)
	glVertex2i(w1+x,y-h); // 3 (-150,150)   (200,150)
	glVertex2i(x,y-h); // 4 (-200,150)      (100,150)
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(w1+x,y-h); //1 = 3 (-150.150)        (200,150)
	glVertex2i(w1+x+(w2-w1),y-h); // (-100,150      (250,150)
	glVertex2i(w1+x,y); // 3 = 2 (-150,200)         (200,150)
	glEnd();
}


void renderScene(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1,0,0);
	trapesium(-200,200,50,100,50);
	glColor3d(0,1,0);
	trapesium(100,200,100,150,50);
	glColor3d(0,0,1);
	trapesium(0,0,50,100,20);
	glFlush();
}

 int main(int argc, char  **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,640);
	glutCreateWindow("Trapesium");
	glClearColor(1,1,1,0);
	gluOrtho2D(-320,320,-320,320);
	glutDisplayFunc(renderScene);
	glutMainLoop();
}

---------------------------------------------------------------------------------------------------------
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

******************TRANSLASI*********************


void drawQuad(){
glBegin(GL_QUADS);
	glVertex2f(0.,0.);
	glVertex2f(0.,10.);
	glVertex2f(20.,10.);
	glVertex2f(20.,0.);
	glEnd();
}


void renderScene(){
	glClear(GL_COLOR_BUFFER_BIT);
	glScalef(10.,30.,10.);
	glColor3d(1,0,0);
	drawQuad();
	glFlush();
}

int main(int argc, char  **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(480,480);
	glutCreateWindow("Translasi");
	glClearColor(1,1,1,0);
	gluOrtho2D(-320,320,-320,320);
	glutDisplayFunc(renderScene);
	glutMainLoop();
}

-------------------------------------------------------------------------------------------------------------------------------------------------

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>


***********************ROTASI********************

void drawQuad(){
	glBegin(GL_QUADS);
	glVertex2f(0.,0.);
	glVertex2f(0.,100.);
	glVertex2f(200.,100.);
	glVertex2f(200.,0.);
	glEnd();
}

void renderScene(){
	glClear(GL_COLOR_BUFFER_BIT);
	glRotatef(45,0,0,1);
	glColor3d(1,0,0);
	drawQuad();
	glFlush();
}

int main(int argc, char  **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(480,480);
	glutCreateWindow("Translasi");
	glClearColor(1,1,1,0);
	gluOrtho2D(-320,320,-320,320);
	glutDisplayFunc(renderScene);
	glutMainLoop();
}


--------------------------------------------------------------------------------------------------------------------------
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>



*************SKALA**********************************

void drawQuad(){
glBegin(GL_QUADS);
	glVertex2f(0.,0.);
	glVertex2f(0.,10.);
	glVertex2f(20.,10.);
	glVertex2f(20.,0.);
	glEnd();
}


void renderScene(){
	glClear(GL_COLOR_BUFFER_BIT);
	glScalef(10.,30.,10.);
	glColor3d(1,0,0);
	drawQuad();
	glFlush();
}

int main(int argc, char  **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(480,480);
	glutCreateWindow("Translasi");
	glClearColor(1,1,1,0);
	gluOrtho2D(-320,320,-320,320);
	glutDisplayFunc(renderScene);
	glutMainLoop();
}

------------------------------------------------------------------------------------------------------------------------------------------------------
