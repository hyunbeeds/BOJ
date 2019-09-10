#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)
using namespace std;

int dp[4005][4005] = { 0, };
// dp[i][j]-> a를 i번째까지 읽고, b를 j까지 읽었을때 b의 j에서 끝나는 최장 공통 문자열

int main() {
	char a[4005];
	char b[4005];
	scanf("%s", a);
	scanf("%s", b);
	int max = 0;
	int a_length = strlen(a);
	int b_length = strlen(b);
	for (int i = 1; i <= a_length; i++) {
		for (int j = 1; j <= b_length; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > max) max = dp[i][j];
			}
			else {
				dp[i][j] = 0;
			}
		}
	}
	printf("%d\n", max);
}