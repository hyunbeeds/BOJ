#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int arr[1000001];
vector<long long int> tree;
int n;
long long int sum(int node, int left, int right, int start, int end) {
	// left~right의 구간합을 구하고 싶음
	// 현재 구간 start~end
	if (end < left || right < start) { // 구간 벗어난 경우
		return 0;
	}
	if (left <= start && end <= right) {// 구간안에 완전히 들어오는 경우
										//printf("[%d-%d] : %d\n", start, end, tree[node]);
		return tree[node];
	}
	int mid = (start + end) / 2;
	return sum(node * 2, left, right, start, mid) + sum(node * 2 + 1, left, right, mid + 1, end);
}

int main() {
	scanf("%d", &n);
	int temp;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &temp);
		arr[temp] = i;
	}
	tree = vector<long long int>(1 << (int)(ceil(log2(n)) + 1), 0);
	int start = 1 << (int)(ceil(log2(n)));
	long long int cnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &temp);
		int cur=arr[temp];
		//나보다 빨리 들어온 놈들중에서 나보다 큰놈의 숫자를 세서 더해주면된다. 
		//binary index tree 이용
		cnt += sum(1, cur, start, 1, start);
		//binary tree update
		cur = start + cur-1;
		tree[cur]++;
		while (cur !=1) {
			cur = cur / 2;
			tree[cur]++;
		}
	}
	printf("%lld\n", cnt);
}