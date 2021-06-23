/* Write a program to reflect a triangle w.r.t a line y=x
 */
 
 #include<graphics.h>
 void mat_mul(int m[][3], int p[], int pd[]){
 	for(int i = 0; i<3; i++){
 		for(int j = 0; j<3; j++){
 			pd[i] += m[i][j] * p[j];
 		}
 	}
 }
 
 void reflect_triangle(int tc[]) {
 	int R[][3] = { {0, 1, 0}, {1, 0, 0}, {0, 0, 1}};
 	int pd[] = {0, 0, 0};
 	for(int i = 0; i<7; i+=2){
 		int p[] = {tc[i], tc[i+1], 1};
 		mat_mul(R, p, pd);
 		tc[i] = pd[0];
 		tc[i+1] = pd[1];
 		pd[0] = pd[1] = 0;	
 	}
 }
 
 int main(){
 	int tri_cord[8];
  	printf("Enter Triangle Coordinates:\n");
  	for(int i = 0; i<6; i++)
  		scanf("%d%*c",  &tri_cord[i]);
  		
	tri_cord[6] = tri_cord[0];
	tri_cord[7] = tri_cord[1];

  	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
 	setcolor(BLUE);
 	drawpoly(4, tri_cord);
 	reflect_triangle(tri_cord);
 	setcolor(CYAN);
 	drawpoly(4, tri_cord);	
 	getch();
 	closegraph();
 	return 0;
 }
