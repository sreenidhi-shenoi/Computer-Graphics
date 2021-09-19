/*
	OpenGL program for Text Display and Rotation Transformation
*/

#include "GL/glut.h"
#include "GL/gl.h"
#include<string.h>

int theta=1;
int tx=1, ty=2;

void initGL()
{
	glClearColor(0.4, 0.4, 0.4, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
    
    glClear(GL_COLOR_BUFFER_BIT); /* clear the display */
    gluOrtho2D(0, 500, 0, 500);

    char str[30]; 

	strcpy(str,"Welcome to Animation"); 

	//get the length of the string to display 

 	int len = (int) strlen(str); 
	glColor3f(0.0,1.0,1.0); 

	//set the position of the text in the window using the x and y coordinates 

	glRasterPos2f(100,200); 

//loop to display character by character 

	for (int i = 0; i<= len; i++)  

	{ 

		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);    

	} 
    glutSwapBuffers(); 
}
//translating triangle
void translate()
{
	glClear(GL_COLOR_BUFFER_BIT);	
	glPushMatrix(); //pushing the transformation matrix into the stack
	glTranslated(tx,ty,0);  //assign translation values
	glColor3f(1.0, 0.0, 0.0); /* set current color to red */
	
	glShadeModel(GL_SMOOTH); /*provides shading*/
	

	// draw a triangle
	glBegin(GL_TRIANGLES);  // drawing starts
		glVertex2i(80,50);
		glColor3f(0.5, 0.5, 0.0); //changing drawing color
		glVertex2i(90,100);
		glColor3f(0.7, 0.3, 0.0); //changing drawing color
		glVertex2i(40,100);
	glEnd();  // drawing ends
	tx++;
	ty=ty+2;
	glPopMatrix(); //poping the transformation matrix from the stack
   	glutSwapBuffers(); 
}
//rotating triangle
void rotate()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPushMatrix(); //pushing the transformation matrix into the stack
	glRotated(theta,0,0,1);  //assign rotation values

	glShadeModel(GL_SMOOTH); /*provides shading*/
	

	// draw a triangle
	glBegin(GL_TRIANGLES);  // drawing starts
		glColor3f(0.0, 0.0, 1.0); /* set current color to blue */		
		glVertex2i(260,320);
		glColor3f(0.0, 1.0, 1.0); //changing drawing color
		glVertex2i(270,370);
		glColor3f(1.0, 1.0, 0.0); //changing drawing color
		glVertex2i(220,370);
	glEnd();  // drawing ends
	theta++;
	glPopMatrix(); //poping the transformation matrix from the stack
	glutSwapBuffers(); // for GLUT_DOUBLE mode only
}



void keyPress(unsigned char key, int x, int y)	/* called on key press */
{
  
	switch(key){
	  case 'r':
	  	glutIdleFunc(rotate);  /* glutIdleFunc sets the global idle callback to be func so a GLUT program can perform background processing tasks or continuous animation when window system events are not being received. If enabled, the idle callback is continuously called when events are not being received. The callback routine has no parameters. */
		break;
	  case 's':
		glutIdleFunc(NULL); 
		break;
	  case 't':
		glutIdleFunc(translate);
		break;	
	  default:
		break;
	}

}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1500, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Rotating a triangle");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPress);		/* set window's key callback */
    glutMainLoop();
    return 0;
}
