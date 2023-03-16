#include <GL/gl.h>
#include <GL/glut.h>

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glPointSize(4.0);
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex3f (0.25, 0.25, 0.0);
        glVertex3f (0.75, 0.25, 0.0);
        glVertex3f (0.75, 0.75, 0.0);
        glVertex3f (0.25, 0.75, 0.0);
    glEnd();
    glFlush ();
}

void rotate(void){
	glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 1.0f);
	glRotatef(20.0,10,0,1.0f);    
    glBegin(GL_POLYGON);
        glVertex3f (0.25, 0.25, 0.0);
        glVertex3f (0.75, 0.25, 0.0);
        glVertex3f (0.75, 0.75, 0.0);
        glVertex3f (0.25, 0.75, 0.0);
    glEnd();
    glFlush ();
}

void onClickRotate (int button, int state,  int x, int y){
	if (button == GLUT_LEFT_BUTTON)
    	if (state == GLUT_DOWN) {
			glColor3f(1.0f, 0.0f, 0.0f);
			glutDisplayFunc(rotate);
		}
}

void init (void) 
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(400,400, 400, 400, -1.0, 1.0);
    
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:                                        
	exit(0);
	break;
  }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (900, 500); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("atividade_2");
    init ();
    glutDisplayFunc(display); 
    glutMouseFunc(onClickRotate);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;  
}
