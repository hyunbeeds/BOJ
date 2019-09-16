#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

long long int arr[300001];
vector<long long int> binary_tree;
int n, m;

long long int init(int node, int left, int right) {
	//현재노드 위치 : node
	//left~right를 지금보고있음
	if (left == right) {
		if (left > n) {
			binary_tree[node] = 0;
		}
		else if (left%2==1) {
			binary_tree[node] = arr[left];
		}
		else {
			binary_tree[node] = arr[left] * (-1);
		}
		return binary_tree[node];
	}
	int mid = (left + right) / 2;
	return binary_tree[node] = init(node * 2, left, mid)+init(node * 2 + 1, mid + 1, right);
}
long long int sum(int node, int left, int right, int start, int end) {
	//현재 node, left~right보고있음
	//찾고자하는 범위 : start~end
	//1.완전히 범위 안인경우
	if (start <= left && right <= end) {
		return binary_tree[node];
	}
	//범위 밖인경우
	if (end < left || right < start) {
		return 0;
	}

	int mid = (left + right) / 2;
	return sum(node * 2, left, mid, start, end)+sum(node * 2 + 1, mid + 1, right, start, end);
}
int main() {

	scanf("%d %d", &n, &m);
	for (int i = 1;i <= n;i++) {
		scanf("%lld", &arr[i]);
	}

	binary_tree = vector<long long int>(1 << ((int)ceil(log2(300000)) + 1), -1);
	int start = 1 << (int)ceil(log2(300000));
	//초기화
	init(1, 1, start);

	long long int order,a, b;
	for (int i = 0;i < m;i++) {
		scanf("%lld %lld %lld", &order, &a, &b);
		if (order == 1) {
			printf("%lld\n", abs(sum(1, 1, start, a, b)));
		}
		else if (order == 2) {
			if (a % 2 == 1) {
				//걍 더해주면됨
				long long int cur = start + a - 1;
				while (cur >= 1) {
					binary_tree[cur] += b;
					cur /= 2;
				}
			}
			else { // diff*(-1)
				long long int cur = start + a - 1;
				while (cur >= 1) {
					binary_tree[cur] -= b;
					cur /= 2;
				}
			}
		}
	}
}