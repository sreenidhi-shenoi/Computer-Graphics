//Bresenham's Line Drawing With Slope Greater than 1
#include<stdio.h>
#include<graphics.h>

int main() {
	int x1, y1, x2, y2;
	
	//Input the endpoints
	printf("Enter start points x1, y1: ");
	scanf("%d %d", &x1, &y1);
	printf("Enter start points x2, y2: ");
	scanf("%d %d", &x2, &y2);

	//finding m
	int dx = x2 - x1;
	int dy = y2 - y1;
	float m = abs(dy / dx);
	
	if(m < 1){
		printf("Slope lesser than 1!\n");
		return 0;
	}
	
	int x, y;
	int gd = DETECT, gm;	
	
	initgraph(&gd, &gm, NULL);
	
	//storing and plotting (x0, y0)
	if(x2 < x1){
		x = x2;
		y = y2;
	}
	else{
		x = x1;
		y = y1;
	}
	putpixel(x, y, RED);

	//Calculating constants
	int p, pn;
	int const1 = (2*dx) - (2*dy);

	p = (2*dx) - dy;

	for(int k = 1; k < dy; k++) {
		//Calculating and plotting next point
		if (p < 1) {
			pn = p + (2*dx);
			y = y+1; //increment y, x remains the same
		}
		else {
			pn = p + const1;
			x = x+1; //increment x
			y = y+1; //increment y
		}
		putpixel(x, y, RED);
		//Updating p value
		p = pn;
	} 
	
	getch();
	closegraph();
	return 0;
}
