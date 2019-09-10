#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

#pragma warning(disable:4996)
#define MAX 987654321

using namespace std;

int n, m;	// n->vertex수, m-> edge수
int start, finish;

int main() {
	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;

		scanf("%d %d", &start, &finish);

		int a, b, c;
		vector<pair<int, int> > edges[500];

		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			edges[a].push_back(make_pair(b, c));
		}
		vector<int> vertex(n + 1, MAX);
		vertex[start] = 0;

		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		pq.push({0, start});
		vertex[start] = 0;
		while (!pq.empty()) {
			pair<int, int> cur = pq.top();
			pq.pop();
			int c_node = cur.second;
			int c_cost = cur.first;
			for (int i = 0; i < edges[c_node].size(); i++) {
				int n_node = edges[c_node][i].first;
				int n_cost = edges[c_node][i].second;

				if (vertex[n_node] > vertex[c_node] + n_cost) {
					vertex[n_node] = vertex[c_node] + n_cost;
					pq.push({vertex[n_node],n_node});
				}
			}	
		}

		priority_queue<int> del;
		del.push(finish);
		while (!del.empty()) {
			int last=del.top();
			del.pop();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < edges[i].size(); j++) {
					if (edges[i][j].first == last) {
						if (vertex[last] == vertex[i] + edges[i][j].second) {
							edges[i][j].second = MAX;
							del.push(i);
						}
					}
					else continue;
				}
			}
		}
		vertex = vector<int>(n + 1, MAX);
		vertex[start] = 0;
		pq.push({ 0, start });
		while (!pq.empty()) {
			pair<int, int> cur = pq.top();
			pq.pop();
			int c_node = cur.second;
			int c_cost = cur.first;
			for (int i = 0; i < edges[c_node].size(); i++) {
				int n_node = edges[c_node][i].first;
				int n_cost = edges[c_node][i].second;

				if (n_cost == MAX) continue;	//최단경로라 없어진 edge
				
				if (vertex[n_node] > vertex[c_node] + n_cost) {
					vertex[n_node] = vertex[c_node] + n_cost;
					pq.push({ vertex[n_node],n_node });
				}
			}
		}

		if (vertex[finish] == MAX) printf("-1\n");
		else printf("%d\n", vertex[finish]);

		// 다익스트라 구해놓은 다음에 최소 경로 지우고 다시 다익스트라
	}
}