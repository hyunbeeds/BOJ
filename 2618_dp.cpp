#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int n, w;
pair<int, int> work[1005];
int dp[1001][1001];
// 경찰차 1이 일i끝내고, 2가 일 j끝낸 위치에 있다. 이 상태에서 
// 마지막 사건까지 해결하는 동안 이동하는 거리의 최소합

int solve(int x, int y) {
	if (dp[x][y] != -1) {
		return dp[x][y];
	}
	int next = max(x, y) + 1;
	if (next >= w + 2) return 0;

	dp[x][y] = min(solve(next, y) + abs(work[x].first-work[next].first) + abs(work[x].second-work[next].second)
		, solve(x,next) + abs(work[y].first - work[next].first) + abs(work[y].second - work[next].second));
	return dp[x][y];
}

void get(int x, int y) {
	int next = max(x, y) + 1;
	if (next >= w + 2) return;

	if (dp[next][y] == -1) {
		dp[next][y] = 0;
	}
	if (dp[x][next] == -1) {
		dp[x][next] = 0;
	}

	if (dp[x][y] == dp[next][y] + +abs(work[x].first - work[next].first) + abs(work[x].second - work[next].second)) {
		printf("1\n");
		get(next, y);
	}
	else {
		printf("2\n");
		get(x, next);
	}
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	scanf("%d", &w);
	work[0] = make_pair(1,1);
	work[1] = make_pair(n,n);
	int x, y;
	for (int i = 2; i < w+2; i++) {
		scanf("%d %d", &x, &y);
		work[i] = make_pair(x,y);
	}
	printf("%d\n", solve(0, 1));
	get(0, 1);
}