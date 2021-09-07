#include "GL/glut.h"
#include "GL/gl.h"


void drawTriangle()
{
    glClearColor(0.4, 0.4, 0.4, 1.0);
    glClear(GL_COLOR_BUFFER_BIT); /* clear the display */
    gluOrtho2D(0, 500, 0, 500);

    glColor3f(0.0, 0.0, 1.0); /* set current color to blue */
	
	glShadeModel(GL_SMOOTH); /*provides shading*/
	

	// draw a triangle
	glBegin(GL_TRIANGLES);  // drawing starts
		glVertex2i(80,50);
		glColor3f(0.0, 1.0, 1.0); //changing dawing color
		glVertex2i(90,100);
		glColor3f(1.0, 1.0, 0.0); //changing dawing color
		glVertex2i(40,100);
	glEnd();  // drawing ends

    glFlush(); // for GLUT_SINGLE mode only

}

//translating triangle
void scale()
{
	glPushMatrix(); //pushing the transformation matrix into the stack
	glScalef(0.5,0.5,0);  //assign translation values
	glColor3f(1.0, 0.0, 0.0); /* set current color to blue */
	
	glShadeModel(GL_SMOOTH); /*provides shading*/
	

	// draw a triangle
	glBegin(GL_TRIANGLES);  // drawing starts
		glVertex2i(80,50);
		glColor3f(0.5, 0.5, 0.0); //changing drawing color
		glVertex2i(90,100);
		glColor3f(1.0, 0.0, 1.0); //changing drawing color
		glVertex2i(40,100);
	glEnd();  // drawing ends

    	glFlush(); // for GLUT_SINGLE mode only
	glPopMatrix(); //poping the transformation matrix from the stack
}



void keyPress(unsigned char key, int x, int y)	/* called on key press */
{
  
  if (key == 'q')
     	exit(0);
   else if (key=='s')
	scale();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1500, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Scaling a triangle");
    glutDisplayFunc(drawTriangle);
    glutKeyboardFunc(keyPress);		/* set window's key callback */
    glutMainLoop();
    return 0;
}
