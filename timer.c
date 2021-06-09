#include "GL/glut.h"
#include "GL/gl.h"
#include<string.h>
#include<math.h>

int theta=-1;

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

	strcpy(str,"Welcome to Timer"); 

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
//rotating triangle
void rotate()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix(); //pushing the transformation matrix into the stack
	glRotated(theta,0,0,1);  //assign rotation values

	glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); // NO FILLING, ONLY BOUNDARY COLORS
	
	// draw a triangle fan
	glBegin(GL_TRIANGLE_FAN);  // drawing starts
		glVertex2i(150,50);
		glColor3f(0.0, 1.0, 1.0); 
		glVertex2i(120,100);
		glColor3f(1.0, 1.0, 0.0); 
		glVertex2i(140,150);
		glColor3f(1.0, 0.0, 1.0);
		glVertex2i(180,130);
		glColor3f(0.0, 1.0, 1.0); 
		glVertex2i(220,100);
		glColor3f(0.5, 0.3, 0.2); 
		glVertex2i(240,70);
	glEnd();  // drawing ends

	theta--;
	glPopMatrix(); //poping the transformation matrix from the stack
	glutSwapBuffers(); // for GLUT_DOUBLE mode only
}


void start()
{
	glutIdleFunc(rotate);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1500, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Rotating a triangle w.r.t timer");
    glutDisplayFunc(display);
    glutTimerFunc(1000,start,0);  // calls start function after 1000 milliseconds
    glutMainLoop();
    return 0;
}
