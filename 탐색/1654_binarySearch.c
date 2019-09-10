#include <stdio.h>
#pragma warning(disable:4996)

long long n, m, max;
long long left, right;
int light[10001];

long long how_many(long long decide) {
	long long num = 0;
	for (int i = 0;i < n;i++) {
		num += light[i] / decide;
	}
	return num;
}
int main() {
	long long ans = 0;
	max = 0;
	scanf("%lld%lld", &n, &m);
	for (int i = 0;i < n;i++) {
		scanf("%d", &light[i]);
		if (light[i] > max)	max = light[i];
	}
	left = 0;
	right = max;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (how_many(mid) < m) {
			right = mid - 1;
		}
		else {
			if (ans < mid) {
				ans = mid;
			}
			left = mid + 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}