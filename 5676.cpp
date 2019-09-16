#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int n, k;
int arr[100001];
char answer[100001];
vector<int> tree;
int init(int node, int left, int right) {
	if (left == right) {
		return tree[node] = arr[left];
	}
	int mid = (left + right) / 2;
	return tree[node] = init(node * 2, left, mid) * init(node * 2 + 1, mid + 1, right);
}
int update(int node, int left, int right, int index, int change) {
	// 범위밖인경우
	if (index < left || right < index) {
		return tree[node];
	}
	//범위안인 경우
	if (left == right) {
		if (left == index) {
			return tree[node] = change;
		}
		return tree[node];
	}
	int mid = (left + right) / 2;
	return tree[node] = update(node * 2, left, mid, index, change) * update(node * 2 + 1, mid+1, right, index, change);
}
int sum(int node, int left, int right, int start, int end) {
	//start~end범위 결과 알고싶음
	//아예안쪽
	if (start <= left && right <= end) {
		return tree[node];
	}
	//아예바깥
	if (right < start || end<left) {
		return 1;
	}

	if (left == right) return tree[node];
	int mid = (left + right) / 2;
	return sum(node * 2, left, mid, start, end) * sum(node * 2 + 1, mid+1, right, start, end);
}
int main() {
	while(scanf("%d%d", &n, &k)!=EOF){
		for (int i = 1;i <= n;i++) {
			scanf("%d", &arr[i]);
			if (arr[i] > 0) {
				arr[i] = 1;
			}
			else if (arr[i] < 0) {
				arr[i] = -1;
			}
		}
		tree = vector<int>(1 << ((int)ceil(log2(n)) + 1), 1);
		init(1, 1, n);
		char order;
		int a, b;
		int cnt = 0;
		for (int i = 0;i < k;i++) {
			getchar();
			scanf("%c%d%d", &order, &a, &b);
			if (order == 'C') {//update
				if (b > 0)b = 1;
				else if (b < 0)	b = -1;
				update(1, 1, n, a, b);
			}
			else if (order == 'P') {	// 결과출력
				int result = sum(1, 1, n, a, b);
				if (result == 1) {
					answer[cnt] = '+';
				}
				else if (result == 0) {
					answer[cnt] = '0';
				}
				else {
					answer[cnt] = '-';
				}cnt++;
			}
		}
		for (int i = 0;i < cnt;i++) {
			printf("%c", answer[i]);
		}printf("\n");

	}
}