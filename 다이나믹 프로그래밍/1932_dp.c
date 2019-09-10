#include <stdio.h>
#pragma warning(disable:4996)
int dp[501][501];	//dp[i][j]-> i층에 m번째 내려왔을때 최대
int tri[501][501] = { 0 };
int n;						//삼각형 크기
int ans = 0;

int main() {
	scanf("%d", &n);
	for (int i = 0;i <= 500;i++) {
		for (int j = 0;j <= 500;j++) dp[i][j] = -1;
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= i;j++) {
			int temp;
			scanf("%d", &temp);
			tri[i][j] = temp;
		}
	}
	dp[1][1] = tri[1][1];
	for (int i = 2;i <= n;i++) {
		for (int j = 1;j <= i;j++) {
			if (dp[i - 1][j] > dp[i - 1][j - 1])
				dp[i][j] = dp[i - 1][j] + tri[i][j];
			else
				dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
		}
	}
	for (int i = 1;i <= n;i++) {
		if (ans < dp[n][i]) ans = dp[n][i];
	}
	printf("%d\n", ans);
}