/* Write a program to rotate a triangle counter clockwise w.r.t a fixed point. (Read
   * triangle coordinates, rotating angle and fixed point from the user. Draw both 
   * original and rotated triangles in two different colors). (Remember: Convert angle 
   * from degree to radian before calculating cosine and sine values. Formula radian =
   * degree * pi/180)
   */
#include<graphics.h>
#include<math.h>

void mat_mul(float m[][3], int p[], int pd[]){
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			pd[i] += m[i][j]*p[j];
		}
	}
}

void rotate_c_fixed_point(int tc[], int theta, int xf, int yf) {
	float radian = theta * M_PI / 180;
	float cosine = cos(radian);
	float sine = sin(radian);
	
	float R[][3] = { { cosine , sine , (xf*(1-cosine) - (yf*sine)) },
						    { -sine, cosine , (yf*(1-cosine) + (xf*sine)) },
						 	{ 0 , 0 , 1 }
					   };
	
	int pd[3] = {0, 0, 0};
	
	for(int i = 0; i<7; i+=2){
		int p[] = {tc[i], tc[i+1], 1};
		mat_mul(R, p, pd);
		tc[i] = pd[0];
		tc[i+1] = pd[1];
		pd[0] = pd[1] = 0;
	}
}

int main(){
	int gd = DETECT, gm;
	int tri_cord[8], p;
	int theta, xf, yf;
	
	printf("Enter Triangle Coordinates:\n");
	for(int i = 0; i<6; i++) {
		scanf("%d%*c", &tri_cord[i]);
	}
	
	tri_cord[6] = tri_cord[0];
	tri_cord[7] = tri_cord[1];
	
	printf("Enter theta value: ");
	scanf("%d", &theta);

	printf("Enter fixed point num[1 / 2 / 3]: ");
	scanf("%d", &p);
	
	 xf = tri_cord[p*2-2];
	 yf = tri_cord[p*2-1];

	initgraph(&gd, &gm, NULL);
	setcolor(MAGENTA);
	drawpoly(4, tri_cord);
	rotate_c_fixed_point(tri_cord, theta, xf, yf);
	setcolor(YELLOW);
	drawpoly(4, tri_cord);	
	getch();
	closegraph();
	return 0;
}
