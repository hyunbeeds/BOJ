#include <stdio.h>
#pragma warning(disable:4996)

int one = 0;
int zero = 0;

int fibonacci(int n) {
	if (n == 0) {
		zero++;
		return 0;
	}
	else if (n == 1) {
		one++;
		return 1;
	}
	else {
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

int main() {
	int num,i;
	scanf("%d", &num);
	fflush(stdin);
	for (i = 0;i < num;i++) {
		int tmp;
		one = 0;
		zero = 0;
		scanf("%d", &tmp);
		fibonacci(tmp);
		printf("%d %d\n", zero, one);
	}
	return 0;

}