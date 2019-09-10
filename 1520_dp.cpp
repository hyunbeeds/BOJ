#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;
int m, n, cnt;
int arr[501][501];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dp[501][501];
int move(int x, int y)
{
	// ���� ����
	if (x == m - 1 && y == n - 1)
		return 1;

	int &ret = dp[x][y];
	// �̹� ���� ���̸� ��ȯ(�޸������̼�)
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
			continue;

		// ������ �� �ִ� ����
		if (arr[x][y] > arr[next_x][next_y]) {
			// �������� ���������� 1�� ��ȯ �� �̴ϴ�.
			ret += move(next_x, next_y);
		}
	}
	return ret;
}
int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// �� �� ���� ���� 0�� �� �� �ֱ� ������
			// �� ���� �õ����� ���� ���� -1�� �ʱ�ȭ
			dp[i][j] = -1;
			scanf("%d", &arr[i][j]);
		}
	}
	printf("%d\n", move(0, 0));

	return 0;
}