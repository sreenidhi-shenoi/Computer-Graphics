//Write a program to draw a circle using Midpoint circle algorithm.

#include<graphics.h>
#include<stdio.h>
#include "circle.h"

void circle(int r, int xc, int yc){
	int x[1000], y[1000];
	//storing first point
	x[0] = 0;
	y[0] = r;
	
	//calculating initial decision parameter:
	int p = 1 -r;

	//calculating subsequent points
	int k = point_calculation(p, x, y);
	
	//PLOTTING THE CIRCLE
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
	for(int i = 0; i<k; i++){
		putpixel(x[i] + xc, y[i] + yc, 15);    //Octant 1
		putpixel(y[i] + xc, x[i] + yc, 15);    //Octant 2
		putpixel(y[i] + xc, -x[i] + yc, 15);   //Octant 3
		putpixel(x[i] + xc, -y[i] + yc, 15);   //Octant 4
		putpixel(-x[i] + xc, -y[i] + yc, 15);  //Octant 5
		putpixel(-y[i] + xc, -x[i] + yc, 15);  //Octant 6
		putpixel(-y[i] + xc, x[i] + yc, 15);   //Octant 7
		putpixel(-x[i] + xc, y[i] + yc, 15);   //Octant 8
	}
	
	getch();
	closegraph();
	return;
}

int main(){
	//input radius r, circle centre
	int r, xc, yc;
	printf("Enter radius: ");
	scanf("%d", &r);
	printf("\nEnter circle centre points [x,y]: ");
	scanf("%d %d", &xc, &yc);
	
	//call circle drawing function
	circle(r, xc, yc);
	return 0;
}
