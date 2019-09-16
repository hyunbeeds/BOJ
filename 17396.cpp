#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>
#pragma warning(disable:4996)

using namespace std;

int n, m;
int sight[100001];

vector<pair<int, long long int> > road[100001];

priority_queue<pair<long long int, int>, vector<pair<long long int, int> >, greater<pair<long long int, int> > > pq;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++) {
		scanf("%d", &sight[i]);
	}
	sight[n - 1] = 0;
	int a, b;
	long long int c;
	//연결은 양방향
	for (int i = 0;i < m;i++) {
		scanf("%d%d%lld", &a, &b, &c);
		if (sight[a] == 1 || sight[b] == 1) {
			continue;
		}
		road[a].push_back(make_pair(b, c));
		road[b].push_back(make_pair(a, c));
	}

	pq.push(make_pair(0, 0));
	long long int cost, next_cost;
	int cur, next;
	vector<long long int> dist(n, LLONG_MAX);
	dist[0] = 0;

	while (!pq.empty()) {
		pair<long long int, int> temp=pq.top();
		cost = temp.first;
		cur = temp.second;
		pq.pop();
		if (cur == n - 1) {
			printf("%lld\n", cost);
			return 0;
		}

		if (dist[cur] < cost)
			continue;

		for (int i = 0;i < road[cur].size();i++) {
			next = road[cur][i].first;
			next_cost = cost + road[cur][i].second;
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push(make_pair(next_cost, next));
			}
		}
	}
	printf("-1\n");
}