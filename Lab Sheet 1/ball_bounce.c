#include<graphics.h>

int main() {
	int gd = DETECT, gm;
	int x = 100, y = 200;
	initgraph(&gd, &gm, NULL);
	for(int b = 0; b < 4; b++) {
			for(int j = 0; j<50; j+=10){
				x += 15;
				y -= j;
				circle(x, y, 100);
				delay(100);
		 	   	cleardevice();
			}
			for(int j = 0; j < 15; j+=5) {
				x += j;
				circle(x, y , 100);
				delay(100);
				cleardevice();
			}
			for(int j = 0; j < 50; j+=10){
				x += 2;
				y += j;
				circle(x, y, 100);
				delay(100);
				cleardevice();
				if (j == 50)
					break;
			}
		}
	getch();
	closegraph();
	return 0;
}
