#include<graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int r = 5;
    int colors[] = {14, 4, 1, 0, 15};
    setbkcolor(8);
    setcolor(14);
    for(int i = 0, j = 0; i < 10; i++) {
    	circle(300, 250, r);
    	r += 20;
    	if( i > 1 && i % 2 == 0) {
    	    j++;
    	    setcolor(colors[j]);
    	}
    }
    getch();
    closegraph();
    return 0;
}
