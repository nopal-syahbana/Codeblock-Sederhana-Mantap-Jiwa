
#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

//kita buat deklarasi untuk fungsi yang akan digunakan
void display();
void init();
void reshape(int,int);

//kemudian buat program utama untuk menjalankan kode
int main (int argc, char** argv){
//kode untuk inisialisasi
glutInit (&argc, argv);
glutInitDisplayMode(GLUT_RGB);
glutInitWindowPosition(100,100);
glutInitWindowSize(1600,900);
glutCreateWindow("TUGAS1_GRAKOM_KELOMPOK2 : TRAPESIUM");
glutDisplayFunc(display);
glutReshapeFunc(reshape);

init();
glutMainLoop();}

void init(){
    //kita beri warna pada background dengan warna putih
    glClearColor(1.0,1.0,1.0,1.0);
}
void display(){
    //kita beri fungsi untuk reset
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
//kemudaian disini kita akan mulai menggambar objek
    glPointSize(10);
//kita akan menambahkan objek persegi namun dengan merubah kedua titik bawah sehingga menjadi jajar genjang
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-6.0, -6.0);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(6.0, -6.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(4.0,3.0);
    glColor3f(0.0, 0.0, 0.1);
    glVertex2f(-4.0, 3.0);

    glEnd();
    glFlush();

}
//kemudian kita tambahkan fungsi reshape
void reshape(int w, int h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

