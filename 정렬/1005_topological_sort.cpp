#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#pragma warning(disable:4996)

using namespace std;
struct Data {
	int point;
	int cost;
};

vector<int>v[1005];
int n, m, f_p;						//n->빌딩수, m->간선수, f_p->도착점
int a[1005];						//비용
int p[1005];						//들어오는 간선수
int dist[1005];						//비용 계산하는 배열

void init();    void solve();

int main() {
	int tc;								//testcase
	cin >> tc;

	for (int i = 0; i<tc; i++) {
		init(); solve();
	}
	return 0;
}

void init() {
	memset(dist, 0, sizeof dist);
	memset(p, 0, sizeof p);
	memset(a, 0, sizeof a);				//초기화

	for (int i = 0; i<1001; i++)
		v[i].clear();

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i<m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		p[y]++;
	}
	scanf("%d", &f_p);

}


void solve() {

	int res = 0;

	queue<Data>q;

	for (int i = 1; i <= n; i++) {
		if (p[i] == 0) {					//위상정렬 1. 들어오는 간선이 없는 정점을 큐에 넣는다!
			q.push({ i,a[i] });
			dist[i] = a[i];
		}
	}
	
	while (!q.empty() && p[f_p]) {			//위상정렬 2. 큐에서 하나씩 간선이 없는 정점을 뺀다!.
		int now = q.front().point;
		int cost = q.front().cost;
		q.pop();

		if (now == f_p && cost > res)
			res = cost;

		for (int i = 0; i<v[now].size(); i++) {		//위상정렬 3. 그 정점에서 나가는 간선들을 없앤다.
			int next = v[now][i];

			if (dist[next] <= dist[now] + a[next]) {	//위상정렬 4. 비용 계산(무조건 최대가 되게)
				dist[next] = dist[now] + a[next];
			}
			if (--p[next] == 0) {						//위상정렬 5. 들어오는 간선이 없는 정점 다시 찾아서 큐에 넣기!
				q.push({ next,a[next] + cost });
			}

		}
	}

	printf("%d\n", dist[f_p]);


}