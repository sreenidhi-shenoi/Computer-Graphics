#include<graphics.h>

void boundary_fill_four_con(int x, int y, int bcolor, int fcolor){
	if(getpixel(x,y) != bcolor && getpixel(x,y) != fcolor) {
		putpixel(x, y, fcolor);
		boundary_fill_four_con(x+1, y, bcolor, fcolor);
		boundary_fill_four_con(x-1, y, bcolor, fcolor);
		boundary_fill_four_con(x, y+1, bcolor, fcolor);
		boundary_fill_four_con(x, y-1, bcolor, fcolor);
	}
}

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	setcolor(BLUE);
	rectangle(150, 150, 350, 350);
	boundary_fill_four_con(200, 200, BLUE, RED);
	getch();
	closegraph();
	return 0;
}


