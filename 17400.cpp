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
	//������ ��ġ : node
	//left~right�� ���ݺ�������
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
	//���� node, left~right��������
	//ã�����ϴ� ���� : start~end
	//1.������ ���� ���ΰ��
	if (start <= left && right <= end) {
		return binary_tree[node];
	}
	//���� ���ΰ��
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
	//�ʱ�ȭ
	init(1, 1, start);

	long long int order,a, b;
	for (int i = 0;i < m;i++) {
		scanf("%lld %lld %lld", &order, &a, &b);
		if (order == 1) {
			printf("%lld\n", abs(sum(1, 1, start, a, b)));
		}
		else if (order == 2) {
			if (a % 2 == 1) {
				//�� �����ָ��
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