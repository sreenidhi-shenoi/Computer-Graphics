/* Write a program to translate a triangle. (Read Triangle coordinates and translation 
  * vector from the user. Draw both original and translated triangles in two different 
  * colors)
  */
#include<graphics.h>
void mat_mul(int m[3][3], int p[3], int pd[3]){
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			pd[i] += m[i][j]*p[j];
		}
	}
}

void translate(int tc[], int tx, int ty){
	//Translation Matrix
	int T[3][3] = {{1, 0, tx}, {0, 1, ty}, {0 , 0, 1}};
	int pd[3] = {0, 0, 0};
	//p' = T . P;
	for(int i = 0; i<7; i+=2){
		int p[] = {tc[i], tc[i+1], 1};
		mat_mul(T, p, pd);
		tc[i] = pd[0];
		tc[i+1] = pd[1];
		pd[0] = pd[1] = 0;
	}
}
  
int main(){
	int gd = DETECT, gm;
  	int tri_cord [8], tx, ty;
  	
  	printf("Enter Triangle Coordinates:\n");
  	for(int i = 0; i<6; i++)
  		scanf("%d%*c",  &tri_cord[i]);
  		
	tri_cord[6] = tri_cord[0];
	tri_cord[7] = tri_cord[1];
	
  	printf("Enter tx: ");
  	scanf("%d", &tx);
   	printf("Enter ty: ");
  	scanf("%d", &ty);
	
  	initgraph(&gd, &gm, NULL);
  	setcolor(BLUE);
  	drawpoly(4, tri_cord); //original triangle
  	translate(tri_cord, tx, ty);
  	setcolor(MAGENTA);
  	drawpoly(4, tri_cord); //trnaslated triangle  	
  	getch();
  	closegraph();
}
