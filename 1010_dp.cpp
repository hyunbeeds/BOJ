#include <cstdio>
#pragma warning(disable:4996)

int n, k,t;
long long int dp[31][31];

int main() {
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 30; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &k);
		printf("%lld\n", dp[k][n]);
	}
}