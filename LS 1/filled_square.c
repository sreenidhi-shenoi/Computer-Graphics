//Filled Square
#include<graphics.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    rectangle(150, 150, 350, 350);
    floodfill(200, 200, 2);
    getch();
    closegraph();
    return 0;
}
