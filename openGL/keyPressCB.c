//Write an OpenGL program to change the background color on pressing ‘b’.

#include<GL/glut.h>
#include<stdio.h>

void initGL(float r, float g, float b){
	glClearColor(r, g, b, 0.0);
	gluOrtho2D(0, 200, 150, 0);
}

void keyPressedCB(unsigned char key, int x, int y){
	if (key == 'b'){
		glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
	}
	if (key == 'e')
		exit(0);
}

void main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Key Pressed!");
	initGL(0.0, 0.0, 0.0);
	glutKeyboardFunc(keyPressedCB);	
	glutMainLoop();
}
