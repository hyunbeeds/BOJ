#include <cstdio>
#pragma warning(disable:4996)
using namespace std;

#define MAX 987654321

int color[201];
int dp[201][201];
// i~j까지 똑같은 색으로 만드는데 바꾸는 횟수 최소
int change(int start, int end) {
	if (start == end) return 0;
	if (dp[start][end] != MAX) return dp[start][end];

	int min = MAX;
	int temp = 0;
	for (int i = start; i < end; i++) {
		if(color[start]==color[i+1])
			temp = change(start, i) + change(i + 1, end);
		else
			temp = change(start, i) + change(i + 1, end) + 1;
		if (temp < min) min = temp;
	}
	dp[start][end] = min;
	return min;
}
int n, m;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &color[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) dp[i][j] = MAX;
	}

	printf("%d\n", change(1, n));
}