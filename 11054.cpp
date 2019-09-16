#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)

int n;
int arr[1001] = { 0, };
int dp[1001][2] = { 0, };
//0->증가하는 중, 수열 개수
//1->감소하는 중, 수열 개수
int main() {
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
	}
	dp[0][0] = 1;
	dp[0][1] = 1;
	int ans = 1;
	for (int i = 1;i < n;i++) {
		int increase_max=0;
		int decrease_max=0;
		for (int j = 0;j < i;j++) {
			if (arr[i] > arr[j]) {	//증가
				if (increase_max < dp[j][0]) {
					increase_max = dp[j][0];
				}
			}
			if (arr[i] < arr[j]) {	//감소
				if (decrease_max < dp[j][1]) {
					decrease_max = dp[j][1];
				}
				if (decrease_max < dp[j][0]) {
					decrease_max = dp[j][0];
				}
			}
		}
		dp[i][0] = increase_max + 1;
		dp[i][1] = decrease_max + 1;
		if (dp[i][0] > ans) ans = dp[i][0];
		if (dp[i][1] > ans) ans = dp[i][1];
	}
	printf("%d\n", ans);
	return 0;
}