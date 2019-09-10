#include <stdio.h>
#pragma warning(disable:4996)

int n;
int map[26][26] = { 0 };
int visited[26][26] = { 0 };
int cnt = 0;		//´ÜÁö¼ö
int house[626] = { 0 };

void dfs(int x, int y) {
	if (visited[x][y] == 0 && map[x][y] == 1) {
		visited[x][y] = 1;
		map[x][y] = cnt;
		dfs(x + 1, y);
		dfs(x - 1, y);
		dfs(x, y + 1);
		dfs(x, y - 1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) {
				cnt = cnt + 1;
				dfs(i, j);
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (map[i][j] != 0) {
				house[map[i][j]]++;
			}
		}
	}

	for (int i = 1;i <= cnt;i++) {
		for (int j = 1;j <= cnt-1;j++) {
			if (house[j] > house[j + 1]) {
				int temp;
				temp = house[j];
				house[j] = house[j + 1];
				house[j + 1] = temp;
			}
		}
	}
	printf("%d\n", cnt);
	for (int i = 1;i <= cnt;i++) {
		printf("%d\n",house[i]);
	}
}