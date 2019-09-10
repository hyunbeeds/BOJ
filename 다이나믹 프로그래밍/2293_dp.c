#include <stdio.h>
#pragma warning(disable:4996)

int dp[10001];		//dp[n]->n원 만드는데 가능한 경우의 수
int coin[101];

int main() {
	int num, price;
	scanf("%d%d", &num, &price);
	for (int i = 0;i < num;i++) {
		scanf("%d", &coin[i]);
	}
	dp[0] = 1;
	for (int i = 0;i < num;i++) {
		for (int j = coin[i];j <= price;j++) {
			dp[j] += dp[j - coin[i]];
		}
	}
	printf("%d\n", dp[price]);
}