#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int candy[1001][1001] = { 0, };
int dp[1001][1001] = { 0, };
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &candy[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i][j - 1], max(dp[i - 1][j - 1], dp[i - 1][j])) + candy[i][j];
		}
	}
	printf("%d\n", dp[n][m]);
}