//Write a program to fill a square of multiple boundary colors using Floodfill algorithm 4-connected approach.

#include<graphics.h>
#include<stdio.h>

void flood_fill_4(int x, int y, int oldcol, int newcol){
	if(getpixel(x,y) == oldcol && getpixel(x,y) != newcol){
		putpixel(x, y, newcol);
		flood_fill_4(x+1, y, oldcol, newcol);
		flood_fill_4(x-1, y, oldcol, newcol);
		flood_fill_4(x, y+1, oldcol, newcol);
		flood_fill_4(x, y-1, oldcol, newcol);
	}
}

int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	setcolor(BLUE);
	line(10, 10, 200, 10);
	setcolor(YELLOW);
	line(10, 110, 200, 110);
	setcolor(MAGENTA);
	line(10, 10, 10, 110);
	setcolor(GREEN);
	line(200, 10, 200, 110);
	flood_fill_4(180, 12, BLACK, BROWN);
	getch();
	closegraph();
	return 0;
}
