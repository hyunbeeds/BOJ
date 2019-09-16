#include <cstdio>
#pragma warning(disable:4996)

int main() {
	int n;
	char temp;
	long long int sum = 0;
	long long int bonus = 0;
	scanf("%d", &n);
	getchar();
	for (int i = 1;i <= n;i++) {
		temp=getchar();
		if (temp == 'O') {
			sum += (i+bonus);
			bonus++;
		}
		else {
			bonus = 0;
		}
	}
	printf("%lld\n", sum);
}
