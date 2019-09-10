#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;

int n, k;
vector<int> primes;
int arr[10001] = { 0, };
//n의 입력이 10000000이므로 max까지만 해도 충분
int main() {
	int max = (int)sqrt(10000000) + 1;
	
	scanf("%d", &n);
	
	for (int i = 2; i <= n; i++) {
		if (n == 1) break;
		if (n%i == 0) {
			n = n / i;
			printf("%d\n", i);
			i--;
		}
	}
}
