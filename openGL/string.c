/* 

 * to display characters  

 */ 

 

#include<GL/glu.h>		// libraries 

#include <GL/glut.h> 

#include<string.h> 

 

void initGL() 

{ 

	glClearColor(0.0,0.0,0.0,0.0);	/* set background to black */ 

  	gluOrtho2D(0,400,0,500);		/* how object is mapped to window */ 

} 



void print() 

{ 

        char str[20]; 

	strcpy(str,"Welcome to OpenGL"); 

	//get the length of the string to display 

 	int len = (int) strlen(str); 
	glColor3f(0.0,1.0,1.0); 

	//set the position of the text in the window using the x and y coordinates 

	glRasterPos2f(100,200); 

/* 

The function glutBitmapCharacter() renders the character at the required position and advances the current raster position by the width of the character.  

to render a string, successive calls to glutBitmapCharacter() will suffice to achieve the desired output. 

*/ 

//loop to display character by character 

	for (int i = 0; i<= len; i++)  

	{ 

		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);    

	} 
	glutSwapBuffers(); 
} 

void main(int argc, char *argv[]) 

{ 

  int win; 

  glutInit(&argc, argv);		/* initialize GLUT system */ 

  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); 

  glutInitWindowSize(800,500);		/* width=400pixels height=500pixels */ 

  win = glutCreateWindow("Rendering text");	/* create window */ 

 

  /* from this point on the current window is win */ 

 

  initGL(); 

  glutDisplayFunc(print);		/* set window's display callback */ 

  
  glutMainLoop();			/* start processing events... */ 

 

  /* execution never reaches this point */ 

   

} 

 


 
//glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);    


