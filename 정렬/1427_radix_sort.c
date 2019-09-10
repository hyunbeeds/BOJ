#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

char num[11];
int num_len;
int radix[10] = { 0 };

int main() {
	scanf("%s", num);
	num_len = strlen(num);
	for (int i = 0;i < num_len;i++) {
		int temp = (int)num[i]-48;
		radix[temp]++;
	}
	for (int i = 9;i >= 0;i--) {
		for (int j = radix[i];j > 0;j--) {
			printf("%d", i);
		}
	}
	printf("\n");
}