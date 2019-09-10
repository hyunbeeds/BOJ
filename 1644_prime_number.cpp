#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int n, k;
vector<int> primes;
int arr[4000001] = { 0, };
int sums[4000001] = { 0, };
int main() {
	for (int i = 2; i <= 4000000; i++) {
		int prime;
		if (arr[i] == 0) {
			arr[i] = 1;
			primes.push_back(i);
			prime = i;
			for (int j = 2; prime*j <= 4000000; j++) {
				arr[prime*j] = 1;
			}
		}
		else continue;
	}
	
	
	for (int i = 0; i < primes.size(); i++) {
		printf("%d ",primes[i]);
		if (i % 10 == 0)printf("\n");
	}

	long long int sum = 0;
	for (int i = 0; i < primes.size(); i++) {
		sum = 0;
		for (int j = i; j < primes.size(); j++) {
			sum += primes[j];
			if (sum > 4000000) break;
			sums[sum]++;
		}
	}

	scanf("%d", &n);
	printf("%d\n", sums[n]);
}