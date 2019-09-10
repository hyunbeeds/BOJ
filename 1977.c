#include <stdio.h>
#pragma warning(disable:4996)

int ar[101];

int main() {
	int m, n, min, sum;
	for (int i = 0;i <= 100;i++) {
		ar[100-i] = i*i;
	}
	sum = 0;
	min = 0;

	scanf("%d", &m);
	scanf("%d", &n);
	for (int i = 0;i <= 100;i++) {
		if (ar[i] >= m&&ar[i] <= n) {
			sum = sum + ar[i];
			min = ar[i];
		}
	}
	if (min == 0) {
		printf("-1");
		return 1;
	}
	printf("%d\n%d\n", sum, min);
}