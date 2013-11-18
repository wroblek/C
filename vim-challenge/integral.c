#include <stdio.h>

double simpson(float a, float b, float (*f) (float), float dx) {
	double value_of_interval_integral =
		0.5 * (f(a) + f(b)) / dx;
	return value_of_interval_integral;
}
double integral(float a, float b, float (*f) (float), int n) {
	int i;
	double dx = (b - a) / n;
	double value_of_integral = 0.0;

	for (i=0; i<n; i++) {
		double subinterval_a = a + (i)*dx;
		double subinterval_b = a + (i+1)*dx;
		value_of_integral += simpson(subinterval_a, subinterval_b, f, dx);
	}

	return value_of_integral;
}

double square(float x) {
	return x*x;
}


int main(int argc, char** argv) {
	double twopi = 2 * 3.14;
	double integral_of_f = integral(0.0, 1.0, square, 1e3);
	/*double integral_of_sin = integral(0.0, twopi, sin, 10);*/
	printf("Całka z funkjci f (0.0 - 1.0) = %g\n", integral_of_f);
	/*printf("Całka z sinus (0 - 2pi) = %g\n", integral_of_sin);*/
	return 0;
}
