#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int n, m;
int arr[100001];
int dp[100001] = { 0, };
int main() {
	scanf("%d %d",&n, &m);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		dp[i] = sum;
	}
	//dp[i]에 i번째 수까지의 합을 해놨다.
	//i-j의 합은 dp[j]-dp[i-1];
	int start, fin;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &start, &fin);
		printf("%d\n", dp[fin] - dp[start - 1]);
	}
}