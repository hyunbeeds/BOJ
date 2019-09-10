#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int dp[201][201] = { 0, };

void character(int n, int m, int order){	//
	if (n == 0 || m==0) {
		for (int i = 0; i < n; i++) {
			printf("a");
		}
		for (int i = 0; i < m; i++) {
			printf("z");
		}
		return;
	}
	if (dp[n+m-1][m] >= order) {
		printf("a");
		character(n-1, m, order);
	}
	else {
		printf("z");
		character(n, m-1, order-dp[n+m-1][m]);
	}

}
int main() {
	int n, m, k;
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 200; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			dp[i][j] = min(dp[i - 1][j - 1] + dp[i - 1][j], (int)1e9);
			//k 가 10^9보다 작게 들어온다고 했으므로 이것이 들어가줘야됨.
		}
	}
	scanf("%d%d%d", &n, &m,&k);
	
	if (k > dp[n + m][n]) printf("-1");
	else character(n, m, k);
	printf("\n");
}