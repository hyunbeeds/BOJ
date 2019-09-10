#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>
#pragma warning(disable:4996)

using namespace std;


vector<int> visited;		//방문순서저장하는 vector
vector<int> edge[10001];
vector<int> ans;
int n, m;
int start;
int cnt = 1;

int dfs(int cur, bool root) {
	int child = 0;
	int ret = cnt;
	visited[cur] = cnt;
	cnt++;
	for (int i = 0; i < edge[cur].size(); i++) {
		int next = edge[cur][i];
		if (visited[next] == 0) {
			//처음 방문되는 곳
			child++;
			int temp = dfs(next, false);
			if (root == false && temp >= visited[cur]) {	//자식들중에서 하나라도 나보다 order가 작은 것을 방문할 수 없으면. 단절점이다
				if (ans[cur] == 0) {
					ans[cur] = 1;
					ans[0]++;
				}
			}
			ret = min(ret, temp);
		}
		else {
			//방문된적이 있는 곳
			ret = min(ret, visited[next]);
		}
	}
	if (root == true && child >= 2 && ans[cur]==0) {
		ans[cur] = 1;
		ans[0]++;
	}
	return ret;
}

int main() {
	int a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	start = a;
	visited = vector<int>(n + 1, 0);
	ans = vector<int>(n + 1, 0);
	for (int i = 1; i <= n; i++) {	// 무조건 다연결된 그래프만 들어오는게 아니므로
									// 분리된것도 확인해봐야하기때문에 이렇게 진행
		if (visited[i] == 0) dfs(i, true);
	}
	
	printf("%d\n", ans[0]);
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 1) {
			printf("%d ", i);
		}
	}
}