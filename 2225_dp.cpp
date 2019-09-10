#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
long long int dp[201][201] = { 0, };	//j개의 정수를 통해 i를 만들수 있는 경우의수
int n, k;
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++) {
		dp[i][1] = 1;
	}
	for (int i = 2; i <= k; i++) {
		long long int sum = 0;
		for (int j = 0; j <= n; j++) {
			sum += dp[j][i - 1];
			dp[j][i] = sum%1000000000;
		}
	}
	printf("%lld\n", dp[n][k]%1000000000);
}