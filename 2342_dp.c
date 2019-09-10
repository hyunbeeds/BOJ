#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

int dp[100001][5][5];		//dp[x][왼발][오른발]

int main() {
	int n, next, answer,temp;
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++) {
			dp[0][i][j] = 0;
		}
	}
	dp[0][0][0] = 1;
	
	n = 1;
	while (1) {
		scanf("%d", &next);
		if (next == 0) break;
		for (int cur_x = 0;cur_x <= 4;cur_x++) {			//중앙->다른곳 2, 인접한곳 3, 반대 4 , 같은곳 1
			for (int cur_y = 0;cur_y <= 4;cur_y++) {
				if (dp[n - 1][cur_x][cur_y] == 0) continue;
				int left, right;
				if (cur_x == 0) {					//중앙->다른곳
					left = dp[n - 1][cur_x][cur_y] + 2;
				}
				else if (cur_x == next) {			//같은곳
					left = dp[n - 1][cur_x][cur_y] + 1;
				}
				else if (abs(cur_x - next) == 1||abs(cur_x-next)==3) {	//인접
					left = dp[n-1][cur_x][cur_y] + 3;
				}
				else {								//반대
					left = dp[n-1][cur_x][cur_y] + 4;
				}
				if (dp[n][next][cur_y] == 0)		dp[n][next][cur_y] = left;
				else if (dp[n][next][cur_y] > left) dp[n][next][cur_y] = left;

				if (cur_y == 0) {					//중앙->다른곳
					right = dp[n-1][cur_x][cur_y] + 2;
				}
				else if (cur_y == next) {			//같은곳
					right = dp[n-1][cur_x][cur_y] + 1;
				}
				else if (abs(cur_y - next) == 1||abs(cur_y-next)==3) {	//인접
					right = dp[n-1][cur_x][cur_y] + 3;
				}
				else {								//반대
					right = dp[n - 1][cur_x][cur_y] + 4;
				}
				if (dp[n][cur_x][next] == 0)		dp[n][cur_x][next] = right;
				else if (dp[n][cur_x][next] > right) dp[n][cur_x][next] = right;
				temp = next;
			}
		}
		n++;
	}
	answer = 5000000;
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	if (n == 2) {
		printf("2\n");
		return 0;
	}

	n = n - 1;
	for (int i = 1;i <= 4;i++) {
		if (dp[n][i][temp] != 0 && dp[n][i][temp] < answer) {
			answer = dp[n][i][temp];
		}
		if (dp[n][temp][i] != 0 && dp[n][temp][i] < answer) {
			answer = dp[n][temp][i];
		}
	}
	
	printf("%d\n", answer-1);
	return 0;
}