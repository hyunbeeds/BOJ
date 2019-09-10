#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int N;
vector<long long int> arr;


int main() {
	int n;
	scanf("%d", &N);
	arr.push_back(0);
	arr.push_back(1);
	for (int i = 2; i <= N; i++) {
		arr.push_back(arr[i - 2] + arr[i - 1]);
	}
	printf("%lld\n", arr[N]);
}