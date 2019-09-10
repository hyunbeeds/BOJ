#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#define INF 2e9

using namespace std;

int n;
int dp[16][1 << 16], adj[16][16];		//dp[current][status]->������ �湮�Ѱ� current�̰�, status(��Ʈ����ũ�� ǥ��)
										//ex) 4�� ����, 1 2 �湮 �Ϸ��Ͻ� -> 1100
int TSP(int cur, int visited) {
	if (visited == (1 << n) - 1) return adj[cur][0];	// �� �湮�Ǿ�����

	int& ret = dp[cur][visited];						
	if (ret != 0) return ret;												//ret�� ������ �ִ°��̶�� �׳� ��ȯ
	ret = INF;
	for (int next = 0; next < n; next++) {
		if (visited&(1 << next))continue;									// next�� �湮���� �ִ� ���϶�
		if (adj[cur][next] == 0)continue;									// next�� �ڱ� �ڽ��϶�
		ret = min(ret, TSP(next, visited | (1 << next)) + adj[cur][next]);	// (next�� �߰��ϴµ� ���� ���+����)�� dp�߿� next�� �߰��ȰͰ� �ּҰ� ���ؼ� dp
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &adj[i][j]);
		}
	printf("%d\n", TSP(0, 1));		//0�� �ʱⰪ���� ����
	return 0;
}