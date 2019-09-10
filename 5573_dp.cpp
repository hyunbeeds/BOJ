#include <cstdio>
#pragma warning(disable:4996)
using namespace std;

int h, w, n;
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
int arr[1002][1002] = { 0, };
int dp[1002][1002] = { 0, };
int main() {
	scanf("%d %d %d", &h, &w, &n);
	//(i,j) -> i==h+1 or j==w+1�Ǹ� ����
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	//dp[1][1][0]+dp[1][1][1]=n;
	dp[1][1] = n-1;

	for (int i = 1; i <= h; i++) {	//�Ʒ��� ����
		for (int j = 1; j <= w; j++) {
			if (dp[i][j]%2 == 0) {	//2�� ���������
				dp[i][j + 1] += dp[i][j] / 2;
				dp[i + 1][j] += dp[i][j] / 2;
			}
			else {	//2�� �ȶ�����
				if (arr[i][j] == 1) {	//���������� ���°��
					dp[i][j + 1] += dp[i][j] / 2 + 1;
					dp[i + 1][j] += dp[i][j] / 2;
				}
				else {	//�Ʒ��� ���°��
					dp[i][j + 1] += dp[i][j] / 2;
					dp[i + 1][j] += dp[i][j] / 2 + 1;
				}
			}
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (dp[i][j] % 2 == 0)
				continue;
			else
				arr[i][j]= (!arr[i][j]);
		}
	}
	int cur_i=1;
	int cur_j=1;
	while (cur_i != h + 1 && cur_j != w + 1) {
		if (arr[cur_i][cur_j] == 1) {
			cur_j++;
		}
		else {
			cur_i++;
		}
	}
	printf("%d %d\n", cur_i, cur_j);
}
