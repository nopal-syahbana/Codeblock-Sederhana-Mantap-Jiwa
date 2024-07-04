#include <GL/glut.h>
#include <cmath>

GLfloat xRotated, yRotated, zRotated;
GLdouble radius = 3;

void timer( int value )
{
    if( zRotated > 360.0 )
    {
        zRotated -= 360.0 * floor( zRotated / 360.0 ); // Don't allow overflow
    }

    if( yRotated > 360.0 )
    {
        yRotated -= 360.0 * floor( yRotated / 360.0 ); // Don't allow overflow
    }

    zRotated += 5.0;
    yRotated += 1.0;

    glutTimerFunc( 16, timer, 0 );
    glutPostRedisplay();
}

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glDepthMask( GL_FALSE );
    glDisable( GL_DEPTH_TEST );
    glDisable( GL_LIGHTING );

    // 2D rendering
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0, 640, 0, 480, -1, 1 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glPushMatrix();
    {
        glColor3f( 1.0, 1.0, 1.0 );
        glPointSize( 3 );
        glBegin( GL_POINTS );
        for( int i = 1; i < 100; i++ )
        {
            int x = rand() % 640;
            int y = rand() % 480;
            glVertex2i( x, y );
        }
        glEnd();
    }
    glPopMatrix();


    glDepthMask( GL_TRUE );
    glEnable( GL_DEPTH_TEST );

    // Enable lighting
    glEnable( GL_LIGHTING );
    glEnable( GL_LIGHT0 );
    GLfloat qaSpecularLight[] = {1.0, 1.0, 1.0, 1.0};
    glLightfv( GL_LIGHT0, GL_SPECULAR, qaSpecularLight );
    // 3D rendering
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    double w = glutGet( GLUT_WINDOW_WIDTH );
    double h = glutGet( GLUT_WINDOW_HEIGHT );
    gluPerspective( 20.0, w / h, 0.1, 80.0 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( 0.0, 0.0, -40.0 );

    glPushMatrix();
    {
        glutSolidSphere( radius, 25, 25 );
    }
    glPopMatrix();

    glPushMatrix();
    {
        glRotatef( yRotated, 0.0, 2.0, 0.0 );
        glTranslatef( 5.0, 0.0, 0.0 );
        GLfloat qaLightPosition[] = {1, 1, 1, 1};
        glLightfv( GL_LIGHT0, GL_POSITION, qaLightPosition );
        GLfloat emitLight[] = {0.9, 0.9, 0.9, 0.9};
        glMaterialfv( GL_FRONT_AND_BACK, GL_EMISSION, emitLight ); // Make sphere glow (emissive)
        glutSolidSphere( radius / 6, 25, 25 );
        GLfloat Noemit[] = {0.0, 0.0, 0.0, 1.0};
        glMaterialfv( GL_FRONT_AND_BACK, GL_EMISSION, Noemit );
    }
    glPopMatrix();

    glutSwapBuffers();
}

int main( int argc, char** argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize( 1000, 600 );
    glutCreateWindow( "Project_KD" );

    xRotated = yRotated = zRotated = 0.0;

    glutDisplayFunc( display );
    glutTimerFunc( 0, timer, 0 );
    glutMainLoop();
    return 0;
}
