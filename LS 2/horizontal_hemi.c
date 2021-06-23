//Write a program to draw a hemisphere as follows using midpoint circle generation.
//(Hint: only 1st and 4th quadrants)

#include<graphics.h>
#include<stdio.h>
#include "circle.h"

void hemisphere(int r, int xc, int yc){
	int x[1000], y[1000];
	x[0] = 0;
	y[0] = r;
	
	int p = 1 - r;
	int k = point_calculation(p, x, y);

	//PLOTTING THE CIRCLE
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
	for(int i = 0; i<k; i++){
		putpixel(y[i] + xc, -x[i] + yc, WHITE);//Octant 3
		putpixel(x[i] + xc, -y[i] + yc, WHITE);//Octant 4
		putpixel(-x[i] + xc, -y[i] + yc, WHITE);//Octant 5
		putpixel(-y[i] + xc, -x[i] + yc, WHITE);//Octant 6
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
	hemisphere(r, xc, yc);
	return 0;
}
