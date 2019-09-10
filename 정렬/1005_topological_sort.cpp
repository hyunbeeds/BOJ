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
int n, m, f_p;						//n->������, m->������, f_p->������
int a[1005];						//���
int p[1005];						//������ ������
int dist[1005];						//��� ����ϴ� �迭

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
	memset(a, 0, sizeof a);				//�ʱ�ȭ

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
		if (p[i] == 0) {					//�������� 1. ������ ������ ���� ������ ť�� �ִ´�!
			q.push({ i,a[i] });
			dist[i] = a[i];
		}
	}
	
	while (!q.empty() && p[f_p]) {			//�������� 2. ť���� �ϳ��� ������ ���� ������ ����!.
		int now = q.front().point;
		int cost = q.front().cost;
		q.pop();

		if (now == f_p && cost > res)
			res = cost;

		for (int i = 0; i<v[now].size(); i++) {		//�������� 3. �� �������� ������ �������� ���ش�.
			int next = v[now][i];

			if (dist[next] <= dist[now] + a[next]) {	//�������� 4. ��� ���(������ �ִ밡 �ǰ�)
				dist[next] = dist[now] + a[next];
			}
			if (--p[next] == 0) {						//�������� 5. ������ ������ ���� ���� �ٽ� ã�Ƽ� ť�� �ֱ�!
				q.push({ next,a[next] + cost });
			}

		}
	}

	printf("%d\n", dist[f_p]);


}