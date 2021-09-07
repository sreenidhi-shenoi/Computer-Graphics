#include<GL/glut.h>
#include<string.h>

void initGL(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0, 200, 150, 0);
}

void output()
{
	  glClear(GL_COLOR_BUFFER_BIT); //Added this
	  glColor3f( 1.0, 0.0, 0.4);
	  glRasterPos2f(10.0, 10.0);
	  int len, i;
	  char* string = "SREENIDHI";
	  len = (int)strlen(string);
	  for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	  }
	  glFlush(); //Added this
}
int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Display Name!");
	initGL();
	glutDisplayFunc(output); //Added this
	glutMainLoop();
}
