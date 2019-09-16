#include <cstdio>
#pragma warning(disable:4996)

const int MAX_N = 5e5, MAX_L = 1e6;
int bit[MAX_N + 1], idx[MAX_L + 1];
long long n;
long long r;
long long sum;

int main() {
	scanf("%lld", &n);
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), idx[x] = i;
	sum = 0;
	for (int i = 0, x; i < n; i++) {
		scanf("%d", &x);
		r = 0;
		for (int j = idx[x]; j > 0; j -= j & -j) {
			r += bit[j];
		}
		sum+= (i - r);
		for (int j = idx[x]; j<=n; j += j & -j) {
			bit[j]++;
		}
	}
	printf("%lld", r);
	return 0;
}