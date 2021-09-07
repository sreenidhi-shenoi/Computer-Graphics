#include<GL/glu.h>
#include<GL/glut.h>

void initGL(float r, float g, float b){
	glClearColor(r, g, b, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void drawLine(){
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
		glVertex2i(180, 50);
		glVertex2i(160, 50);		
	glEnd();

	glColor3f(1.0, 0.0, 0.0);	
	glBegin(GL_LINES);
		glVertex2i(160,50);
		glVertex2i(160, 70);
	glEnd();
	
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
		glVertex2i(160,70);
		glVertex2i(180, 70);
	glEnd();

	glColor3f(0.5, 1.0, 0.5);	
	glBegin(GL_LINES);
		glVertex2i(180,70);
		glVertex2i(180, 50);
	glEnd();

	glFlush();
}

int main(int argc, char * argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("openGL Line");
	
	initGL(1.0, 1.0, 1.0);
	glutDisplayFunc(drawLine);
	glutMainLoop();
	return 0;
}
