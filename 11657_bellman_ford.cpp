/*#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

int n, m;
int start;
int a, b, c;
typedef struct edge {
	int start;
	int end;
	int cost;
}edge;

edge edges[6001];

int main() {
	scanf("%d %d", &n, &m);
	start = 1;
	bool write;
	int cnt;
	cnt = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edges[cnt].start = a;
		edges[cnt].end = b;
		edges[cnt].cost = c;
		cnt++;
	}

	
	vector<int> ans = vector<int>(n + 1, 50000000);
	ans[start] = 0;
	//n-1번 update
	for (int v = 1; v < n; v++) {
		for (int i = 0; i < cnt; i++) {
			if (ans[edges[i].end] > ans[edges[i].start] + edges[i].cost && ans[edges[i].start] + edges[i].cost<=5000000) {
				ans[edges[i].end] = ans[edges[i].start] + edges[i].cost;
			}
		}
	}
	//마지막 바뀌나 확인
	bool minus = false;
	for (int i = 0; i < cnt; i++) {
		if (ans[edges[i].end] > ans[edges[i].start] + edges[i].cost && ans[edges[i].start] + edges[i].cost <= 5000000) {
			minus = true;
		}
	}
	if (minus == true) {
		printf("-1\n");
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (ans[i] >= 50000000) printf("-1\n");
			else printf("%d\n", ans[i]);
		}
	}
}*/