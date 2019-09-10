#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int n;
int color[1001][3];
int dp[1001][3];	//0->지금을 0으로 칠했을때 최소
					//1->지금을 1으로 칠했을때 최소
					//2->지금을 2로 칠했을때 최소
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &color[i][0], &color[i][1], &color[i][2]);
	}
	dp[1][0] = color[1][0];
	dp[1][1] = color[1][1];
	dp[1][2] = color[1][2];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
	}
	printf("%d\n", min(dp[n][2], min(dp[n][0], dp[n][1])));
}