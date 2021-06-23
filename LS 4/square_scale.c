/* Write a program to scale a square. (Read Square coordinates and scaling vector 
  * from the user. Draw both original and scaled squares in two different colors)
  */
#include<graphics.h>
  
void mat_mul(int m[3][3], int p[3], int pd[3]){
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			pd[i] += m[i][j]*p[j];
		}
	}
}

void scale(int sc[], int sx, int sy){
	//Scaling Matrix
	int S[3][3] = {{sx, 0, 0}, {0, sy, 0}, {0 , 0, 1}};
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
	int sq_cord[10], sx, sy;

  	printf("Enter Square Coordinates:\n");
  	for(int i = 0; i<8; i++)
  		scanf("%d%*c",  &sq_cord[i]);
  		
	sq_cord[8] = sq_cord[0];
	sq_cord[9] = sq_cord[1];
	
  	printf("Enter sx: ");
  	scanf("%d", &sx);
   	printf("Enter sy: ");
  	scanf("%d", &sy);
  	
  	initgraph(&gd, &gm, NULL);
  	drawpoly(5, sq_cord); //original triangle
  	scale(sq_cord, sx, sy);
  	setcolor(GREEN);
  	drawpoly(5, sq_cord); //trnaslated triangle  	
	getch();
	closegraph();
	return 0;
}
