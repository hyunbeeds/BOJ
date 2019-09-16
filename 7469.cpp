#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;

vector<int> tree[263000];
// 1<<(ceil(log2(100000))+1) = 262144..
int arr[100001];
void update(int node, int start, int end, int index, int x) {
	
	if (index < start || end < index) {
		return;
	}
	tree[node].push_back(x);
	if (start == end) return;

	int mid = (start + end) / 2;
	update(node * 2, start, mid, index,x);
	update(node * 2+1, mid+1, end, index, x);
}
int count(int node, int start, int end, int left, int right, int x) {
	// left~right 구간에서 x보다 작은놈의 개수를 세서 반환해주는 함수다.
	// 현재 start~end구간에 위치해있다.
	// 현재범위가 구하려고 하는 범위와 완전히 다른경우
	if (end < left || right < start) {
		return 0;
	}
	// start~end가 left~right 사이 범위안에 완전히 들어가는 경우
	if (left <= start && end <= right) {
		// 현재구간에서 x보다 작은 놈이 몇개인지 확인해서 반환한다. 
		return upper_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin();
	}
	int mid = (start + end) / 2;
	return count(node * 2, start, mid, left, right, x) + count(node * 2 + 1, mid + 1, end, left, right, x);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	int max = 1 << (int)(ceil(log2(n)) + 1);
	for (int i = 1;i <= n;i++) {
		scanf("%d", &arr[i]);
		update(1, 1, n, i, arr[i]);
	}
	for (int i = 1;i <= max;i++) {
		sort(tree[i].begin(), tree[i].end());
	}
	for (int i = 0;i < m;i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		//a~b 구간에서 c번째 원소 구하기
		int left = -1e9;
		int right = 1e9;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (count(1, 1, n, a, b, mid) < c) left = mid + 1;
			else right = mid-1;
		}
		printf("%d\n", left);
	}

}