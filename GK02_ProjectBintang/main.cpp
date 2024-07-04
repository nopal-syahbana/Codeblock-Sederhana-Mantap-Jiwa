#include "stdlib.h"
#include "gl/glut.h"
#include "math.h"
const double PI = 3.141592653589793;
int i;
void back(){
glBegin(GL_QUADS);
glColor3f(0,0,0);
 glVertex2d (-150,150);
 glVertex2d(150,150);
 glVertex2d(150,-150);
 glVertex2d (-150,-150);
glEnd();
}
void lingkaran(int radius, int jumlah_titik, int x_tengah, int y_tengah) {
glBegin(GL_POLYGON);
{for (i=0;i<=360;i++){
 float sudut=i*(2*PI/jumlah_titik);
 float x=x_tengah+radius*cos(sudut);
 float y=y_tengah+radius*sin(sudut);
 glVertex2f(x,y);
}
}
glEnd();
}
void Draw() {
 glClear(GL_COLOR_BUFFER_BIT);
 back();
 glColor3f(1.0, 0.0, 0.0);
 lingkaran(30,70,0,0);
 glColor3f(0.0, 1.0, 0.0);
 lingkaran(20,70,40,40);
 glColor3f(1.0, 1.0, 1.0);
 lingkaran(13,70,70,70);
 glColor3f(1.0, 0.0, 1.0);
 lingkaran(8,70,90,90);
 glColor3f(0.0, 0.0, 1.0);
 lingkaran(40,70,-60,-60);
 glFlush();
}
int main(int argc, char **argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(300, 300);
 glutInitWindowPosition(200, 200);
 glutCreateWindow("MuhAnasLingkaran");
 gluOrtho2D(-150,150,-150,150);
 glutDisplayFunc(Draw);
 glutMainLoop();
}
