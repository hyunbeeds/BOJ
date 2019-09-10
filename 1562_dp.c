#include <stdio.h>
#pragma warning(disable:4996)
long long dp[101][10][1024];

int main() {
	int n;
	long long answer = 0;
		//dp[m][x][information] m의 길이를 가진 수가 x로 시작할때, 정보
	scanf("%d", &n);
	for (int i = 0;i < 101;i++) {
		for (int j = 0;j < 10;j++) {
			for (int k = 0;k < 1024;k++) {
				dp[i][j][k] = 0;
			}
		}
	}

	dp[1][0][1<<0] = 1;
	dp[1][1][1<<1] = 1;
	dp[1][2][1<<2] = 1;
	dp[1][3][1<<3] = 1;
	dp[1][4][1<<4] = 1;
	dp[1][5][1<<5] = 1;
	dp[1][6][1<<6] = 1;
	dp[1][7][1<<7] = 1;
	dp[1][8][1<<8] = 1;
	dp[1][9][1<<9] = 1;
	for (int i = 1;i <= n - 1;i++) {
		for (int j = 0;j <= 9;j++) {
			for (int bit = 0;bit < 1 << 10;bit++) {
				if(j-1>=0)
				dp[i + 1][j][bit|1<<j] += dp[i][j - 1][bit];
				if(j+1<=9)
				dp[i + 1][j][bit|1<<j] += dp[i][j + 1][bit];
				dp[i+1][j][bit]%=1000000000;
			}
		}
	}
	for (int i = 1;i <= 9;i++) {
		answer = (answer + dp[n][i][1023]) % 1000000000;
	}
	printf("%lld\n",answer);
}
/*				
#include <stdio.h>
#define MOD 1000000000
int N, ans, dp[100][10][4], i, n, d, v;
int main() {
	scanf("%d", &N);
	for (i = 1; i <= 9; i++)
		dp[0][i][2 * (i == 9)] = 1;
	for (n = 0; n< N - 1; n++)
		for (d = 0; d <= 9; d++)
			for (v = 0; v <= 3; v++) {
				if (d - 1 >= 0)
					(dp[n + 1][d - 1][v | (d == 1)] += dp[n][d][v]) %= MOD;
				if (d + 1 <= 9)
					(dp[n + 1][d + 1][v | 2 * (d == 8)] += dp[n][d][v]) %= MOD;
			}
	for (d = 0; d <= 9; d++)
		ans = (ans + dp[N - 1][d][3]) % MOD;
	printf("%d", ans);
}*/