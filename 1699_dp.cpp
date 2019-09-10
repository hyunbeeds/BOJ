#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int n;
long long int dp[100001];
int main() {
	scanf("%d", &n);
	long long int temp = 0;
	long long int cnt;
	dp[0] = 0;
	for (int i = 1; i <= n; i++) dp[i] = 987654321;
	for (int i = 1; i <= n; i++) {
		for (temp = 1; temp*temp <= i; temp++) {
			if (dp[i] > 1 + dp[i - temp*temp]) {
				dp[i] = 1 + dp[i - temp*temp];
			}
		}
	}
	printf("%lld\n", dp[n]);
}