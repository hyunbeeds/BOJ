#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int N,S;

vector<long long int> tree;
vector<int> arr;
bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

long long int sum(int cur_node, int start, int end, int left, int right) {
// cur_node의 담당범위가  start-end고, 구해야하는 합의 범위는 left-right이다.
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[cur_node];
	}
	return sum(cur_node * 2, start, (start + end) / 2, left, right) + sum(cur_node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int update(int cur_node,int value, int start, int end) {
	// 사람한명(상대 실력지수가 value)이 들어왔을때, 인덱스 트리 갱신!
	if (start == end) return tree[cur_node] = arr[start];
	else {
		int mid = (start + end) / 2;
		return tree[cur_node] = update(cur_node * 2, value, start, mid) + update(cur_node * 2 + 1, value, mid + 1, end);
	}
}
int main() {
	int n;
	scanf("%d %d", &N, &S);
	int temp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		arr.push_back(temp);
	}
	int sum;
	int cnt;
	int ans = 1000000;
	int start = 0;
	int end = 0;
	sum = arr[0];
	while (1) {
		if (sum < S) {
			end++;
			if (end >= N) break;
			sum += arr[end];
		}
		else {
			if (ans > end - start + 1) ans = end - start + 1;
			if (ans == 1) break;
			sum -= arr[start];
			start++;
		}
	}
	if (ans == 1000000) {
		printf("0\n");
		return 0;
	}
	printf("%d\n", ans);
	return 0;
}