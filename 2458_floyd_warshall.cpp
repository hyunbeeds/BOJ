#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int arr[501][501] = { 0, };
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = 10000;
		}
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}

	//floyd warshall 알고리즘을 통해 거리를 구하고
	//(나를 제외한 정점->나), (나->나를제외한 정점)의 거리가 있는 것들의
	//개수가 정점수-1이면 나의 순위를 알수 있는 것이다.
	//아니면 모르는것!

	for (int k = 1; k <= n; k++) {
		// k-> 경유점
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// i->시작점, j도착점
				if (i == k || j == k) continue;
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	int cnt;
	int ans = 0;
	for (int k = 1; k <= n; k++) {
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (arr[k][i] >= 1 && arr[k][i] < 10000) cnt++;
			if (arr[i][k] >= 1 && arr[i][k] < 10000) cnt++;
		}
		if (cnt == n - 1) ans++;
	}
	printf("%d\n", ans);
}