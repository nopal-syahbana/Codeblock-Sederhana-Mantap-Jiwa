#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>


//kita buat deklarasi untuk fungsi yang akan diguna
void display();
void init();
void reshape(int,int);

//kemudian buat program utama untuk menjalankan kode
int main (int argc, char** argv){
//kode untuk inisialisasi
glutInit (&argc, argv);
glutInitDisplayMode(GLUT_RGB);
glutInitWindowPosition(200,100);
glutInitWindowSize(500,500);
glutCreateWindow("RUMAH 2 DIMENSI");

glutDisplayFunc(display);
glutReshapeFunc(reshape);

init();
glutMainLoop();
}
    //kita beri warna pada background dengan warna putih
void init(){
    glClearColor(1.0,1.0,1.0,1.0);
}
void display(){
    //kita beri fungsi untuk reset
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
//kemudaian disini kita akan mulai menggambar objek
    glPointSize(10);

//pertama kita buat jalan dengan menggunakan persegi panjang
    glBegin(GL_POLYGON);
    glColor3f(0.28, 0.28, 0.28);
    glVertex2f(-10.0, -3.0);
    glVertex2f(-10.0, -7.0);
    glVertex2f(10.0, -7.0);
    glVertex2f(10.0, -3.0);
    glEnd();
//kemudian buat garis jalan dengan line/garis
     glLineWidth(5);
     glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-9.0, -5.0);
    glVertex2f(-6.5, -5.0);
    glVertex2f(-4.0, -5.0);
    glVertex2f(-1.5, -5.0);
    glVertex2f(1.0, -5.0);
    glVertex2f(3.5, -5.0);
    glVertex2f(6.5, -5.0);
    glVertex2f(9.0, -5.0);

    glEnd();
//kemudian atap pertama dengan menggunakan seegitiga
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(0.0, 5.0);
    glVertex2f(-3.0, 2.0);
    glVertex2f(3.0, 2.0);
    glEnd();
//atap kedua menggunakan jajar genjang
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.0, 5.0);
    glVertex2f(3.0, 2.0);
    glVertex2f(8.5, 2.0);
    glVertex2f(5.5, 5.0);
    glEnd();

//lalu buat 2 tembok
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.0, 0.0);
    glVertex2f(-3.0, 2.0);
    glVertex2f(-3.0, -3.0);
    glVertex2f(3.0, -3.0);
    glVertex2f(3.0, 2.0);

    glEnd();
//tembok kedua
     glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(3.0, 2.0);
    glVertex2f(3.0, -3.0);
    glVertex2f(8.5, -3.0);
    glVertex2f(8.5, 2.0);
    glEnd();

//tambahkan pintu dengan persegi panjang
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.75);
    glVertex2f(1.0, 0.5);
    glVertex2f(1.0, -3.0);
    glVertex2f(2.5, -3.0);
    glVertex2f(2.5, 0.5);
    glEnd();

//beri gagang pintu dengan point/titik
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2d(1.2,-1.3);
    glEnd();

//tambahkan jendela
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2.5, 0.5);
    glVertex2f(-2.5, -2.0);
    glVertex2f(0.0, -2.0);
    glVertex2f(0.0, 0.5);
    glEnd();
//garis jendela
     glLineWidth(4);
     glBegin(GL_LINES);
    glColor3f(0.5, 0.0, 0.0);
    glVertex2f(-1.2, 0.5);
    glVertex2f(-1.2, -2.0);
   glVertex2f(-2.5, -0.7);
    glVertex2f(0.0, -0.7);

   glEnd();

//gagang pintu
    glBegin(GL_POINTS);
     glColor3f(1.0, 1.0, 1.0);
    glVertex2d(1.2,-1.3);
    glEnd();

    glFlush();

}
void reshape(int w, int h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}
