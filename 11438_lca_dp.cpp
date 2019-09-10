/*#include <cstdio>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;

int n,m;

vector<int> edge[100001];
int max_depth = 0;
int dep[100001];
int visited[100001] = { 0, };
vector<vector<int> > parent;


void dfs(int cur, int depth) {
	dep[cur] = depth;
	if (depth > max_depth) max_depth = depth;
	visited[cur] = 1;
	for (int i = 0; i < edge[cur].size(); i++) {
		if(!visited[edge[cur][i]]) dfs(edge[cur][i], depth + 1);
	}
}
int main() {
	scanf("%d", &n);
	//depth 최대치 구해야됨
	int a, b;
	for (int i = 0; i < n-1; i++) {	//edge
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	//dfs 이용해서 depth 최대치 구해보자
	dfs(1,0);
	
	for (int i = 1; i <= n; i++) {
		printf("%d depth : %d\n", i, dep[i]);
	}
	printf("max depth : %d\n", max_depth);
	
	//dp 배열 초기화
	parent = vector<vector<int> >((int)log2(max_depth)+1);
	for (int i = 0; i < parent.size(); i++) {
		parent[i] = vector<int>(n+1, 0);
	}
	//dp 배열 채우기, 첫번째열
	parent[0][0] = 0;
	parent[0][1] = 0;
	int res;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < edge[i].size(); j++) {
			if (dep[i] > dep[edge[i][j]]) {
				parent[0][i] = edge[i][j];
				break;
			}
		}
	}
	for (int i = 1; i < parent.size(); i++) {
		parent[i][0] = 0;
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
	
	for (int i = 0; i < parent.size(); i++) {
		for (int j = 1; j <= n; j++) {
			printf("%2d ", parent[i][j]);
		}printf("\n");
	}
	//문제수 입력받기	
	scanf("%d", &m);
	int diff;
	int cnt;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		//둘의 깊이가 같지 않을 경우 둘의 깊이를 같게 만든다.
		//printf("깊이 변경전 %d %d\n", a, b);
		if (dep[a] != dep[b]) {
			if (dep[a] < dep[b]) {	// a를 깊이가 높은놈으로 바꿈
				swap(a, b);
			}
			//a를 올림
			diff = dep[a] - dep[b];
			cnt = 0;
			while (diff != 0) {
				if (diff % 2 == 1) {
					a = parent[cnt][a];
				}
				cnt++;
				diff = diff / 2;
			}
		}
		if (a == b) {
			printf("%d\n", a);
			continue;
		}
		int ans = a;
		//printf("깊이 변경 후 %d %d\n",a, b);
		for (int j = parent.size() - 1; j >= 0; j--) {
			// parent[j][a], parent[j][b]가 같으면 놔두고
			// a, b를 그걸로 바꿈
			if (parent[j][a] != parent[j][b]) {
				a = parent[j][a];
				b = parent[j][b];
				//printf("이동 %d %d\n", a, b);
			}
			ans = parent[j][a];
		}
		printf("%d\n", ans);
	}
} */