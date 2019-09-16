#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits.h>
#pragma warning(disable:4996)
using namespace std;

int test, n;
pair<double, double> arr[513];
double dp[513][513];
double dist(pair<double, double> a, pair<double, double> b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
double cal(int x, int y) {
	if (x == n - 1 && y == n - 1) return 0.0;
	if (x == n - 1) return dist(arr[y], arr[n - 1]);
	if (y == n - 1) return dist(arr[x], arr[n - 1]);

	if (dp[x][y] != -1.0) return dp[x][y];
	int next = max(x, y) + 1;
	//갈때 다음꺼 들리는 경우
	dp[x][y] = min(1e9, cal(next, y) + dist(arr[x], arr[next]));
	//올때 들리는 경우
	dp[x][y] = min(dp[x][y], cal(x, next) + dist(arr[y], arr[next]));
	return dp[x][y];
}
int main() {
	scanf("%d", &test);
	while (test--) {
		scanf("%d", &n);
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				dp[i][j] = -1.0;
			}
		}
		for (int i = 0;i < n;i++) {
			scanf("%lf%lf", &arr[i].first, &arr[i].second);
		}
		printf("%.3lf\n", cal(0,0));
	}
}