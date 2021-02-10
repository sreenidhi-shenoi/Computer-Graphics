#include<stdio.h>
#include<graphics.h>

int main(){
	int gd = DETECT, gm;
	printf("Moving to graphics mode...\n");
	initgraph(&gd, &gm, NULL);
	setbkcolor(BLACK);
	setcolor(WHITE);
	//setfillstyle(LINE_FILL,CYAN);
	circle(250,250, 100);
	setcolor(BROWN);
	line(145, 145, 355, 145);
	line(145, 145, 145, 355);
	line(355, 145, 355, 355);
	line(145, 355, 355, 355);
	line(145, 145, 245, 45);
	line(245, 45, 355, 145);
	outtextxy(185, 250, "WELCOME HOME :)!");
	getch();
	closegraph();
	printf("Exiting the graphics mode...\n");
    return 0;
}
