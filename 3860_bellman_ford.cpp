#include <cstdio>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
#define rip 1
#define ghost 2
using namespace std;

typedef struct ghosthole {
	int end_x;
	int end_y;
	int time;
}ghosthole;

typedef struct edge {
	int start,end, cost;
	edge(int a, int b, int c) : start(a), end(b), cost(c) {};
}edge;

vector<ghosthole> holes;
int a, b, c, d, e;
int w, h;
int grave;
int hole;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1,-1, 0, 0 };

int dp[31][31] = { 0, };

int main() {
	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) break;	//00이면 종료

		int state[31][31] = { 0, };

		scanf("%d", &grave);
		for (int i = 0; i < grave; i++) {
			scanf("%d %d", &a, &b);
			state[b][a] = rip;
		}
		
		scanf("%d", &hole);
		vector<edge> edges;
		//holes = vector<ghosthole>(hole);
		for (int i = 0; i < hole; i++) {
			scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
			state[b][a] = 2;
			//holes[i].end_x = c;
			//holes[i].end_y = d;
			//holes[i].time = e;
			edges.push_back(edge(b*w + a, d*w+c, e));
		}
	
		
		int new_x, new_y;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				for (int d = 0; d < 4; d++) {
					if (state[i][j] >= rip) {	//귀신구멍이나 rip인 경우
						continue;
					}
					new_x = i + dx[d];
					new_y = j + dy[d];
					if (new_x < 0 || new_x >= h || new_y < 0 || new_y>=w) continue;
					if (state[new_x][new_y] == 1) continue;
					edges.push_back(edge(i*w + j, new_x*w + new_y, 1));
				}
			}
		}
		/*
		for (int i = 0; i < edges.size(); i++) {
			printf("%d->%d : %d\n", edges[i].start, edges[i].end, edges[i].cost);
		}
		*/

		vector<int> ans = vector<int>(w*h + 1, 100000000);
		ans[0] = 0;

		//벨만 포드알고리즘 이용하자.
		//vertex의 개수 w*h
		bool never = false;
		for (int v = 0; v < w*h-grave; v++) {
			for (int i = 0; i < edges.size(); i++) {
				if (ans[edges[i].end] > ans[edges[i].start] + edges[i].cost) {
					ans[edges[i].end] = ans[edges[i].start] + edges[i].cost;
				}
			}
		}
		for (int i = 0; i < edges.size(); i++) {
			if (ans[edges[i].end] > ans[edges[i].start] + edges[i].cost) {
				never = true;
				break;
			}
		}
		
		/*
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (ans[i*w + j] >= 100000000)printf("inf ");
				else printf("%3d ", ans[i*w+j]);
			}printf("\n");
		}*/
		if (never == true) {
			printf("Never\n");
		}
		else {
			if (ans[w*h - 1] >= 10000000) printf("Impossible\n");
			else printf("%d\n", ans[w*h - 1]);
		}
		edges.clear();
		ans.clear();
	}
}
