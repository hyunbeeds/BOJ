#include <stdio.h>
#pragma warning(disable:4996)
long long row, col;
long long answer = 0;
long long num;
long long pow = 1;

void solve(long long n,long long r, long long c) {	//n->길이
	if (n == 2) {
		if (r == 1 && c == 1) answer += 0;
		if (r == 1 && c == 2) answer += 1;
		if (r == 2 && c == 1) answer += 2;
		if (r == 2 && c == 2) answer += 3;
		return;
	}
	long long mid = n / 2;
	if (r <= mid&&col <= mid) {	//2사분면
		solve(mid, r, c);
	}
	if (r <= mid&&col > mid) {	//1사분면
		answer += mid*mid;
		solve(mid, r, c - mid);
	}
	if (r > mid&&col <= mid) {	//3사분면
		answer += mid*mid*2;
		solve(mid, r-mid, c);
	}
	if (r > mid&&col > mid) {	//4사분면
		answer += mid*mid*3;
		solve(mid, r-mid, c - mid);
	}

}

int main() {
	scanf("%lld %lld %lld", &num, &row, &col);
	if (num == 0 && row == 0 && col == 0) {
		printf("0\n");
		return 0;
	}
	if (num == 1) {
		if (row == 0 && col == 0) answer += 0;
		if (row == 0 && col == 1) answer += 1;
		if (row == 1 && col == 0) answer += 2;
		if (row == 1 && col == 1) answer += 3;
		printf("%lld\n", answer);
		return 0;
	}
	for (int i = 0;i < num;i++) {
		pow = pow * 2;
	}
	solve(pow,row+1,col+1);

	printf("%lld\n", answer);
	return 0;
}