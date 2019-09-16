#include <cstdio>
#pragma warning(disable:4996)

int main() {
	long long int a, b, v;
	scanf("%lld %lld %lld", &a, &b, &v);

	long long int left = 1;
	long long int right = 1000000000;
	long long int min = 1000000000;
	long long int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if ((mid * a - (mid - 1) * b) >= v) {
			right = mid;
			if (mid < min) min = mid;
		}
		else {
			left = mid + 1;
		}
	}
	if (left < min && (left * a - (left - 1) * b) >= v) min = left;

	printf("%lld\n", min);
}