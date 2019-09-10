#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;
int n;
int arr[501][501] = { 0,};
int dp[501][501] = { 0, };
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dp[1][1] = arr[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}
	int max=0;
	for (int i = 1; i <= n; i++) {
		if (max < dp[n][i]) {
			max = dp[n][i];
		}
	}
	printf("%d\n", max);
}