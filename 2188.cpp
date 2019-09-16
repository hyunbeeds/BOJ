#include <cstdio>
#include <vector>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

int n, m;
vector<int> arr[201];
int visited[201];
int connect[201];

int dfs(int cur) {
	if (visited[cur]==1) return 0;
	visited[cur] = 1;
	for (int i = 0;i < arr[cur].size();i++) {
		int next = arr[cur][i];
		if (!connect[next] || dfs(connect[next])) {
			//지금 연결이 안되어있거나, 이미 매칭된 점이 다른 대체제가 있는 경우
			//연결할수 있는 것이므로
			//연결하고 1을 return 한다.
			connect[next] = cur;
			return 1;
		}
	}
	return 0;
}
int main() {
	scanf("%d%d", &n, &m);
	int num, temp;
	for (int i = 1;i <= n;i++){
		scanf("%d", &num);
		while (num--) {
			scanf("%d", &temp);
			arr[i].push_back(temp);
		}
	}
	int ret = 0;
	for (int i = 1;i <= n;i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i)) ret++;
	}
	printf("%d", ret);
}