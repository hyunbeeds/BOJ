#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int arr[501][501] = { 0, };
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = 10000;
		}
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}

	//floyd warshall �˰����� ���� �Ÿ��� ���ϰ�
	//(���� ������ ����->��), (��->���������� ����)�� �Ÿ��� �ִ� �͵���
	//������ ������-1�̸� ���� ������ �˼� �ִ� ���̴�.
	//�ƴϸ� �𸣴°�!

	for (int k = 1; k <= n; k++) {
		// k-> ������
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// i->������, j������
				if (i == k || j == k) continue;
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	int cnt;
	int ans = 0;
	for (int k = 1; k <= n; k++) {
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (arr[k][i] >= 1 && arr[k][i] < 10000) cnt++;
			if (arr[i][k] >= 1 && arr[i][k] < 10000) cnt++;
		}
		if (cnt == n - 1) ans++;
	}
	printf("%d\n", ans);
}