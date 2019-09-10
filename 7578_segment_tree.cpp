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
		//������ ���� ���� ����߿��� ������ ū���� ���ڸ� ���� �����ָ�ȴ�. 
		//binary index tree �̿�
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