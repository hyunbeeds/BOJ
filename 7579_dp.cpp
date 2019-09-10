/*#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int dp[10100] = { 0, };
//i cost일때 최대 확보가능한 메모리양
int memory[101];
int cost[101];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	//m-> 목표 메모리
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &memory[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);
		sum += cost[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = sum; j >= cost[i]; j--) {
			dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
		}
	}
	for (int i = 0; i <= 20; i++) {
		printf("%d : %d\n", i, dp[i]);
	}

	for (int i = 0; i <= 10000; i++) {
		if (dp[i] >= m) {
			printf("%d\n", i);
			break;
		}
	}
}*/