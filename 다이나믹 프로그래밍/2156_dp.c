#include <stdio.h>
#pragma warning(disable:4996)

int dp[10001] = { 0 };
int grape[10001] = { 0 };

int max(int x, int y) {
	if (x > y) return x;
	else return y;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		scanf("%d", &grape[i]);
	}
	
	if (n == 1) {
		printf("%d\n", grape[1]);
		return 0;
	}
	else if (n == 2) {
		printf("%d\n", grape[1] + grape[2]);
		return 0;
	}
	dp[0] = 0;
	dp[1] = grape[1];
	dp[2] = grape[1] + grape[2];

	for (int i = 3;i <= n;i++) {
		dp[i] = max(dp[i - 1], max(dp[i - 2] + grape[i],dp[i-3]+grape[i-1]+grape[i]));
	}

	printf("%d\n",max(dp[n-2],max(dp[n],dp[n-1])));
}