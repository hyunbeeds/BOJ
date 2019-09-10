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
	//depth �ִ�ġ ���ؾߵ�
	int a, b;
	for (int i = 0; i < n-1; i++) {	//edge
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	//dfs �̿��ؼ� depth �ִ�ġ ���غ���
	dfs(1,0);
	
	for (int i = 1; i <= n; i++) {
		printf("%d depth : %d\n", i, dep[i]);
	}
	printf("max depth : %d\n", max_depth);
	
	//dp �迭 �ʱ�ȭ
	parent = vector<vector<int> >((int)log2(max_depth)+1);
	for (int i = 0; i < parent.size(); i++) {
		parent[i] = vector<int>(n+1, 0);
	}
	//dp �迭 ä���, ù��°��
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
	//������ �Է¹ޱ�	
	scanf("%d", &m);
	int diff;
	int cnt;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		//���� ���̰� ���� ���� ��� ���� ���̸� ���� �����.
		//printf("���� ������ %d %d\n", a, b);
		if (dep[a] != dep[b]) {
			if (dep[a] < dep[b]) {	// a�� ���̰� ���������� �ٲ�
				swap(a, b);
			}
			//a�� �ø�
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
		//printf("���� ���� �� %d %d\n",a, b);
		for (int j = parent.size() - 1; j >= 0; j--) {
			// parent[j][a], parent[j][b]�� ������ ���ΰ�
			// a, b�� �װɷ� �ٲ�
			if (parent[j][a] != parent[j][b]) {
				a = parent[j][a];
				b = parent[j][b];
				//printf("�̵� %d %d\n", a, b);
			}
			ans = parent[j][a];
		}
		printf("%d\n", ans);
	}
} */