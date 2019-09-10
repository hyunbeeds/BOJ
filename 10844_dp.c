#include <stdio.h>
#pragma warning(disable:4996)

long long stair[101][10];

int main() {
	int n,result;
	for (int i = 1;i <= 9;i++) {
		stair[1][i] = 1;
	}
	stair[1][0] = 0;
	
	scanf("%d", &n);
	for (int i = 2;i <= n;i++) {
		for (int j = 0;j <= 9;j++) {
			if (j == 0) {
				stair[i][j] = stair[i - 1][1];
			}
			else if (j == 9) {
				stair[i][j] = stair[i - 1][8];
			}
			else stair[i][j] = (stair[i - 1][j - 1] + stair[i - 1][j + 1])%1000000000;
		}
	}
	result = 0;
	for (int i = 0;i <= 9;i++) {
		result = (result + stair[n][i])%1000000000;
	}
	printf("%d\n", result);
}