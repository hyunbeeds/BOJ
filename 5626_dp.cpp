#include <cstdio>
#include <cstring>
#pragma warning(disable:4996)

long long int mod = 1000000007;
int n, arr[10001];
long long int dp[2][10010];

// 첫번째 제단과 마지막 제단은 무조건 높이가 0이다
// 그리고 인접한 제단들은 최대 높이 차이가 1이다.
// 따라서 아래처럼  점화식을 세울수 있는데,
// dp[i][j] = dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1]
// dp[i][j] - > 첫번째 열부터 순서대로 높이를 정해나갈때. 
// i번째열 높이가 j일 경우의수, 
// 근데 이대로 하면 메모리 초과나니까 sliding window기법 사용
//  보면 직전의 높이의 경우의 수만 필요하기에 2개로 했다. 

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] != -1) {	//dp[i][j]에서 j들어갈때, j-1이 식안에 들어가기때문에
			arr[i]++;		//0이 있으면 예외처리해주어야하므로, 전체적으로 다 1씩 더해주었다.
		}
	}

	if (arr[0] == -1 || arr[0] == 1) {
		dp[0][1] = 1;
	}
	else {
		dp[0][1] = 0;	//불가능한 경우, 뒤는 다 0 나올거임..
	}

	int cur = 0;
	int next = 1;
	for (int i = 1; i < n; i++) {
		memset(dp[next], 0, sizeof(dp[next]));
		if (arr[i] == -1) {
			//도둑이 훔쳐간 경우는 모든 높이가 가능하므로
			for (int j = 1; j <= n; j++) {
				dp[next][j] = (dp[cur][j - 1] + dp[cur][j] + dp[cur][j + 1]) % mod;
			}
		}
		else {
			// 높이가 있는경우는 무조건 그높이여야만 하므로
			dp[next][arr[i]] = (dp[cur][arr[i] - 1] + dp[cur][arr[i]] + dp[cur][arr[i] + 1]) % mod;
		}
		cur = 1 - cur;
		next = 1 - next;
	}
	printf("%lld\n", dp[cur][1]);
}