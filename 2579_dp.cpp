#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;
int dp[301][3] = { 0, };
//dp[i][0] = ������ 0ĭ �������� �ö���� �� ����ĭ�� ��ĭ�پ �Դٴ� ��
//dp[i][1] = ������ ��ĭ �������� �ö�� -->����ĭ�� ��ĭ���ο�

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