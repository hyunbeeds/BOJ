#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

long long factorial[21];

int main() {
	int n, order;
	int arr[21] = { 0, };
	int str[21] = { 0, };
	factorial[0] = 1;
	for (int i = 1; i <= 20; i++) {
		factorial[i] = i*factorial[i - 1];
	}
	scanf("%d", &n);
	scanf("%d", &order);
	int len = n;
	if (order == 1) {
		long long int k;
		scanf("%lld", &k);
		while (1) {
			if (n == 0) break;
			int cur = 1;
			while (1) {
				if (cur*factorial[n - 1] >= k) break;
				cur++;
			}
			int cnt = 0;
			for (int i = 1; i <= len; i++) {
				if (arr[i] == 0) {
					cnt++;
					if (cnt == cur) {
						cnt = i;
						break;
					}
				}
			}
			arr[cnt] = 1;
			printf("%d ", cnt);
			k = k - (cur - 1)*factorial[n - 1];
			n--;
		}
		printf("\n");
	}
	else if (order == 2) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &str[i]);
		}
		long long int result = 0;
		int len = n;
		for (int i = 1; i <= n; i++) {
			int cur = 0;
			for (int j = 1; j <= n; j++) {
				if (arr[j] == 0) {
					cur++;
				}
				if (j == str[i]) {
					break;
				}
			}
			arr[str[i]] = 1;
			//나올때 몇번째인지 알려준다.
			result = result + (cur - 1)*factorial[len - 1];
			len--;
		}
		result = result + 1;
		printf("%lld\n", result);
	}
}