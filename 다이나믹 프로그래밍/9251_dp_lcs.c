#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

char str1[1010];
char str2[1010];
char answer[1010];
int cnt=0;
int str1_len, str2_len;
int dp[1010][1010] = { 0 };	//dp[i][j]의미, str1을 i번째, str2를 j번째까지 읽었을때 lcs의 크기
							//dp[i][0],dp[0][j]=0(0<=i<=N,0<=j<=M),
							//if(str1[i-1]==str2[j-1]) dp[i][j]==dp[i-1][j-1]+1
							//else dp[i][j]=MAX(dp[i-1][j],dp[i][j-1])
int main() {
	int a, b;
	scanf("%s %s", str1, str2);
	str1_len = strlen(str1);
	str2_len = strlen(str2);
	for (int i = 1;i <= str1_len;i++) {
		for (int j = 1;j <= str2_len;j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				if (dp[i - 1][j] > dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
				}
				else dp[i][j] = dp[i][j - 1];
			}
		}
	}

	//왼쪽 위 가운데
	a = str1_len;
	b = str2_len;
	while (dp[a][b] != 0) {
		if (dp[a][b] == dp[a][b-1]) {
			b--;
			continue;
		}
		if (dp[a][b] == dp[a - 1][b]) {
			a--;
			continue;
		}
		if (dp[a][b] == dp[a - 1][b - 1]+1) {
			answer[cnt] = str1[a - 1];
			cnt++;
			a--;b--;
			continue;
		}
		printf("a :%d b:%d",a,b);
	}
	printf("%d\n", dp[str1_len][str2_len]);
	for (int i = cnt - 1;i >= 0;i--) {
		printf("%c", answer[i]);
	}
	printf("\n");
}