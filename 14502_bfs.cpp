#include <stdio.h>
#include <algorithm>
#include <queue>

#pragma warning(disable:4996)


using namespace std;
int map[8][8] = { 0, };
int n, m;
int result = 0;
int dx[] = { -1,0,+1,0 };
int dy[] = { 0,+1,0,-1 };

void dfs(int count) {
	if (count == 3) {
		//이제 virus 퍼지는거 할차례
		int copy[8][8] = { 0, };
		int visited[8][8] = { 0, };
		queue<pair<int, int> > q;

		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (map[i][j] == 2) {
					q.push(make_pair(i, j));
					visited[i][j] = 1;
				}
				copy[i][j] = map[i][j];
			}
		}

		while (!q.empty()) {
			pair<int, int> virus = q.front();
			q.pop();
			for (int i = 0;i < 4;i++) {
				pair<int, int> next;
				next.first = virus.first + dx[i];
				next.second = virus.second + dy[i];
				if (next.first < 0 || next.first >= n || next.second<0 || next.second>=m) {
					continue;
				}
				else {
					if (copy[next.first][next.second] == 0 && visited[next.first][next.second] == 0) {
						visited[next.first][next.second] = 1;
						q.push(next);
						copy[next.first][next.second] = 1;
					}
				}
 			}

		}


		int ret=0;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (copy[i][j] == 0) ret++;
			}
		}
		if (ret > result) result = ret;
		return;
	}
	else {
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (map[i][j] == 0) {
					map[i][j] = 1;
					dfs(count + 1);
					map[i][j] = 0;
				}
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0);
	printf("%d", result);
	
	
}