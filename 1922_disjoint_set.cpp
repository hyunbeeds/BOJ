#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

int joint[1001];
int n, m;
int visited[1001] = { 0, };


typedef struct edge {
	int start;
	int end;
	int cost;
}edge;
priority_queue<edge> edges;

bool operator < (edge a, edge b) {
	return a.cost > b.cost;
}


int par(int a) {
	if (joint[a] == a) return a;
	else return joint[a] = par(joint[a]);
}

void unify(int a, int b) {
	int aroot = par(a);
	int broot = par(b);
	joint[aroot] = broot;
}


int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edge d;
		d.start = a;
		d.end = b;
		d.cost = c;
		edges.push(d);
	}
	for (int i = 0; i <= n; i++) {
		joint[i] = i;
	}

	edge cur;
	int ans = 0;
	while (!edges.empty()) {
		cur=edges.top();
		edges.pop();
		if (par(cur.start) == par(cur.end)) {
			continue;
		}
		else {
			visited[cur.start] = 1;
			visited[cur.end] = 1;
			ans += cur.cost;
			unify(cur.start, cur.end);
			//printf("%d %d Ãß°¡\n", cur.start, cur.end);
		}
	}
	printf("%d\n", ans);
}
