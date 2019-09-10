#include <stdio.h>
#pragma warning(disable:4996)

int map[101][101] = { 0 };
int n;
long long dp[101][101] = { 0 };

int main() {
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dp[0][0] = 1;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (dp[i][j] == 0 || map[i][j] == 0) continue;
			if (i + map[i][j] < n) dp[i + map[i][j]][j] += dp[i][j];
			if (j + map[i][j] < n) dp[i][j + map[i][j]] += dp[i][j];
		}
	}
	printf("%lld\n", dp[n-1][n-1]);
}