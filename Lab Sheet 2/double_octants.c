//Write a program to draw sector as follows using midpoint circle generation.
//(Hint: only 2nd and 6th octants) => 3rd and 7th Octants
#include<graphics.h>
#include<stdio.h>
#include "circle.h"


void hemisphere(int r, int xc, int yc){
	int x[1000], y[1000];

	//storing first point
	x[0] = 0;
	y[0] = r;
	
	//calculating initial decision parameter, subsequent points
	int p = 1 - r;
	int k = point_calculation(p, x, y);
	
	//PLOTTING THE CIRCLE
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
	line(-y[0]+xc, x[0]+yc, y[0]+xc, -x[0]+yc);
	for(int i = 1; i<k; i++){
		putpixel(y[i] + xc, -x[i] + yc , WHITE); //Octant 3
		putpixel(-y[i]+ xc, x[i] + yc, WHITE); //Octant 7
	}
	line(-y[k-1]+xc, x[k-1]+yc, y[k-1]+xc, -x[k-1]+yc);
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
