#include <cstdio>
#pragma warning(disable:4996)

int n, k, t;
int m;
double dp[2501][2501];
int dol[51];
double comb(int n, int r) {
	double &ret = dp[n][r];
	if (ret > 0) return ret;
	if (r == 0 || r == n) return ret = 1;
	return ret = comb(n - 1, r - 1) + comb(n - 1, r);
}
int main() {
	
	scanf("%d", &m);
	n = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &dol[i]);
		n += dol[i];
	}
	scanf("%d", &k);

	double result=0.0;
	for (int i = 1; i <= m; i++) {
		if (dol[i] < k) continue;
		result += comb(dol[i],k);
	}
	result = result / comb(n,k);
	printf("%.10lf\n", result);
}
