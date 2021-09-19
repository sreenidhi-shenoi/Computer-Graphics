//Write a program to fill a rectangle already filled with a color with another color using Floodfill algorithm 8-connected approach.
//Accept old color and fill color from user.

#include<graphics.h>
#include<stdio.h>

void flood_fill_8(int x, int y, int oldcol, int newcol){
	if(getpixel(x,y) == oldcol && getpixel(x,y) != newcol){
		putpixel(x, y, newcol);
		flood_fill_8(x+1, y, oldcol, newcol);
		flood_fill_8(x-1, y, oldcol, newcol);
		flood_fill_8(x, y+1, oldcol, newcol);
		flood_fill_8(x, y-1, oldcol, newcol);
		flood_fill_8(x+1, y+1, oldcol, newcol);
		flood_fill_8(x+1, y-1, oldcol, newcol);
		flood_fill_8(x-1, y+1, oldcol, newcol);
		flood_fill_8(x-1, y-1, oldcol, newcol);
	}
}

int main() {
	int oldcol, newcol;
	printf("Enter fillcolor (old): ");
	scanf("%d", &oldcol);
	printf("Enter fillcolor (new): ");
	scanf("%d", &newcol);

	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
		
	setcolor(BLUE);
	line(100, 100, 100, 300);
	setcolor(GREEN);
	line(100, 300, 400, 300);
	setcolor(LIGHTBLUE);
	line(400, 100, 400, 300);
	setcolor(LIGHTGREEN);
	line(100, 100, 400, 100);
	flood_fill_8(200, 250, BLACK, oldcol);	
	flood_fill_8(200, 250, oldcol, newcol);
	getch();
	closegraph();
	return 0;
}
