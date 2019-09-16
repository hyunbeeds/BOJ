#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int arr[100001];
vector<int> binary_tree;
int n, m;

int init(int node, int left, int right) {
	//������ ��ġ : node
	//left~right�� ���ݺ�������
	if (left == right) {
		if (left <= n) {
			binary_tree[node] = arr[left];
		}
		else {
			binary_tree[node] = 1000000000;
		}
		return binary_tree[node];
	}
	int mid = (left + right) / 2;
	return binary_tree[node] = min(init(node * 2, left, mid), init(node * 2 + 1, mid + 1, right));
}
int minimize(int node, int left, int right, int start, int end) {
	//���� node, left~right��������
	//ã�����ϴ� ���� : start~end
	//1.������ ���� ���ΰ��
	if (start <= left && right <= end) {
		return binary_tree[node];
	}
	//���� ���ΰ��
	if (end < left || right < start) {
		return 1000000000;
	}

	int mid=(left+right)/2;
	return min(minimize(node * 2, left, mid, start, end), minimize(node * 2 + 1, mid + 1, right, start, end));
}
int main() {

	scanf("%d %d", &n, &m);
	for (int i = 1;i <= n;i++) {
		scanf("%d", &arr[i]);
	}
	
	binary_tree = vector<int>(1 << ((int)ceil(log2(100000)) + 1), -1);
	int start = 1 << (int)ceil(log2(100000));
	//�ʱ�ȭ
	init(1, 1, start);
	int a, b;
	for (int i = 0;i < m;i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", minimize(1, 1, start, a, b));
	}
}