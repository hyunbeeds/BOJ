#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

int n, m;
int start;
int a, b, c;
int i, j;
vector<pair<int, int> > edge[20001];
int main() {
	scanf("%d %d", &n, &m);
	scanf("%d", &start);
	bool write;
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		write = false;
		for (j = 0; j < edge[a].size(); j++) {	// 중복된 간선확인해서 작은것만 남긴다.
			if (edge[a][j].first == b) {
				edge[a][j].second = min(edge[a][j].second, c);
				write = true;
			}
		}
		if (write == true) continue; //여기해결좀
		else edge[a].push_back(make_pair(b, c));
	}

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	//(cost, vertex번호)들어감
	vector<int> ans = vector<int>(n + 1, 50000000);
	ans[start] = 0;
	pq.push(make_pair(0, start));
	pair<int, int> cur;
	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();
		if (cur.first>ans[cur.second]) {
			continue;
		}
		for (i = 0; i < edge[cur.second].size(); i++) {
			if (ans[edge[cur.second][i].first] > cur.first + edge[cur.second][i].second) {
				ans[edge[cur.second][i].first] = cur.first + edge[cur.second][i].second;
				pq.push(make_pair(ans[edge[cur.second][i].first], edge[cur.second][i].first));
			}
		}

	}
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 50000000) printf("INF\n");
		else printf("%d\n", ans[i]);
	}
}