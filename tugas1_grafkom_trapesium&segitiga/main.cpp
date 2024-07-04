
#include <GL/glut.h>
#include <stdlib.h>

int a=0;
int b=0;
int c=0;
int d=0;
int w, x;

//membuat bentuk trapesium
void Quads(){
    glBegin(GL_QUADS); //membuat kotak sebagai base dari trapesium
    glColor3f(1,1,2);
    glVertex2f(100,100);
    glColor3f(1,3,4);
    glVertex2f(200,100);
    glColor3f(1,1,0);
    glVertex2f(200,200);
    glColor3f(1,1,0);
    glVertex2f(100,200);
    glEnd();
}
void Triangels(){
    glBegin(GL_TRIANGLES); //membuat bentuk segitiga
    glVertex2i(-200,-100);
    glVertex2i(-100,-100);
    glColor3f(0.2,1,2);
    glVertex2i(-150,-100);
    glEnd();
}
void renderscene(){
     glClear(GL_COLOR_BUFFER_BIT);
     glPushMatrix();
     glTranslatef(b,c,0);
     Quads();
     glPopMatrix();
     glPushMatrix();
     glTranslatef(a,d,0);
     Triangels();
     glPopMatrix();

     glFlush();
}
void quadskey (unsigned char key, int x, int y){
    if (key=='a'){b+=-10;c+=0;}
        else if (key=='d'){b+=10;c+=0;}
        else if (key=='w'){b+=0;c+=10;}
        else if (key=='s'){b+=0;c=-10;}
        }

void trianglekey (int key, int x, int y){
    switch(key){
    case GLUT_KEY_LEFT:a+=-10;d+=0;break;
    case GLUT_KEY_RIGHT:a+=10;d+=0;break;
    case GLUT_KEY_UP:a+=0;d+=10;break;
    case GLUT_KEY_DOWN:a+=0;d+=-10;break;
    }
}

void update(int value){
    glutPostRedisplay();
    glutTimerFunc(50,update,0);
}
int main (int argc, char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("KELOMPOK 2_SEGITIGA & TRAPESIUM");
    gluOrtho2D(-320.,-320.,-320.,-320.);
    glutDisplayFunc(renderscene);
    glutTimerFunc(1,update,0);
    glutKeyboardFunc(quadskey);
    glutSpecialFunc(trianglekey);
    glutMainLoop();

    glFlush();

    return 0;
}
