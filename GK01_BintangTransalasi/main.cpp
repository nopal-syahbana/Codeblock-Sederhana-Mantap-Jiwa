#include <stdlib.h>
#include <GL/glut.h>
#include <windows.h>

//membuat method fungsi untuk bintang dari GL_POLYGON
void drawQuad(){

 glBegin(GL_POLYGON);
  glVertex2f(77.,70.);
  glVertex2f (80.,146.);
  glVertex2f(99.,90.);
  glVertex2f(157.,90.);
  glVertex2f (110.,55.);
  glVertex2f (128.,1.);
  glVertex2f (80.,34.);
  glVertex2f (32.,1.);
  glVertex2f (54.,55.);
  glVertex2f (3.,90.);
  glVertex2f (63.,90.);
  glVertex2f (80.,146.);
 glEnd();
 glFlush();
}

//kemudian membuat renderscene dengan menggunakan bintang yang sudah dibuat di method awal
void renderScene(void){

//mereset gambar dalam renderscene
 glClear(GL_COLOR_BUFFER_BIT);

 //membuat bintang pertama hingga bintang ke-11 dengan warna ungu dengan rotasi dan skala serta
 //menetapkan lokasi bintang sesuai gar
  glPushMatrix();
 glTranslatef(1040,1000,0);
  glRotatef(45,0,0,1);
  glScalef(0.5,0.5,0);
 glColor3f(1,0,1);//Ungu no.1
 drawQuad();
 glPopMatrix();

  glPushMatrix();
 glTranslatef(950,880,0);
 glRotatef(45,0,0,1);
 glScalef(1.0,1.0,0);
 glColor3f(0,1,0);//hijau no.1
 drawQuad();
 glPopMatrix();

  glPushMatrix();
 glTranslatef(820,720,0);
 glRotatef(45,0,0,1);
 glScalef(1.5,1.5,0);
 glColor3f(0,1,1);//cyan no.2
 drawQuad();
 glPopMatrix();

 glPushMatrix();
 glTranslatef(650,550,0);
 glRotatef(45,0,0,1);
  glScalef(2.0,2.0,0);
 glColor3f(0,0,1);//biru no.3
 drawQuad();
 glPopMatrix();

  glPushMatrix();
 glTranslatef(400,330,0);
 glRotatef(45,0,0,1);
 glScalef(2.5,2.5,0);
 glColor3f(1,1,0);//kuning no.4
 drawQuad();
 glPopMatrix();


 glPushMatrix();
  glTranslatef(100,30,0);
 glRotatef(45,0,0,1);
  glScalef(3.0,3.0,0);
 glColor3f(1,0,0);//merah tengah no.5
 drawQuad();
 glPopMatrix();

  glPushMatrix();
 glTranslatef(-150,-220,0);
 glRotatef(45,0,0,1);
 glScalef(2.5,2.5,0);
 glColor3f(1,1,0);//Kuning no.6
 drawQuad();
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-350,-390,0);
 glRotatef(45,0,0,1);
 glScalef(2.0,2.0,0);
 glColor3f(0,0,1);//biru no.7
 drawQuad();
 glPopMatrix();

  glPushMatrix();
 glTranslatef(-470,-510,0);
 glScalef(1.5,1.5,0);
 glRotatef(45,0,0,1);
 glColor3f(0,1,1);//cyan no.9
 drawQuad();
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-550,-620,0);
  glRotatef(45,0,0,1);
  glScalef(1.0,1.0,0);
 glColor3f(0,1,0);//hijau no.10
 drawQuad();
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-610,-660,0);
  glRotatef(45,0,0,1);
  glScalef(0.5,0.5,0);
 glColor3f(1,0,1);//Ungu no.11
 drawQuad();
 glPopMatrix();

 glFlush();
}

//kemudian memanggil renderscene sekaligus mmebuat window untuk tampilan
 int main(int argc,char **argv){
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
 glutInitWindowPosition(200,200);
 glutInitWindowSize(480,480);
 glClearColor(1,1,1,0);
 glutCreateWindow("Kelompok02_""Bintang Translasi""_Grafkom Tugas 02");
 gluOrtho2D(-1500., 1500.,-1500.,1500.);
 glutDisplayFunc(renderScene);
 glutMainLoop();
}
