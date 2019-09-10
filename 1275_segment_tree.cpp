/*#include <cstdio>
#include <cmath>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

int N, M;
vector<long long int> arr;
vector<long long int> tree;

long long int sum(int node, int left, int right, int start, int end) {
	// left~right�� �������� ���ϰ� ����
	// ���� ���� start~end
	if (end < left || right < start) { // ���� ��� ���
		return 0;
	}
	if (left <= start && end <= right) {// �����ȿ� ������ ������ ���
										//printf("[%d-%d] : %d\n", start, end, tree[node]);
		return tree[node];
	}
	int mid = (start + end) / 2;
	return sum(node * 2, left, right, start, mid) + sum(node * 2 + 1, left, right, mid + 1, end);
}

int main() {
	scanf("%d %d", &N, &M);
	arr = vector<long long int>(N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}
	int start = 1 << ((int)ceil(log2(N)));
	//printf("start : %d", start);
	tree = vector<long long int>(1 << ((int)ceil(log2(N)) + 1), 0);

	for (int i = start; i < start + arr.size(); i++) {
		tree[i] = arr[i - start];
	}// ���� ��忡 arr�� ��ġ��Ŵ

	 // �ڽ� �̿��ؼ� ��ä����

	for (int i = start - 1; i >= 1; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}


	long long int a, b, c, d;
	for (int i = 0; i < M; i++) {
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		if (a < b) {
			printf("%lld\n", sum(1, a, b, 1, start));
		}
		else {
			printf("%lld\n", sum(1, b, a, 1, start));
		}
		long long int dif = d - arr[c - 1];
		int cur_node = start + c - 1;
		tree[cur_node] = d;
		while (cur_node != 1) {	//�ö󰡸鼭 �ճ��� �ٲ���
			cur_node = cur_node / 2;
			tree[cur_node] += dif;
		}
		arr[c - 1] = d;
	}
}
*/