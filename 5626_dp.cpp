#include <cstdio>
#include <cstring>
#pragma warning(disable:4996)

long long int mod = 1000000007;
int n, arr[10001];
long long int dp[2][10010];

// ù��° ���ܰ� ������ ������ ������ ���̰� 0�̴�
// �׸��� ������ ���ܵ��� �ִ� ���� ���̰� 1�̴�.
// ���� �Ʒ�ó��  ��ȭ���� ����� �ִµ�,
// dp[i][j] = dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1]
// dp[i][j] - > ù��° ������ ������� ���̸� ���س�����. 
// i��°�� ���̰� j�� ����Ǽ�, 
// �ٵ� �̴�� �ϸ� �޸� �ʰ����ϱ� sliding window��� ���
//  ���� ������ ������ ����� ���� �ʿ��ϱ⿡ 2���� �ߴ�. 

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] != -1) {	//dp[i][j]���� j����, j-1�� �ľȿ� ���⶧����
			arr[i]++;		//0�� ������ ����ó�����־���ϹǷ�, ��ü������ �� 1�� �����־���.
		}
	}

	if (arr[0] == -1 || arr[0] == 1) {
		dp[0][1] = 1;
	}
	else {
		dp[0][1] = 0;	//�Ұ����� ���, �ڴ� �� 0 ���ð���..
	}

	int cur = 0;
	int next = 1;
	for (int i = 1; i < n; i++) {
		memset(dp[next], 0, sizeof(dp[next]));
		if (arr[i] == -1) {
			//������ ���İ� ���� ��� ���̰� �����ϹǷ�
			for (int j = 1; j <= n; j++) {
				dp[next][j] = (dp[cur][j - 1] + dp[cur][j] + dp[cur][j + 1]) % mod;
			}
		}
		else {
			// ���̰� �ִ°��� ������ �׳��̿��߸� �ϹǷ�
			dp[next][arr[i]] = (dp[cur][arr[i] - 1] + dp[cur][arr[i]] + dp[cur][arr[i] + 1]) % mod;
		}
		cur = 1 - cur;
		next = 1 - next;
	}
	printf("%lld\n", dp[cur][1]);
}