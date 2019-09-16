#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;
int test, n, m;
int tree_size;
vector<int> arr;
vector<int> tree;
void update(int i, int diff) {
	while (i < tree.size()) {
		tree[i] += diff;
		i += (i & -i);	//������ 1���ڸ��� 1�����ֱ�
						//ex) 1101-> 1110-> 10000
						//ex) 11-> 100-> 1000-> 10000
	}
}
int sum(int i) {
	int ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}
int main() {
	scanf("%d", &test);
	for (int t = 0;t < test;t++) {
		scanf("%d%d", &n, &m);
		arr = vector<int>(n+1);	
		tree = vector<int>(n+m+2);
	
		for (int i = 1;i <= n;i++) {
			update(i, 1);
			arr[i] = n - i + 1;	//ó�� ��ġ���
		}
		int goal;
		for (int i = 0;i < m;i++) {
			scanf("%d", &goal);
			int cur;	//������ġ
			cur = arr[goal];
			// ������ġ~n+i �� ��ȭ���� ���� ��ȯ�ϸ�ȴ�.
			printf("%d ", sum(n + i) - sum(cur));
			//�׸��� ���� �ø��� ��ġ �ٲ��ش�.
			update(cur, -1);
			update(n + i + 1, 1);
			arr[goal] = n + i + 1;
		}printf("\n");
		
	}
}