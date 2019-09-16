#include <cstdio>
#pragma warning(disable:4996)

int arr[301][301] = { 0, };
int dp[301][301] = { 0, };
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			scanf("%d", &arr[i][j]);
			dp[i][j] = 1000000;
		}
	}
	dp[1][1] = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			int next_i, next_j;
			for (int z = 1;z <= arr[i][j];z++) {
				next_i = i + z;
				if (next_i > n)break;
				else {
					if(dp[next_i][j]>(dp[i][j]+1))
					dp[next_i][j] = dp[i][j] + 1;
				}
			}
			for (int z = 1;z <= arr[i][j];z++) {
				next_j = j + z;
				if (next_j > m)break;
				else {
					if (dp[i][next_j] > (dp[i][j] + 1))
						dp[i][next_j] = dp[i][j] + 1;
				}
			}
		}
	}
	printf("%d\n", dp[n][m]);
}