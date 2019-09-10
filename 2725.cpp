#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int n;
int test;
int main() {
	n = 1000;
	vector<vector<int> > point = vector<vector<int> >(n + 1);
	for (int i = 0; i <= n; i++) {
		point[i] = vector<int>(n + 1, 0);
	}

	int dx, dy;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 && j == 0) continue;
			if (point[i][j] == 0) {
				point[i][j] = 1;
				//이제 (0,0)으로 부터 직선 뻗어서 해보자
				dx = i * 2;
				dy = j * 2;
				while (dx <= n && dy <= n) {
					point[dx][dy] = 2;
					dx += i;
					dy += j;
				}
			}
		}
	}

	int cnt[1001] = { 0, };
	cnt[0] = 0;
	
	for (int i = 1; i <= 1000; i++) {
		int count = 0;
		for (int j = 0; j < i; j++) {
			if (point[i][j] == 1) count++;
			if (point[j][i] == 1) count++;
		}
		if (point[i][i] == 1) count++;
		cnt[i] = cnt[i - 1] + count;
	}

	scanf("%d", &test);
	for (int t = 0; t < test; t++) {
		scanf("%d", &n);
		printf("%d\n", cnt[n]);
	}
}