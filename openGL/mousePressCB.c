#include<GL/glut.h>
void initGL(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0, 200, 150, 0);
}
void drawLineStrip(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);
		glVertex2i(10.0, 50.0);
		glVertex2i(50.0, 75.0);
		glVertex2i(10.0, 100.0);
	glEnd();
	glFlush();
}
void mousePressedCB(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		drawLineStrip();
	}
	if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN){
		glColor3f(1.0, 0.0, 0.0);
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
	}	
}
int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Mouse Pressed!");
	initGL();
	glutMouseFunc(mousePressedCB);
	glutMainLoop();
}
