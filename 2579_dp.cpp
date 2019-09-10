#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;
int dp[301][3] = { 0, };
//dp[i][0] = 직전에 0칸 연속으로 올라왔음 즉 여기칸에 두칸뛰어서 왔다는 뜻
//dp[i][1] = 직전에 한칸 연속으로 올라옴 -->여기칸에 한칸으로옴

int arr[301] = { 0, };
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = arr[1];
	dp[1][1] = arr[1];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i - 2][0],dp[i-2][1])+arr[i];
		dp[i][1] = dp[i-1][0] + arr[i];
	}
	printf("%d\n", max(dp[n][0], dp[n][1]));
}