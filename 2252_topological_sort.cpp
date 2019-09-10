#include <cstdio>
#include <vector>
#include <queue>
#pragma warning(disable:4996)

using namespace std;
int n, m;
vector<int> order[32001];
vector<int> indegree;
int main() {
	//topological sort
	scanf("%d %d", &n, &m);
	int a, b;
	indegree = vector<int>(n + 1,0);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		order[a].push_back(b);
		indegree[b]++;
	}
	queue<int> queue;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) queue.push(i);
	}
	vector<int> ans;
	int k;
	while (!queue.empty()) {
		k = queue.front();
		queue.pop();
		ans.push_back(k);
		for (int i = 0; i < order[k].size();i++) {
			indegree[order[k][i]]--;
			if (indegree[order[k][i]] == 0) queue.push(order[k][i]);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ",ans[i]);
	}
}