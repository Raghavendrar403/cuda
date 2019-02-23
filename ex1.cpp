#include<iostream>
#include<cmath>

__global__
void add(int n, float *x, float *y) {
	for(int i = 0; i<n; i++) { 
		y[i] = x[i] + y[i];	
	}
}

int main() {
	int N = 1<<20; // 1M elements

	float *x = new float[N];
	float *y = new float[N];

	for(int i = 0; i<N; i++) {
		y[i] = 1.0f;
		x[i] = 2.0f;
	}

	add(N, x, y);

	float maxErr = 3.0f;

	for(int i = 0; i<N; i++) {
		maxErr = fmax(maxErr, fabs(y[i]-3.0f));	
	}

	std::cout<<"MAX ERROR: "<<maxErr<<std::endl;

	delete[] x;
	delete[] y;

	return 0;
}
