#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

//kita buat deklarasi untuk fungsi yang akan digunakan
void myInit(void)
 {
     // membuat background menjadi putih
    glClearColor(1.0,1.0,1.0,0.0);
    // membuat warna gambar menjadi hitam
    glColor3f(0.0f, 0.0f, 0.f);
    // disini kita berikan fungsi untuk membuat ukuran titik menjadi 4x lebih besar
 	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glLineWidth(4.0f);
	gluOrtho2D(0.0, 500.0, 0.0, 300.0);
}
//kemudian kita membuat beberapa objek dari susunan rumah menggunakan polygon
//jangan lupa kita display

void Rumahdisplay (void)
{
    //fungsi untuk mengosongkan layar
	glClear(GL_COLOR_BUFFER_BIT);

	//membuat tembok bagian depan
	glColor3f(1.f,0.0f,0.0f); //merah
    glBegin(GL_POLYGON);
		glVertex2i(100, 100);
		glVertex2i(100, 200);
		glVertex2i(200, 200);
		glVertex2i(200, 100);
	glEnd();
	//membuat tembok bagian belakang
	glColor3f(0.5f,0.0f,0.0f); //merah tua
    glBegin(GL_POLYGON);
		glVertex2i(200, 100);
		glVertex2i(200, 200);
		glVertex2i(400, 200);
		glVertex2i(400, 100);
	glEnd();
    //membuat bentuk pintu
	glColor3f(1.0f,0.6f,0.0f); //warna coklat
    glBegin(GL_POLYGON);
		glVertex2i(130, 100);
		glVertex2i(130, 150);
		glVertex2i(160, 150);
		glVertex2i(160, 100);
	glEnd();
	//membuat gagang pintu dengan points
	glColor3f(0.0f,0.0f,0.0f); //Warna hitam
    glBegin(GL_POINTS);
		glVertex2i(135, 130);

	glEnd();
    //membuat atap bagian depan
	glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_POLYGON);
		glVertex2i(100, 200); //biru
		glVertex2i(150, 250);
		glVertex2i(200, 200);
	glEnd();
	//membuat atap bagian depan
	glColor3f(0.0f,0.0f,0.5f);//biru tua
    glBegin(GL_POLYGON);
        glVertex2i(200, 200);
		glVertex2i(150, 250);
		glVertex2i(350, 250);
		glVertex2i(400, 200);
	glEnd();
    //membuat Jendela dengan 4 warna
	glColor3f(0.0f,0.9f,0.5f);
    glBegin(GL_POLYGON);
		glVertex2i(275, 125);
		glVertex2i(275, 150);
		glVertex2i(300, 150);
		glVertex2i(300, 125);
	glEnd();

	glColor3f(0.2f,0.7f,0.5f);
    glBegin(GL_POLYGON);
		glVertex2i(275, 150);
		glVertex2i(275, 175);
		glVertex2i(300, 175);
		glVertex2i(300, 150);
	glEnd();

	glColor3f(0.0f,0.5f,1.0f);
    glBegin(GL_POLYGON);
		glVertex2i(300, 125);
		glVertex2i(300, 150);
		glVertex2i(325, 150);
		glVertex2i(325, 125);
	glEnd();

	glColor3f(0.0f,0.2f,0.5f);
    glBegin(GL_POLYGON);
		glVertex2i(300, 150);
		glVertex2i(300, 175);
		glVertex2i(325, 175);
		glVertex2i(325, 150);
	glEnd();

	// membuat Cerobong
	glColor3f(1.0f,0.6f,0.0f); // Warna Coklat
    glBegin(GL_POLYGON);
		glVertex2i(290, 330);
		glVertex2i(290, 250);
		glVertex2i(310, 250);
		glVertex2i(310, 330);
	glEnd();
    // Membuat Garis cerobong
	glColor3f(0.0f,0.0f,0.0f); // warna Hitam
	glBegin(GL_LINE_LOOP);
    	glVertex2i(290, 250);
		glVertex2i(290, 300);
		glVertex2i(310, 300);
		glVertex2i(310, 250);
	glEnd();

    //Membuat Garis untuk melapisi bentuk
    // Garis tembok depan
        glColor3f(0.0f,0.0f,.0f);
    glBegin(GL_LINE_LOOP);
		glVertex2i(100, 100);
		glVertex2i(100, 200);
		glVertex2i(200, 200);
		glVertex2i(200, 100);
	glEnd();
	// garis pintu
    glBegin(GL_LINE_LOOP);
		glVertex2i(130, 100);
		glVertex2i(130, 150);
		glVertex2i(160, 150);
		glVertex2i(160, 100);
	glEnd();
    // garis tembok belakang
    glBegin(GL_LINE_LOOP);
		glVertex2i(200, 100);
		glVertex2i(200, 200);
		glVertex2i(400, 200);
		glVertex2i(400, 100);
	glEnd();
    // garis Atap depan
    glBegin(GL_LINE_LOOP);
		glVertex2i(100, 200);
		glVertex2i(150, 250);
		glVertex2i(200, 200);
	glEnd();
    // garis Atap Belakang
    glBegin(GL_LINE_LOOP);
		glVertex2i(200, 200);
		glVertex2i(150, 250);
		glVertex2i(350, 250);
		glVertex2i(400, 200);
	glEnd();
    //Beerikutnya garis jendela di bawah
    // Jendela kiri bawah
     glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINE_LOOP);
		glVertex2i(275, 125);
		glVertex2i(275, 150);
		glVertex2i(300, 150);
		glVertex2i(300, 125);
	glEnd();
	// Jendela kiri atas
	glBegin(GL_LINE_LOOP);
    	glVertex2i(275, 150);
		glVertex2i(275, 175);
		glVertex2i(300, 175);
		glVertex2i(300, 150);
	glEnd();
	// Jendela kanan bawah
    glBegin(GL_LINE_LOOP);
    	glVertex2i(300, 125);
		glVertex2i(300, 150);
		glVertex2i(325, 150);
		glVertex2i(325, 125);
	glEnd();
	// Jendela kanan atas
    glBegin(GL_LINE_LOOP);
    	glVertex2i(300, 150);
		glVertex2i(300, 175);
		glVertex2i(325, 175);
		glVertex2i(325, 150);
	glEnd();
    // kemudian dengan menggunakan flush kita mengirim seluruh objek ke layar
	glFlush();
}

//kemudian buat program utama untuk menjalankan kode
INT main(int argc, char** argv)
{
    //kode untuk inisialisasi
	glutInit(&argc, argv);
	//kode display
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// memberi ukuran window untuk gambar
	glutInitWindowSize(650,500);
	// menempatkan objek kedalam jendela
	glutInitWindowPosition(100, 100);
    // membuat judul Window
	glutCreateWindow(" CPK1_GRAFKOM_Ahmad Naufal Syahbana ");
    // registrasi fungsi menggambar yakni rumah display
	glutDisplayFunc(Rumahdisplay);
	myInit();
	glutMainLoop();
}

