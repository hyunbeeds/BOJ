#include <cstdio>
#pragma warning(disable:4996)

int main() {
	int n;
	scanf("%d", &n);
	int cnt = 0;
	while (n != 0) {
		if (n % 2 == 1) cnt++;
		n = n >> 1;
	}
	printf("%d\n", cnt);
}