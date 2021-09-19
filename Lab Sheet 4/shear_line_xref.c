/* Write a program to perform y-shear on a square w.r.t a line x=xref. (Read Square 
  * coordinates, reference line and shear factor from the user. Draw both original and 
  * sheared squares in two different colors)
  */
  
#include<graphics.h>
  
void mat_mul(int m[3][3], int p[3], int pd[3]){
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			pd[i] += m[i][j]*p[j];
		}
	}
}

void shear_line_xref(int sc[], int shy, int xref){
	//Shearing Matrix
	int S[3][3] = {{1, 0, 0}, {shy, 1, -shy*xref}, {0 , 0, 1}};
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
	int sq_cord[10], shy, xref;

  	printf("Enter Square Coordinates:\n");
  	for(int i = 0; i<8; i++)
  		scanf("%d%*c",  &sq_cord[i]);
  		
	sq_cord[8] = sq_cord[0];
	sq_cord[9] = sq_cord[1];
	
  	printf("Enter value of shear factor - shy: ");
  	scanf("%d", &shy);
  	
  	printf("Enter value for xref: ");
  	scanf("%d", &xref);
  	
  	initgraph(&gd, &gm, NULL);
  	setbkcolor(WHITE);
  	setcolor(GREEN);
  	drawpoly(5, sq_cord); //original triangle
    shear_line_xref(sq_cord, shy, xref);
  	setcolor(LIGHTBLUE);
  	drawpoly(5, sq_cord); 	
	getch();
	closegraph();
	return 0;
}
