#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

int n, m,k;
int a, b, c;
int i, j;
vector<pair<int, int> > edge[1001];
priority_queue<int, vector<int>, greater<int> > orders[1001];

int main() {
	scanf("%d %d %d", &n, &m,&k);
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back(make_pair(b, c));
	}

	priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	//(cost, vertex번호)들어감
	vector<int> ans = vector<int>(n + 1,50000000);
	ans[1] = 0;
	pq.push(make_pair(0,1));
	pair<int, int> cur;
	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();
		if (orders[cur.second].size() >= k) continue;
		else orders[cur.second].push(cur.first);
		
		for (i = 0; i < edge[cur.second].size(); i++) {
			pq.push(make_pair(edge[cur.second][i].second+cur.first, edge[cur.second][i].first));
		}
		
	}
	for (int i = 1; i <= n; i++) {
		for (int j = k; j > 1; j--) {
			if (!orders[i].empty()) {
				orders[i].pop();
			}
			else {
				break;
			}
		}
		if (!orders[i].empty()) printf("%d\n", orders[i].top());
		else {
			printf("-1\n");
		}
	}
} 