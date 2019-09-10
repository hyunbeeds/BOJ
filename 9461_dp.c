#include <stdio.h>
#pragma warning(disable:4996)
long long ar[101];
int n, T;
int main() {
	ar[1] = 1;
	ar[2] = 1;
	ar[3] = 1;
	ar[4] = 2;
	ar[5] = 2;
	for (int i = 6;i <= 100;i++) {
			ar[i] = ar[i - 1] + ar[i - 5];
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		printf("%lld\n", ar[n]);
	}
}