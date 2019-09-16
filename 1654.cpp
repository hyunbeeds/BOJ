#include <cstdio>
#include <limits.h>
#pragma warning(disable:4996)

int k, n;
long long int arr[10001];

int main() {
	scanf("%d%d", &k, &n);
	for (int i = 0;i < k;i++) {
		scanf("%lld", &arr[i]);
		
	}
	long long int start = 1;
	long long int end = INT_MAX;
	long long int mid;
	long long int num;
	long long int min = -1;
	while (start <= end) {
		mid = (start + end) / 2;
		num = 0;
		for (int i = 0;i < k;i++) {
			num = num + (arr[i]/mid);	
		}
		if (num >= n) {
			start = mid + 1;
			if (mid > min) min = mid;
		}
		else {
			end = mid - 1;
		}
	}
	printf("%lld\n", min);
}
