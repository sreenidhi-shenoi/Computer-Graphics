#include<GL/glut.h>
#include<GL/glu.h>

void drawTriangle(){
	glClearColor(0.4, 0.4, 0.4, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0, 500, 0, 500);

	glColor3f(0.0, 1.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glBegin(GL_TRIANGLES);
		glVertex2i();
		glColor3f();
		glVertex2i();
		glColor3f();
		glVertex2i();
		glColor3f();
	glEnd();	
	glFlush();
}

void translate(){
	glPushMatrix();
	glTranslated(120, 130, 0);
	glColor3f(1.0, 0.0, 0.0);
	
	glShadeModel(GL_SMOOTH);
	
	glBegin(GL-TRIANGLES);
		glVertex2i();
		glColor3f();
		glVertex2i();
		glColor3f();
		glVertex2i();
		glColor3f();
	glEnd();
	
	glFlush();
	glPopMatrix();
}

void keyCB(unsigned char key, int x, int y)	/* called on key press */
{
  
  if (key == 'q')
     	exit(0);
  else if (key=='t')
	translate();
}

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1500, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Translating a triangle");
	glutDisplayFunc(drawTriangle);
	glutKeyboardFunc(keyCB);
	glutMainLoop();
	return 0;
}
