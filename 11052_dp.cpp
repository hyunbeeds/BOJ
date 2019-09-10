#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int n;
int card[1001] = { 0, };
int dp[1001] = { 0, };	//카드 j개 샀을때 최대값

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &card[i]);
	}
	int max;
	int sum;
	dp[0] = 0;
	dp[1] = card[1];
	for (int i = 2; i <= n; i++) {
		max = 0;
		for (int j = 0; j < i; j++) {
			sum=dp[j] + card[i - j];
			if (sum > max) max= sum;
		}
		dp[i] = max;
	}
	printf("%d\n", dp[n]);
}