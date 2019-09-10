#include <cstdio>
#define M_PI 3.14159265358979323846
#pragma warning(disable:4996)

double r;

int main() {
	scanf("%lf", &r);
	printf("%lf\n%lf", M_PI*r*r, r*r*2);
}