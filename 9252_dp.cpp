#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)
using namespace std;

int dp[1005][1005] = { 0, };
// dp[i][j]-> a를 i번째까지 읽고, b를 j까지 읽었을때 최장 문자열
//
int main() {
	char a[1005];
	char b[1005];
	scanf("%s", a);
	scanf("%s", b);

	for (int i = 1; i <= strlen(a); i++) {
		for (int j = 1; j <= strlen(b); j++) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	int i, j;
	i = strlen(a);
	j = strlen(b);
	printf("%d\n", dp[i][j]);
	
	vector<char> ans;
	
	while (dp[i][j]!=0) {
		if (dp[i][j - 1] == dp[i][j]) {
			j = j - 1;
			continue;
		}
		if (dp[i - 1][j] == dp[i][j]) {
			i = i - 1;
			continue;
		}
		
		if(dp[i-1][j-1]+1==dp[i][j]){
			ans.push_back(a[i - 1]);
			j = j - 1;
			i = i - 1;
		}
	}
	for (i = ans.size() - 1; i >= 0; i--) {
		printf("%c", ans[i]);
	}printf("\n");
}