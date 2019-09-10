#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

int n, k;
int arr[1001]={0, };

int main() {
	scanf("%d %d", &n, &k);
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		int prime;
		if (arr[i] == 0) {
			arr[i] = 1;
			prime = i;
			cnt++;
			if (cnt == k) {
				printf("%d\n",prime);
				return 0;
			}
			for (int j = 2; prime*j <= n; j++) {
				if (arr[prime*j] == 0) {
					arr[prime*j] = 1;
					cnt++;
					if (cnt == k) {
						printf("%d\n", prime*j);
						return 0;
					}
				}
			}
		}
		else continue;
	}
}