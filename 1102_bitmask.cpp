#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)
#define MAX 987654321

using namespace std;

int cost[17][17];
int n, p;
int dp[1 << 16] = { 0, };
int start = 0;
bool answer = false;
//마지막 방문한게 i일때 status
int tsp(int status, int cnt) {
	if (cnt>=p) {		//모두 방문한 경우
		answer = true;
		return 0;
	}
	if (dp[status] != MAX) return dp[status];

	dp[status] = MAX;
	for (int cur = 0; cur < n; cur++) {
		if (status & (1 << cur)) {	//현재 발전소가 켜져있으면
			for (int next = 0; next < n; next++) {
				if (status & (1 << next)) continue;
				else {	//다음 발전소가 안켜져 있으면
					dp[status] = min(dp[status], tsp(status | (1 << next), cnt + 1) + cost[cur][next]);
				}
			}
		}
		else continue;
	}
	return dp[status];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	char s[20];
	int status = 0;
	int cnt = 0;
	scanf("%s", s);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'Y') {
			status += (1 << i);
			cnt++;
		}
	}
	scanf("%d", &p);
	if (cnt >= p)printf("0\n");
	else {
		for (int i = 0; i < (1 << n); i++) {
			dp[i] = MAX;
		}
		int temp = tsp(status, cnt);
		if (answer == true) {
			printf("%d\n", temp);
		}
		else {
			printf("-1\n");
		}
	}
}

