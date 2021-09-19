/* Write a program to perform x-shear on a square. (Read Square coordinates and 
  * shear factor from the user. Draw both original and sheared squares in two different 
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

void x_shear(int sc[], int shx){
	//Shearing Matrix
	int S[3][3] = {{1, shx, 0}, {0, 1, 0}, {0 , 0, 1}};
	int pd[3] = {0, 0, 0};
	
	//p' = S . P;
	for(int i = 0; i<9; i+=2){
		int p[] = {sc[i], sc[i+1], 1};
		mat_mul(S, p, pd);
		sc[i] = pd[0];
		sc[i+1] = pd[1];
		pd[0] = pd[1] = 0;
	}
}
  
int main(){
	int gd = DETECT, gm;
	int sq_cord[10], shx;

  	printf("Enter Square Coordinates:\n");
  	for(int i = 0; i<8; i++)
  		scanf("%d%*c",  &sq_cord[i]);
  		
	sq_cord[8] = sq_cord[0];
	sq_cord[9] = sq_cord[1];
	
  	printf("Enter value of shear factor - shx: ");
  	scanf("%d", &shx);
  	
  	initgraph(&gd, &gm, NULL);
  	drawpoly(5, sq_cord); //original triangle
  	x_shear(sq_cord, shx);
  	setcolor(GREEN);
  	drawpoly(5, sq_cord); //trnaslated triangle  	
	getch();
	closegraph();
	return 0;
}
