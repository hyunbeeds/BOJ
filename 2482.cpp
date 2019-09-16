#include <cstdio>
#pragma warning(disable:4996)
#define mod 1000000003
int dp[1001][1001];

int n, k;
int main() {
	scanf("%d", &n);
	scanf("%d", &k);
	//���� �������� ������ �غ���
	//0�� ���� ���� ��찡 �ϳ���, 1�����°��� ��찡 n���̴�.
	dp[0][0] = 1;
	for (int i = 1;i <= n;i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	// dp[n][k]=dp[n-1][k]+dp[n-2][k-1];
	// ù��°�� �Ȼ̴� ��� + ù��°�� �̴°�� 
	for (int i = 2;i <= n;i++) {
		for (int j = 2;j <= k;j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1])%mod;
		}
	}
	//���� ���� ������ �����ϸ� ��ù��°�� �Ȱ��� ��� + ���°��->�翷�ǲ� �����ؾߵǹǷ� 3����
	printf("%d ", (dp[n - 1][k] + dp[n - 3][k - 1]) % mod);
}