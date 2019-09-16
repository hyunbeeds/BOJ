#include <cstdio>
#pragma warning(disable:4996)
#define mod 1000000003
int dp[1001][1001];

int n, k;
int main() {
	scanf("%d", &n);
	scanf("%d", &k);
	//먼저 직선으로 생각을 해보자
	//0개 고르는 것은 경우가 하나고, 1개고르는것은 경우가 n개이다.
	dp[0][0] = 1;
	for (int i = 1;i <= n;i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	// dp[n][k]=dp[n-1][k]+dp[n-2][k-1];
	// 첫번째꺼 안뽑는 경우 + 첫번째꺼 뽑는경우 
	for (int i = 2;i <= n;i++) {
		for (int j = 2;j <= k;j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1])%mod;
		}
	}
	//이제 선을 원으로 연결하면 맨첫번째를 안고르는 경우 + 고르는경우->양옆의꺼 제외해야되므로 3개뺌
	printf("%d ", (dp[n - 1][k] + dp[n - 3][k - 1]) % mod);
}