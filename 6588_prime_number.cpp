#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int n, k;
int arr[1000001] = { 0, };
int primes[1000001] = { 0, };
int main() {
	for (int i = 2; i <= 1000000; i++) {
		int prime;
		if (arr[i] == 0) {
			arr[i] = 1;
			primes[i] = 1;
			prime = i;
			
			for (int j = 2; prime*j <= 1000000; j++) {
				arr[prime*j] = 1;
			}
		}
		else continue;
	}

	int n=1;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		else {
			for (int i = 3; i*2 <= n; i+=2) {
				if (primes[i] == 1 && primes[n - i]==1) {
					printf("%d = %d + %d\n", n, i, n - i);
					break;
				}
			}
		}
	}
}