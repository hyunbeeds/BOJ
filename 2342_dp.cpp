#include <cstdio>
#include <algorithm>
#include <cmath>
#pragma warning(disable:4996)
#define MAX 987654321

using namespace std;

int dp[100001][5][5];
// n번시행 후 현재위치 (i,j)일때, 최소 비용
int main() {
	int next;
	int cnt = 1;

	for (int k = 0; k <= 100000; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				dp[k][i][j] = MAX;
			}
		}
	}
	dp[0][0][0] = 0;
	int last = 0;
	while (1) {
		scanf("%d", &next);
		if (next == 0) break;
		for (int cur_x = 0; cur_x < 5; cur_x++) {
			for (int cur_y = 0; cur_y < 5; cur_y++) {
				
				if (dp[cnt - 1][cur_x][cur_y] == MAX) continue;

				// 왼쪽발을 바꿀때
				if (cur_x == 0) {
					dp[cnt][next][cur_y] = min(dp[cnt][next][cur_y], dp[cnt - 1][cur_x][cur_y] + 2);
				}
				else if (cur_x == next) {
					dp[cnt][next][cur_y] = min(dp[cnt][next][cur_y], dp[cnt - 1][cur_x][cur_y] + 1);
				}
				else if (abs(cur_x - next) == 1 || abs(cur_x - next) == 3) {
					//근접해있는 경우 
					dp[cnt][next][cur_y] = min(dp[cnt][next][cur_y], dp[cnt - 1][cur_x][cur_y] + 3);
				}
				else {//반대
					dp[cnt][next][cur_y] = min(dp[cnt][next][cur_y], dp[cnt - 1][cur_x][cur_y] + 4);
				}
				if (next == cur_y) dp[cnt][next][cur_y] = MAX;

				// 오른쪽발을 바꿀때
				if (cur_y == 0) {
					dp[cnt][cur_x][next] = min(dp[cnt][cur_x][next], dp[cnt - 1][cur_x][cur_y] + 2);
				}
				else if (cur_y == next) {
					dp[cnt][cur_x][next] = min(dp[cnt][cur_x][next], dp[cnt - 1][cur_x][cur_y] + 1);
				}
				else if (abs(cur_y - next) == 1 || abs(cur_y- next) == 3) {
					//근접해있는 경우 
					dp[cnt][cur_x][next] = min(dp[cnt][cur_x][next], dp[cnt - 1][cur_x][cur_y] + 3);
				}
				else {
					dp[cnt][cur_x][next] = min(dp[cnt][cur_x][next], dp[cnt - 1][cur_x][cur_y] + 4);
				}
				if (next == cur_x) dp[cnt][cur_x][next] = MAX;

			}
		}
		
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (dp[cnt][i][j] == MAX) printf("MAX ");
				else printf("%3d ", dp[cnt][i][j]);
			}printf("\n");
		}
		printf("\n");
		last = next;
		cnt++;
	}
	cnt = cnt - 1;
	int min = MAX;
	for (int i = 0; i < 5; i++) {
		if (dp[cnt][i][last] < min) min = dp[cnt][i][last];
		if (dp[cnt][last][i] < min) min = dp[cnt][last][i];
	}

	printf("%d\n", min);
}