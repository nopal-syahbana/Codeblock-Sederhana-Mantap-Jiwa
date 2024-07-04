/**
  Jam Digital Tapi Analog

  @author Kelompok 2

*/

#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>
#include <time.h>
#include <sys/timeb.h>



const float clockR    = 80.0f,
            clockVol  = 100.0f,

            angle1min = M_PI / 30.0f,

            minStart  = 0.9f,
            minEnd    = 1.0f,

            stepStart = 0.8f,
            stepEnd   = 1.0f;

//Variabel yang digunakan untuk menghitung jam
float jarumjam = 0,
      jarummenit  = 0,
      jarumdetik  = 0;



void newLine(float rStart, float rEnd, float angle){
  float c = cos(angle), s = sin(angle);
  glVertex2f( clockR*rStart*c, clockR*rStart*s);
  glVertex2f( clockR*rEnd*c, clockR*rEnd*s);
}


//Membuat Method Renderscene untuk menggambar bentuk jam analog
void RenderScene(void){
  int i;

  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0f, 0.0f, 0.0f);
  glLineWidth(2.0f);
  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_POINT_SMOOTH);
  glEnable(GL_POLYGON_SMOOTH);

  glBegin(GL_LINES);
    for(i=0; i<60; i++){
//Menit Normal
      if(i%5){
        if(i%5 == 1)
          glColor3f(1.0f, 1.0f, 1.0f);
        newLine(minStart, minEnd, i*angle1min);
      }else{
        glColor3f(1.0f, 0.0f, 0.0f);
        newLine(stepStart, stepEnd, i*angle1min);
      }
    }
  glEnd();
//Menggambar Jarum Jam
  glLineWidth(3.0f);
  glBegin(GL_LINES);
    newLine(0.0f, 0.5f, -jarumjam+M_PI/2);
    newLine(0.0f, 0.8f, -jarummenit+M_PI/2);
  glEnd();

  glLineWidth(1.0f);
  glColor3f(0.0f, 1.0f, 0.0f);
  glBegin(GL_LINES);
    newLine(0.0f, 0.8f, -jarumdetik+M_PI/2);
  glEnd();

  glutSwapBuffers();
}
//Memberikan Warna pada window
void SetupRC(void){
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

//Method agar jam menyesuaikan sesua rasio
void ChangeSize(GLsizei w, GLsizei h){
  GLfloat aspectRatio;

  // Mencegah hasil agar tidak 0
  if(h == 0)
    h = 1;

  // Menyesuaikan dengan dimensi window
  glViewport(0, 0, w, h);

  // Reset koordinat
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // fungsi utama
  aspectRatio = (GLfloat)w / (GLfloat)h;
  if (w <= h)
    glOrtho (-clockVol, clockVol, -clockVol / aspectRatio, clockVol / aspectRatio, 1.0, -1.0);
  else
    glOrtho (-clockVol * aspectRatio, clockVol * aspectRatio, -clockVol, clockVol, 1.0, -1.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

//method agar jam menyesuaikan dengan waktu pada komputer
void TimerFunction(int value){
  struct timeb tb;
  time_t tim=time(0);
  struct tm* t;
  t=localtime(&tim);
  ftime(&tb);

  jarumdetik = (float)(t->tm_sec+ (float)tb.millitm/1000.0f)/30.0f * M_PI;
  jarummenit = (float)(t->tm_min)/30.0f * M_PI + jarumdetik/60.0f;
  jarumjam = (float)(t->tm_hour > 12 ? t->tm_hour-12 : t->tm_hour)/6.0f * M_PI+
              jarummenit/12.0f;

  glutPostRedisplay();
  glutTimerFunc(33,TimerFunction, 1);
}

// Main program
int main(int argc, char* argv[]){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutCreateWindow("Jam Digital Tapi Analog wkwk");

  glutDisplayFunc(RenderScene);
  glutReshapeFunc(ChangeSize);
  glutTimerFunc(33, TimerFunction, 1);

  SetupRC();

  glutMainLoop();

  return 0;
}

