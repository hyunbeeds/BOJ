#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#pragma warning(disable:4996)

using namespace std;
int n, m;
vector<int> indegree;
vector<pair<int,int> > edge[501];
vector<int> costs;
int main() {
	
	scanf("%d", &n);
	int temp;
	int cost;
	indegree = vector<int>(n + 1, 0);
	vector<int> building;	

	for (int i = 1; i <= n; i++) {
		scanf("%d", &cost);
		while (1) {
			scanf("%d", &temp);
			if (temp == -1) break;
			building.push_back(temp);
		}
		if (building.size() == 0) {// 선행노드 없음 0노드랑 연결
			edge[0].push_back(make_pair(i, cost));
			indegree[i]++;
		}
		else {
			for (int j = 0; j < building.size(); j++) {
				edge[building[j]].push_back(make_pair(i,cost));
				indegree[i]++;
			}
		}
		building.clear();
	}
	costs = vector<int>(n + 1, 0);


	
	
	//topological sort
	
	int a, b;

	queue<int> queue;
	queue.push(0);
	int k;
	while (!queue.empty()) {
		k = queue.front();
		queue.pop();
		for (int i = 0; i < edge[k].size(); i++) {
			indegree[edge[k][i].first]--;
			costs[edge[k][i].first] = max(costs[edge[k][i].first], costs[k] + edge[k][i].second);
			if (indegree[edge[k][i].first] == 0) queue.push(edge[k][i].first);
		}
	}
	for (int i = 1; i <=n; i++) {
		printf("%d\n", costs[i]);
	}
}
