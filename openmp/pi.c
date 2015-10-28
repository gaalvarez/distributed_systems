#include <stdio.h>
#include <omp.h>

static long num_steps = 1000000000;

double step;

void main() {
	int i; 
	double x, pi;
	double sum = 0.0;
	step = 1.0/(double) num_steps;
	#pragma omp parallel for shared(step) private(x) reduction(+:sum)
	for (i = 0; i < num_steps; i++) {
		x = (i + 0.5)*step;
		sum = sum + 4.0/(1.0 + x*x);
	}

	pi = step * sum;
	printf("pi [%lf] step [%lf] sum[%lf]\n", pi, step,sum);
}
