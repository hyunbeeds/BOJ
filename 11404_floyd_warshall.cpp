/*#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <limits>
#pragma warning(disable:4996)
#define inf 100000000
using namespace std;

int dp[101][101];

int n, m;
int a, b, c;
int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)dp[i][j] = 0;
			else dp[i][j] = inf;
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		dp[a][b] = min(dp[a][b], c);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j]=min(dp[i][k] + dp[k][j], dp[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == inf) {
				printf("0 ");
			}
			else {
				printf("%d ", dp[i][j]);
			}
		}printf("\n");
	}
}*/