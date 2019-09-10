#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)
#define MAX 987654321

using namespace std;

int cost[17][17];
int n;
int dp[17][1 << 16] = { 0, };
int start = 0;
//마지막 방문한게 i일때 status
int tsp(int current, int status) {
	if (status == ((1 << n) - 1)) {		//모두 방문한 경우
		if (cost[current][0] != 0)
			return cost[current][0];
		else
			return MAX;
	}
	if (dp[current][status] != 0) return dp[current][status];

	dp[current][status] = MAX;
	for (int next = 0; next < n; next++) {
		if ((status & (1<<next))>0) continue;		//i번째 도시 방문한경우
		else if (cost[current][next]==0) {					//현재와 같은경우
			continue;
		}
		else {
			dp[current][status]=min(dp[current][status], (tsp(next, status | (1 << next))+cost[current][next]));
		}
	}
	return dp[current][status];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	int temp;

	printf("%d\n", tsp(0,1));
}
