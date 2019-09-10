#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>
#pragma warning(disable:4996)

using namespace std;


vector<int> visited;		//�湮���������ϴ� vector
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
			//ó�� �湮�Ǵ� ��
			child++;
			int temp = dfs(next, false);
			if (root == false && temp >= visited[cur]) {	//�ڽĵ��߿��� �ϳ��� ������ order�� ���� ���� �湮�� �� ������. �������̴�
				if (ans[cur] == 0) {
					ans[cur] = 1;
					ans[0]++;
				}
			}
			ret = min(ret, temp);
		}
		else {
			//�湮������ �ִ� ��
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
	for (int i = 1; i <= n; i++) {	// ������ �ٿ���� �׷����� �����°� �ƴϹǷ�
									// �и��Ȱ͵� Ȯ���غ����ϱ⶧���� �̷��� ����
		if (visited[i] == 0) dfs(i, true);
	}
	
	printf("%d\n", ans[0]);
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 1) {
			printf("%d ", i);
		}
	}
}