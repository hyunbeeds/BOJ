#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int n, k, ans;
int card[101];
long long int dp[101][21] = { 0, };	//	i번째 까지 계산했을때, j가 나오는 경우의 수
long long int eq = 0;


int main() {

	scanf("%d", &n);
	n = n - 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &card[i]);
	}
	scanf("%d", &ans);

	dp[1][card[1]] = 1;
	int plus;
	int minus;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 20; j++) {
			plus = j + card[i];
			minus = j - card[i];
			if (plus >= 0 && j + card[i] <= 20) {
				dp[i][plus] += dp[i - 1][j];
			}
			if (minus >= 0 && minus <= 20) {
				dp[i][minus] += dp[i - 1][j];
			}
		}
	}

	printf("%lld\n", dp[n][ans]);
}