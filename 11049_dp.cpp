#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
#define i_MAX 987654321

using namespace std;

int dp[501][501] = { 0, };	//	i-j±îÁöÀÇ °ö¼ÀÁß ÃÖ¼Ò
pair<int, int> matrix[501];
int n;

int matrix_mul(int start, int end) {
	
	if (start == end) return 0;
	if (dp[start][end] != i_MAX) return dp[start][end];
	int temp;
	for (int i = start; i <= end; i++) {
		temp=matrix_mul(start, i) + matrix_mul(i+1, end) + matrix[start].first*matrix[i].second*matrix[end].second;
		dp[start][end] = min(dp[start][end], temp);
	}
	
	return dp[start][end];
}
int main() {
	scanf("%d", &n);
	int a, b;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a, &b);
		matrix[i] = { a, b };
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = i_MAX;
		}
	}
	printf("%d\n",matrix_mul(1, n));

	return 0;
}