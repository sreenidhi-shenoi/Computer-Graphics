/*
 *  A simple example of mouse callback in OpenGL.
 */

#include<GL/glu.h>		// libraries
#include <GL/glut.h>


void displaytriangle()		/* function called whenever triangle display needed */
{
  glClear(GL_COLOR_BUFFER_BIT);		/* clear the display */
  glColor3f(1.0, 1.0, 0.0);		/* set current color to white */
  glBegin(GL_POLYGON);			/* draw filled triangle */
  glVertex2i(200,125);			/* specify each vertex of triangle */
  glVertex2i(100,375);
  glVertex2i(300,375);
  glEnd();				/* OpenGL draws the filled triangle */
  glFlush();				/* Complete any pending operations */
}


void displaypoly()		/* function called whenever square display needed */
{
  glClear(GL_COLOR_BUFFER_BIT);		/* clear the display */
  glColor3f(0.0, 0.5, 1.0);		/* set current color  */
  glBegin(GL_POLYGON);			/* draw filled square */
  glVertex2i(200,125);			/* specify each vertex of square */
  glVertex2i(300,125);
  glVertex2i(300,375);
  glVertex2i(200,175);
  glEnd();				/* OpenGL draws the filled square */
  glFlush();				/* Complete any pending operations */
}

void mousepress(int button,int state,int x, int y )
{
	if (button==GLUT_LEFT_BUTTON && state==GLUT_UP) // checking the button and state
		exit(0);
	else if (button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
		displaypoly();
	else if (button==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
		displaytriangle();

}

void main(int argc, char *argv[])
{
  int win;

  glutInit(&argc, argv);		/* initialize GLUT system */

  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(400,500);		/* width=400pixels height=500pixels */
  glutCreateWindow("Triangle");	/* create window */

  /* from this point on the current window is the window created */

  glClearColor(0.0,0.0,0.0,0.0);	/* set background to black */
  gluOrtho2D(0,400,0,500);		/* how object is mapped to window */
  glutDisplayFunc(displaytriangle);		/* set window's display callback */
  glutMouseFunc(mousepress);		/* set window's mouse callback */
  glutMainLoop();			/* start processing events... */

  /* execution never reaches this point */

  
}
