#include<GL/glu.h>		// libraries
#include <GL/glut.h>

//one-time OpenGL initialization tasks, such as setting the clearing color. 
void initGL(float r, float g, float b) // user defined function
{	
	glClearColor(r,g,b,0.0);  /* set background to white */

/*
	glMatrixMode sets the current matrix mode.
         mode can assume one of four values:
             GL_MODELVIEW
	            Applies subsequent matrix operations to the modelview matrix stack.
	        GL_PROJECTION
	            Applies subsequent matrix operations to the projection matrix stack.
	        GL_TEXTURE
	            Applies subsequent matrix operations to the texture matrix stack.
	        GL_COLOR
	            Applies subsequent matrix operations to the color matrix stack.
                    
            To find out which matrix stack is currently the target of all matrix
            operations, call glGet with argument GL_MATRIX_MODE. The initial
            value is GL_MODELVIEW.
*/

	glMatrixMode (GL_PROJECTION);

/*  gluOrtho2D - sets up a two-dimensional orthographic viewing region. */                
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);    //define a 2D orthographic projection matrix


/* 		 4 arguments (left, right, bottom, top)
 *		 left, right - Specify the coordinates for the left and right vertical clipping planes.
 *       bottom, top - Specify the coordinates for the bottom and top horizontal clipping planes.
 */
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);   /* clear the display */

	glColor3f(0.0, 0.0, 1.0); /* set current color to blue */
	
	glShadeModel(GL_SMOOTH); /*provides shading*/
	//glShadeModel(GL_FLAT); /*color of the object will be the color of the first vertex */

	// draw a triangle
	glBegin(GL_POLYGON);  // drawing starts
		glVertex2i(180,50);
		glColor3f(0.0, 1.0, 1.0); //changing dawing color
		glVertex2i(190,100);
		glColor3f(1.0, 1.0, 0.0); //changing dawing color
		glVertex2i(140,100);
	glEnd();  // drawing ends

// draw a triangle fan
	glShadeModel(GL_FLAT);	
	glBegin(GL_TRIANGLE_FAN);  // drawing starts	
		glVertex2i(50,50);
		glColor3f(0.0, 1.0, 1.0); 
		glVertex2i(20,100);
		glColor3f(1.0, 1.0, 0.0); 
		glVertex2i(40,150);
		glColor3f(1.0, 0.0, 1.0);
		glVertex2i(80,130);
		glColor3f(0.0, 1.0, 1.0); 
		glVertex2i(120,100);
		glColor3f(0.5, 0.3, 0.2); 
		glVertex2i(140,70);
	glEnd();  // drawing ends

	 //glFlush(); /* Complete any pending operations */  // for GLUT_SINGLE mode only  

 glutSwapBuffers();   /* Complete any pending operations */  //if displaymode GLUT_DOUBLE use this
}



void main(int argc,char *argv[])
{
	glutInit(&argc,argv); // initializes GLUT...similar to main 
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); // single buffer / double buffer
	glutInitWindowSize (1000, 500); // window size specification
	glutInitWindowPosition (100, 100); // locate window
	glutCreateWindow ("points and lines"); // window creation
	initGL(1.0,1.0,1.0); // called only once
	glutDisplayFunc(display); // register the call back function for handling window paint event
	glutMainLoop();  // event processing loop
}
