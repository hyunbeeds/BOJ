#include <stdio.h>
#pragma warning(disable:4996)

int dp[201][201][21];	//지금하고있는게 앞에가 x, 뒤가 y, 지금상태 z, 오는데 걸린 수;
int inf[201];
int n;
int color;
int answer = 500;
void solve(int start, int end, int current,int cnt) {
	int left, right;

	if (start == 1 && end == n) {
		if (answer > cnt) answer = cnt;
		return;
	}

	left = start-1;
	right = end+1;

	while (1) {
		if (left == 1) break;
		if (inf[left - 1] == inf[left]) {
			left = left - 1;
		}
		else break;
	}

	while (1) {
		if (right == n)break;
		if (inf[right + 1] == inf[right]) {
			right = right + 1;
		}
		else break;
	}

	if (start == left) {
		solve(start, right, inf[right], cnt + 1);
		return;
	}
	else if (end == right) {
		solve(left, end, inf[left], cnt + 1);
		return;
	}
	else {
		solve(left, end, inf[left], cnt + 1);
		solve(start, right, inf[right], cnt + 1);
		return;
	}
}
int main() {
	scanf("%d", &n);
	scanf("%d", &color);
	for (int i = 1;i < n;i++) {
		scanf("%d", &inf[i]);
	}
	for (int i = 1;i <= n;i++) {
		solve(i, i, inf[i], 0);
	}

	printf("%d\n", answer);

}