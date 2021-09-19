//Write a program to fill a rectangle using Boundary fill algorithm 8-connected approach.
// Accept Boundary color and fill color from user.

#include<graphics.h>
#include<stdio.h>

void boundary_fill_eight_con(int x, int y, int bcolor, int fcolor) {
	if(getpixel(x,y) != bcolor && getpixel(x,y) != fcolor) {
		putpixel(x, y, fcolor);
		boundary_fill_eight_con(x+1, y, bcolor, fcolor);
		boundary_fill_eight_con(x-1, y, bcolor, fcolor);
		boundary_fill_eight_con(x, y+1, bcolor, fcolor);
		boundary_fill_eight_con(x, y-1, bcolor, fcolor);
		boundary_fill_eight_con(x+1, y-1, bcolor, fcolor);
		boundary_fill_eight_con(x+1, y+1, bcolor, fcolor);
		boundary_fill_eight_con(x-1, y-1, bcolor, fcolor);
		boundary_fill_eight_con(x-1, y+1, bcolor, fcolor);
		}
}


int main() {
	int bcolor, fcolor;
	printf("Enter boundary color: ");
	scanf("%d", &bcolor);
	printf("Enter fill color: ");
	scanf("%d", &fcolor);
	
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	setcolor(bcolor);
  rectangle(100, 100, 450, 450);
	boundary_fill_eight_con(140, 150, bcolor, fcolor);
	getch();
	closegraph();
	return 0;
}
