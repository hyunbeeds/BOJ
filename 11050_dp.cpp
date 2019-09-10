#include <cstdio>
#pragma warning(disable:4996)

int n, k;
int dp[1001][1001];

int main() {
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 1000; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			dp[i][j] = ((dp[i - 1][j - 1]%10007) + (dp[i-1][j]%10007))%10007;
		}
	}
	scanf("%d %d", &n, &k);
	printf("%d\n", dp[n][k]);
}