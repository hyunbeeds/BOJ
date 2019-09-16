#include <cstdio>
#include <cmath>
#include <vector>
#pragma warning(disable:4996)
#define mod 1000000007
using namespace std;
vector<long long int> arr;
vector<long long int> tree;

long long int init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = (init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end)) % mod;

}
long long int update(int node, int index, int start, int end, long long int val) {
	if (index < start || end < index) return tree[node];
	if (start == end) return tree[node] = val;
	int mid = (start + end) / 2;
	return tree[node] = (update(node * 2, index, start, mid, val) * update(node * 2 + 1, index, mid + 1, end, val))%mod;

}
long long int sum(int node, int start, int end, int left, int right) {
	//left~right 범위 곱구하려고함
	//아예범위안인경우
	if (left <= start && end <= right) {
		return tree[node];
	}
	//범위밖인경우 1반환
	if (right<start || end<left) {
		return 1;
	}

	int mid = (start + end) / 2;
	
	return (sum(node * 2, start, mid,left, right) * sum(node * 2 + 1, mid + 1, end, left, right)) % mod;
}
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	arr= vector<long long int>(n+1, 0);
	tree= vector<long long int>(1<<(int)(ceil(log2(n))+1), 1);
	for (int i = 1;i <= n;i++) {
		scanf("%lld", &arr[i]);
	}
	init(1, 1, n);
	long long int order,a,b;
	for (int i = 0;i < m + k;i++) {
		scanf("%lld%lld%lld", &order, &a, &b);
		if (order == 1) {	//update
			update(1, a, 1, n, b);
		}
		else {	//곱 구해서 출력
			printf("%lld\n", sum(1, 1, n, a, b) % mod);
		}
	}
}