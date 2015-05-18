 #include <stdlib.h> 
#include <GL/glut.h>	
#include<stdio.h>
typedef int BOOL;
#define TRUE 1
#define FALSE 0
static BOOL g_bButton1Down = FALSE;
static GLenum spinMode = GL_TRUE;
static GLenum singleStep = GL_FALSE;
int flag =0;
int flag2 =0;
static float HourOfDay = 0.0;
static float DayOfYear = 0.0;
static float DisplayIncrement = 24.0;
static float HourOfDay1 = 0.0;
static float DayOfYear1 = 0.0;
static float DisplayIncrement1 = 25.0;
GLfloat  whiteLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat  sourceLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat	 lightPos[] = { 0.0f, 0.0f, 0.0f, 1.0f };
//////////////////////////////////////////////////////////////////////////////////
void OpenGLInit(void);
static void Display(void );
static void Key_left(void );
static void Key_right(void );
static void ResizeWindow(int w, int h);
static void KeyPressFunc( unsigned char Key, int x, int y );
/////////////////////////////////////////////////////////////////////////////////
void Lighting()
	{
	glEnable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
	glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    }
    /////////////////////////////////////////////////////////////////////////////
void drawRing(GLfloat px,GLfloat py,GLfloat pz,GLfloat rotation)
{
    glPushMatrix();
    glColor3ub(0,0,250);
    glTranslatef(px,py,pz);
    glRotatef(rotation,0.0f, 1.0f, 0.0f);
    glutSolidTorus(1.0, 1.6, 5, 10);

    rotation+= -1.0f;

    if(rotation > 360.0f)
    {
        rotation = 0.0f;
    }
    glPopMatrix();
}
/////////////////////////////////////////////////////////////
static void Display1(void)
{  
  glLoadIdentity();                  // Reset the model-view matrix
   glTranslatef(-8.f, 6.0f, -6.0f);  // Move left and into the screen
 
   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
 
      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
 
      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f, -1.0f, -1.0f);
 
      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();   // Done drawing the pyramid
 
   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

  GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
   GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
   GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat no_shininess[] = { 0.0 };
   GLfloat low_shininess[] = { 5.0 };
   GLfloat high_shininess[] = { 100.0 };
   GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (spinMode) {
        HourOfDay += DisplayIncrement;
        DayOfYear += DisplayIncrement/24.0;
        HourOfDay = HourOfDay - ((int)(HourOfDay/24))*24;
        DayOfYear = DayOfYear - ((int)(DayOfYear/365))*365;
		}
if (spinMode) {
        HourOfDay1 += DisplayIncrement1;
        DayOfYear1 += DisplayIncrement1/25.0;
        HourOfDay1 = HourOfDay1 - ((int)(HourOfDay1/25))*25;
        DayOfYear1 = DayOfYear1 - ((int)(DayOfYear1/687))*687;
		}
    glLoadIdentity();
glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glTranslatef ( 0.0, 0.0, -8.0 );
	glRotatef( 45.0, 1.0, .0, 0.0 );
    glPushMatrix();
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
  	glColor3f( 1, 0.7, 0.02 );
    glutSolidSphere( 1.0, 40, 40 );
glLightfv(GL_LIGHT0,GL_POSITION,lightPos);


glRotatef( 360.0*DayOfYear1/687.0, 0.0, 1.0, 0.0 );
    glTranslatef( -7.0, 0.0, 0.0 );
    glPushMatrix();
	glRotatef( 300.0*HourOfDay1/25.0, 0.0, 1.0, 0.0 );
    glColor3f( 1.0, 0.8, 0.6 );
    glutSolidSphere( 1.2, 30, 30);
   drawRing(0.2,0.0,0.0,20.0);
    glPopMatrix();
   	 glFlush();
  glPopMatrix();

glRotatef( -360.0*DayOfYear1/687.0, 0.0, 1.0, 0.0 );
    glTranslatef( 2.0, 0.0, 0.0 );
    glPushMatrix();
	glRotatef( 360.0*HourOfDay1/25.0, 0.0, 1.0, 0.0 );
    glColor3f( 1.0, 0.2, 0.3 );
    glutWireSphere( 0.2, 30, 30);
    glPopMatrix();
    glFlush();
  glPopMatrix();   


   	 
glPopMatrix();
    glRotatef( 360.0*DayOfYear/365.0, 0.0, 1.0, 0.0 );
    glTranslatef( 4.0, 0.0, 0.0 );
    glPushMatrix();
	glRotatef( 360.0*HourOfDay/24.0, 0.0, 1.0, 0.0 );
    glColor3f( 0.0, 1.0, 1.0 );
    glutWireSphere( 0.4, 30, 30);
    glPopMatrix();
   	glRotatef( 360.0*12.0*DayOfYear/365.0, 0.0, 1.0, 0.0 );
    glTranslatef( 0.7, 0.0, 0.0 );
    glColor3f( 1, 1, 1 );
    glutSolidSphere( 0.1, 30, 30 );
    glFlush();
    glutSwapBuffers();

	if ( singleStep ) {
		spinMode = GL_FALSE;
	}

	glutPostRedisplay();
}
/////////////////////////////////////////////////////////////////////////////////
static void KeyPressFunc( unsigned char Key, int x, int y )
{
	switch ( Key ) {
	case 'V':
	case 'v':
	if(flag==0)
{
	flag=1;
	//glRotatef( 45.0, 1.0, .0, 0.0 );
	glutDisplayFunc( Display );
}
else
{
	flag=0;
	glutDisplayFunc( Display1 );
}
        break;
        	case 'l':
	case 'L':
	if(flag2==0)
{
	flag2=1;
	glDisable(GL_LIGHTING);
}
else
{
	flag2=0;
	glEnable(GL_LIGHTING);
}
break;
	case 27:	
		exit(1);
	}
}
///////////////////////////////////////////////////////////////////////////////////////
void MouseButton(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON)
    {
      g_bButton1Down = (state == GLUT_DOWN) ? TRUE : FALSE;
			Key_left();
    }
   else if (button == GLUT_RIGHT_BUTTON)
    {
      g_bButton1Down = (state == GLUT_DOWN) ? TRUE : FALSE;
			Key_right();
    }
}
////////////////////////////////////////////////
static void Key_left(void)
{
    DisplayIncrement *= 2.0;
    DisplayIncrement1 *= 2.0;			
}
////////////////////////////////////////////////
static void Key_right(void)
{
    DisplayIncrement /= 2.0;
    DisplayIncrement1 /=2.0;		
	
}
///////////////////////////////////////////////
static void Display(void)
{
 glLoadIdentity();                  // Reset the model-view matrix
   glTranslatef(-8.f, 6.0f, -6.0f);  // Move left and into the screen
 
   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
 
      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
 
      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f, -1.0f, -1.0f);
 
      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();   // Done drawing the pyramid
 
   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

  GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
   GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
   GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat no_shininess[] = { 0.0 };
   GLfloat low_shininess[] = { 5.0 };
   GLfloat high_shininess[] = { 100.0 };
   GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (spinMode) {
        HourOfDay += DisplayIncrement;
        DayOfYear += DisplayIncrement/24.0;
        HourOfDay = HourOfDay - ((int)(HourOfDay/24))*24;
        DayOfYear = DayOfYear - ((int)(DayOfYear/365))*365;
		}
 if (spinMode) {
        HourOfDay1 += DisplayIncrement1;
        DayOfYear1 += DisplayIncrement1/25.0;
        HourOfDay1 = HourOfDay1 - ((int)(HourOfDay1/25))*25;
        DayOfYear1 = DayOfYear1 - ((int)(DayOfYear1/687))*687;
		}
    glLoadIdentity();
glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glTranslatef ( 0.0, 0.0, -8.0 );
	glRotatef( 0.0, 1.0, .0, 0.0 );
    glPushMatrix();
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
  	glColor3f( 1, 0.7, 0.02 );
    glutSolidSphere( 1.0, 40, 40 );
glLightfv(GL_LIGHT0,GL_POSITION,lightPos);

glRotatef( 360.0*DayOfYear1/687.0, 0.0, 1.0, 0.0 );
    glTranslatef( 7.0, 0.0, 0.0 );
    glPushMatrix();
	glRotatef( 300.0*HourOfDay1/25.0, 0.0, 1.0, 0.0 );
    glColor3f( 1.0, 0.8, 0.6 );
    glutSolidSphere( 1.2, 30, 30);
   drawRing(0.0,0.0,0.0,20.0);
    glPopMatrix();
   	 glFlush();
glPopMatrix();

glRotatef( -360.0*DayOfYear1/687.0, 0.0, 1.0, 0.0 );
    glTranslatef( 2.0, 0.0, 0.0 );
    glPushMatrix();
	glRotatef( 300.0*HourOfDay1/25.0, 0.0, 1.0, 0.0 );
    glColor3f( 1.0, 0.2, 0.3 );
    glutWireSphere( 0.2, 30, 30);
    glPopMatrix();
   	 glFlush();
glPopMatrix();


    glRotatef( 360.0*DayOfYear/365.0, 0.0, 1.0, 0.0 );
    glTranslatef( 4.0, 0.0, 0.0 );
    glPushMatrix();
	glRotatef( 360.0*HourOfDay/24.0, 0.0, 1.0, 0.0 );
    glColor3f( 0.0, 1.0, 1.0 );
    glutSolidSphere( 0.4, 30, 30);
    glPopMatrix();
   	glRotatef( 360.0*12.0*DayOfYear/365.0, 0.0, 1.0, 0.0 );
    glTranslatef( 0.7, 0.0, 0.0 );
    glColor3f( 1, 1, 1 );
    glutSolidSphere( 0.1, 30, 30 );
   glFlush();


    glutSwapBuffers();
	if ( singleStep ) {
		spinMode = GL_FALSE;
	}
	glutPostRedisplay();
}
////////////////////////////////////////////////////////////

void OpenGLInit(void)
{
    glShadeModel( GL_FLAT );
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glClearDepth( 1.0 );
    glEnable( GL_DEPTH_TEST );
}
///////////////////////////////////////////////////////////
static void ResizeWindow(int w, int h)
{
    float aspectRatio;
	h = (h == 0) ? 1 : h;
	w = (w == 0) ? 1 : w;
	glViewport( 0, 0, w, h );
	aspectRatio = (float)w/(float)h;
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 100.0, aspectRatio, 1.0, 30.0 );
    glMatrixMode( GL_MODELVIEW );
}
/////////////////////////////////////////////////////////
int main( int argc, char** argv )
{
       
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	printf("V or v to change angle\nL or l to switch on/off lighting\nRight CLick to slow down by a factor of 2\nLeft CLick to increase speed by a factor of 2\n");
	glutInitWindowPosition( 0, 0 );
	glutInitWindowSize( 1800, 1000);
	glutCreateWindow( "Assignment" );
	OpenGLInit();
	Lighting();
	glutKeyboardFunc( KeyPressFunc );
	glutMouseFunc (MouseButton);
	glutReshapeFunc( ResizeWindow );
	glutDisplayFunc( Display );
	glutMainLoop(  );
	return(0);
}
