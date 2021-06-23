//Star Program
#include<graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    line(150, 150, 125, 200); 
    line(150, 150, 175, 200);
	line(125, 200, 75, 200);
	line(175, 200, 225, 200);
    line(75, 200, 125, 225);
    line(225, 200, 175, 225);
    line(125, 225, 100, 275);
    line(175, 225, 200, 275);
    line(100, 275, 150, 240);
    line(200, 275, 150, 240);
    getch();
    closegraph();
    return 0;
}
