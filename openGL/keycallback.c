/*
 *  A simple example of keyboard callback in OpenGL.
 */

#include <GL/glut.h> // header files

void initGL()
{
  glClearColor(0.0,0.0,0.0,0.0);	/* set background to black */
  gluOrtho2D(0,400,0,500);		/* how object is mapped to window */
  
}

void displaytriangle()	/* function called whenever triangle display needed */
{
  glClear(GL_COLOR_BUFFER_BIT);		/* clear the display */
  glColor3f(1.0,1.0,1.0);		 /* set current color to white*/
  glBegin(GL_POLYGON);			/* draw filled triangle */
  glVertex2i(200,125);			/* specify each vertex of triangle */
  glVertex2i(100,375);
  glVertex2i(300,375);
  glEnd();				/* OpenGL draws the filled triangle */
  glFlush();				/* Complete any pending operations */
}
void drawsquare() /* function called whenever square display needed */
{
  glClear(GL_COLOR_BUFFER_BIT);		/* clear the display */
  glColor3f(0.0,1.0,1.0);		 /* set current color */
  glBegin(GL_POLYGON);			/* draw filled square */
  glVertex2i(100,125);			/* specify each vertex of square */
  glVertex2i(100,375);
  glVertex2i(300,375);
  glVertex2i(300,125);
  glEnd();				/* OpenGL draws the filled square */
  glFlush();				/* Complete any pending operations */
}
void keyCB(unsigned char key, int x, int y)	/* called on key press */
{
  
  if (key == 'q')
     	exit(0);
  else if (key=='s')
	drawsquare();
  else if (key=='t')
	displaytriangle();
}


int main(int argc, char *argv[])
{
  int win;

  glutInit(&argc, argv);		/* initialize GLUT system */

  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(400,500);		/* width=400pixels height=500pixels */
  win = glutCreateWindow("Triangle");	/* create window */

  /* from this point on the current window is win */

  initGL();
  glutDisplayFunc(displaytriangle);		/* set window's display callback */
  glutKeyboardFunc(keyCB);		/* set window's key callback */

  glutMainLoop();			/* start processing events... */

  /* execution never reaches this point */

  return 0;
}
