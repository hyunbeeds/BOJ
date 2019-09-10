#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int arr[3][100001];
int dp[100001][3] = { 0, };	//i¹øÂ° ¿­, 0-> ¾È¶À, 1-> À§¿¡¶À 2-> ¾Æ·¡¶À
int t;
int n;
int main() {
	scanf("%d", &t);
	for (int test = 0; test < t; test++) {
		scanf("%d", &n);
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		dp[1][0] = 0;
		dp[1][1] = arr[1][1];
		dp[1][2] = arr[2][1];
		for (int i = 2; i <= n; i++) {
			dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
			dp[i][1] = max(dp[i - 1][2],dp[i-1][0]) + arr[1][i];
			dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + arr[2][i];
			//printf("%d : %d %d %d\n", i, dp[i][0], dp[i][1], dp[i][2]);
		}

		printf("%d\n", max(max(dp[n][0], dp[n][1]), dp[n][2]));
	}
}