#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int n, m;
int arr[301][301] = { 0, };
int dp[301][301] = { 0, };

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	//DP[X1][Y1] = (1,1)~(X1,Y1) 까지의 직사각형 넓이
	//(X1,Y1)~(X2,Y2) 의 넓이 = DP[X2][Y2] - DP[X1-1][Y2] - DP[X2][Y1-1] + DP[X1-1][Y1-1]
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = arr[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
		}
	}

	scanf("%d", &m);
	int a, b, c, d;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d\n", dp[c][d] - dp[a - 1][d] - dp[c][b - 1] + dp[a - 1][b - 1]);
	}
}