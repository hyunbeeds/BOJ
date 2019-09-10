#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

long long int dp[1001][10] = { 0 };	//i자리수, j로 끝나는 오르막수의 수
int n;
int main() {
	scanf("%d", &n);
	for (int j = 0; j <= 9; j++) {
		dp[1][j] = 1;
	}
	long long temp;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = 1;
		temp = dp[i - 1][0];
		for (int j = 1; j <= 9; j++) {
			temp += dp[i-1][j];
			dp[i][j] = temp%10007;
		}
	}
	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += dp[n][i];
	}
	printf("%lld\n", sum%10007);
}