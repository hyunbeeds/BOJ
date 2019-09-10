#include <stdio.h>
#pragma warning(disable:4996)
#define max(a,b) (a>b)?a:b;
int n,k;
int dp[100001];
int ar[100001];
int ans=-100000000;

int main() {
	scanf("%d", &n);
	for (int i = 0;i < n;i++)scanf("%d", &ar[i]);
	dp[0] = ar[0];
	ans=max(ans, dp[0]);
	for (int i = 1;i < n;i++) {
		dp[i] = ar[i];
		if (dp[i - 1] + dp[i] > dp[i]) {
			dp[i] += dp[i - 1];
			ans = max(ans, dp[i]);
		}
	}
	for (k = 0;k < n;k++) {
		if (ar[k] > 0) break;
	}
	if (k == n) {
		for (int i = 0;i < n;i++) {
			if (ar[i] > ans) ans = ar[i];
		}
	}
	printf("%d\n", ans);
}
