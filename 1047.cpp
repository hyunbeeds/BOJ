#include <cstdio>
#pragma warning(disable:4996)

int coin[11];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i=1;i<=n;i++) scanf("%d", &coin[i]);
	
	int cnt = 0;
	for (int i = n; i >= 1; i--) {
		if (coin[i] <= k) {
			cnt += k / coin[i];
			k = k - (k / coin[i])*coin[i];
			if (k == 0) break;
		}	
	}
	printf("%d\n", cnt);
}