#include <cstdio>
#pragma warning(disable:4996)
using namespace std;

int h, w, n;
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
int arr[1002][1002] = { 0, };
int dp[1002][1002] = { 0, };
int main() {
	scanf("%d %d %d", &h, &w, &n);
	//(i,j) -> i==h+1 or j==w+1되면 종료
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	//dp[1][1][0]+dp[1][1][1]=n;
	dp[1][1] = n-1;

	for (int i = 1; i <= h; i++) {	//아래로 가자
		for (int j = 1; j <= w; j++) {
			if (dp[i][j]%2 == 0) {	//2로 나누어떨어짐
				dp[i][j + 1] += dp[i][j] / 2;
				dp[i + 1][j] += dp[i][j] / 2;
			}
			else {	//2로 안떨어짐
				if (arr[i][j] == 1) {	//오른쪽으로 가는경우
					dp[i][j + 1] += dp[i][j] / 2 + 1;
					dp[i + 1][j] += dp[i][j] / 2;
				}
				else {	//아래로 가는경우
					dp[i][j + 1] += dp[i][j] / 2;
					dp[i + 1][j] += dp[i][j] / 2 + 1;
				}
			}
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (dp[i][j] % 2 == 0)
				continue;
			else
				arr[i][j]= (!arr[i][j]);
		}
	}
	int cur_i=1;
	int cur_j=1;
	while (cur_i != h + 1 && cur_j != w + 1) {
		if (arr[cur_i][cur_j] == 1) {
			cur_j++;
		}
		else {
			cur_i++;
		}
	}
	printf("%d %d\n", cur_i, cur_j);
}
