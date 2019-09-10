#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int n, m;
int arr[1005][1005] = { 0, };
int dp[1005][1005] = { 0, };

int main() {
	char str[1005];
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", str);
		for (int j = 1; j <= m; j++) {
			arr[i][j] = str[j - 1] - '0';
			if (arr[i][j] == 1) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = 0;
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 1) {
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
				if (max < dp[i][j]) {
					max = dp[i][j];
				}
			}
		}
	}
	printf("%d\n", max*max);
}