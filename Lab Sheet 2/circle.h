int point_calculation(int p, int x[], int y[]){
	//calculating subsequent points
	int k = 0;
	while(x[k] <= y[k]) {
		k+=1;
		if(p < 0){
			x[k] = x[k-1] + 1;
			y[k] = y[k-1];
		    p = p + (2*x[k-1]) + 3;	
		}
		else{ //p >= 0
			x[k] = x[k-1] + 1;
			y[k] = y[k-1] - 1;
		    p = p + ((2*x[k-1])-(2*y[k-1])) + 5;
		}
	}
	return k;
}
