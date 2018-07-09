#include <iostream>
#include <cmath>

/* 
2022번 
사다리
*/
using namespace std;

double min(double x, double y) {
	if (x < y) {
		return x;
	}
	return y;
}

int main(void) {
	double x, y, c;

	while (scanf("%lf %lf %lf", &x, &y, &c) == 3) {
		double left = 0;
		double right = min(x, y);

		while (abs(right - left) > 1e-6) {
			double mid = (left + right) / 2.0;
			double d = mid;
			double h1 = sqrt(x*x - d * d);
			double h2 = sqrt(y*y - d * d);
			double h = (h1*h2) / (h1 + h2);

			if (h > c) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		printf("%.31f\n", left);
	}

	return 0;
}