#include <windows.h>
#include <gl/Gl.h>
#include <gl/glut.h>
//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
 void myInt(void)
 {
    glClearColor(1.0,1.0,1.0,0.0);      	 // membuat latar belakang putih
    glColor3f(0.0f, 0.0f, 0.f);              // membuat warna gambar hitam
 	glPointSize(5.0);		       	         // ukuran titik 5 x 5 pixel
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glLineWidth(4.0f);
	gluOrtho2D(0.0, 500.0, 0.0, 300.0);
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

       	// hapus layar
	glColor3f(0.0f, 0.5f, 1.0f); //biru muda
    glBegin(GL_POLYGON);//tembok depan
		glVertex2i(100, 100);
		glVertex2i(100, 200);
		glVertex2i(200, 200);
		glVertex2i(200, 100);
	glEnd();
    glBegin(GL_POLYGON);//tembok gedung
		glVertex2i(200, 100);
		glVertex2i(200, 200);
		glVertex2i(400, 200);
		glVertex2i(400, 100);
	glEnd();

	glColor3f(2.0f,0.5f,1.0f);
    glBegin(GL_POLYGON);//pintu
		glVertex2i(130, 100);
		glVertex2i(130, 150);
		glVertex2i(160, 150);
		glVertex2i(160, 100);
	glEnd();
	glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_POINTS);//pintu
		glVertex2i(135, 130);

	glEnd();

	glColor3f(0.5f,0.0f,0.0f);
    glBegin(GL_POLYGON);
		glVertex2i(290, 330);         		// Cerobong
		glVertex2i(290, 250);
		glVertex2i(310, 250);
		glVertex2i(310, 330);
	glEnd();

	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_LINE_LOOP);
    	glVertex2i(290, 250);         		// Garis cerobong
		glVertex2i(290, 300);
		glVertex2i(310, 300);
		glVertex2i(310, 250);
	glEnd();

	glColor3f(0.0f,0.5f,0.5f);
    glBegin(GL_POLYGON);
		glVertex2i(100, 200); //atap depan
		glVertex2i(150, 250);
		glVertex2i(200, 200);
	glEnd();
	glColor3f(0.5f,0.5f,0.5f);
    glBegin(GL_POLYGON);       //atap gedung

        glVertex2i(200, 200);
		glVertex2i(150, 250);

		glVertex2i(350, 250);
		glVertex2i(400, 200);
	glEnd();

	glColor3f(0.0f,1.0f,0.0f);
    glBegin(GL_POLYGON);
		glVertex2i(275, 125);         		// Jendela kiri bawah
		glVertex2i(275, 150);
		glVertex2i(300, 150);
		glVertex2i(300, 125);
	glEnd();

	glColor3f(1.0f,0.5f,0.0f);
    glBegin(GL_POLYGON);
		glVertex2i(275, 150);         		// Jendela kiri atas
		glVertex2i(275, 175);
		glVertex2i(300, 175);
		glVertex2i(300, 150);
	glEnd();

	glColor3f(1.0f,1.0f,0.0f);
    glBegin(GL_POLYGON);
		glVertex2i(300, 125);         		// Jendela kanan bawah
		glVertex2i(300, 150);
		glVertex2i(325, 150);
		glVertex2i(325, 125);
	glEnd();

	glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
		glVertex2i(300, 150);         		// Jendela kanan atas
		glVertex2i(300, 175);
		glVertex2i(325, 175);
		glVertex2i(325, 150);
	glEnd();
    //atas polygon bawah garis

        glColor3f(0.0f,0.0f,.0f);
    glBegin(GL_LINE_LOOP);
		glVertex2i(100, 100);         		// Garis tembok depan
		glVertex2i(100, 200);
		glVertex2i(200, 200);
		glVertex2i(200, 100);
	glEnd();
    glBegin(GL_LINE_LOOP);
		glVertex2i(130, 100);         		// garis pintu
		glVertex2i(130, 150);
		glVertex2i(160, 150);
		glVertex2i(160, 100);
	glEnd();

    glBegin(GL_LINE_LOOP);
		glVertex2i(200, 100);         		// garis tembok belakang
		glVertex2i(200, 200);
		glVertex2i(400, 200);
		glVertex2i(400, 100);
	glEnd();


    glBegin(GL_LINE_LOOP);
		glVertex2i(100, 200);         		// garis Atap depan
		glVertex2i(150, 250);
		glVertex2i(200, 200);
	glEnd();

    glBegin(GL_LINE_LOOP);
		glVertex2i(200, 200);   		    // garis Atap Belakang
		glVertex2i(150, 250);
		glVertex2i(350, 250);
		glVertex2i(400, 200);
	glEnd();
    //garis jendela di bawah
    glColor3f(0.0f,0.0f,0.0f);

    glBegin(GL_LINE_LOOP);
		glVertex2i(275, 125);         		// Jendela kiri bawah
		glVertex2i(275, 150);
		glVertex2i(300, 150);
		glVertex2i(300, 125);
	glEnd();
	glBegin(GL_LINE_LOOP);
    	glVertex2i(275, 150);         		// Jendela kiri atas
		glVertex2i(275, 175);
		glVertex2i(300, 175);
		glVertex2i(300, 150);
	glEnd();
    glBegin(GL_LINE_LOOP);
    	glVertex2i(300, 125);         		// Jendela kanan bawah
		glVertex2i(300, 150);
		glVertex2i(325, 150);
		glVertex2i(325, 125);
	glEnd();
    glBegin(GL_LINE_LOOP);
    	glVertex2i(300, 150);         		// Jendela kanan atas
		glVertex2i(300, 175);
		glVertex2i(325, 175);
		glVertex2i(325, 150);
	glEnd();
	glFlush();		                    	// mengirim semua output ke layar
}

//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
INT main(int argc, char** argv)
{
	glutInit(&argc, argv);          		     // inisialisasi  toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set modus display
	glutInitWindowSize(450,300);     	      	 // set ukuran window
	glutInitWindowPosition(100, 150); 		    // set posisi window di layar
    //acuan sudut kiri-atas
	glutCreateWindow("my first attempt"); 	// buka screen window
	glutDisplayFunc(myDisplay);     		// registrasi fungsi menggambr
	myInt();
	glutMainLoop(); 		     		    // berulang terus-menerus
}
