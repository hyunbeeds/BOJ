#include <cstdio>
#include <cmath>
#include <vector>
#pragma warning(disable:4996)

#define mod 1000000007 
using namespace std;

int main() {
	vector<long long int> arr(log2(1e19) + 1, 0);
	long long int a, x;
	scanf("%lld%lld", &a, &x);
	a = a % mod;
	arr[1] = a;
	for (int i = 2;i <arr.size();i++) {
		arr[i] = (arr[i - 1] * arr[i-1]) % mod;
	}
	long long int result = 1;
	int cnt=1;
	while (x > 0) {
		if (x % 2 == 1) {
			result = ((result%mod) * (arr[cnt]%mod)) % mod;
		}
		x = x >> 1;
		cnt++;
	}
	printf("%lld\n", result%mod);
}