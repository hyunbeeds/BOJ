#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int N;
vector< pair<long long int,int> > arr;
vector<int> order;
vector<int> tree;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int search(int cur_node, int value, int start, int end) {
	// �ڱ⺸�� ���Ƿ��� ū���� ���� ���� ���̴�.
	// ex) �� ���Ƿ��� 2�� n�� 8�̶��,3,4,5,6,7��° ����� �ִ��� ������ üũ�ؼ�
	// �� ���ڸ� �ٴ��Ѱ��� ��ȯ���ָ�ȴ�. 
	if (value < start) {
		return tree[cur_node];
	}
	else if(end < value || start==end){
		// ���ϴ� ���� �ȿ� �ȵ鶧!!
		return 0;
	}
	int mid = (start + end) / 2;
	return search(cur_node * 2, value, start, mid) + search(cur_node * 2 + 1, value, mid + 1, end);
}

int update(int cur_node,int value, int start, int end) {
	// ����Ѹ�(��� �Ƿ������� value)�� ��������, �ε��� Ʈ�� ����!
	if (value < start || end < value) return tree[cur_node]; // ���� ����� �׳� ����
	else if (start == end) return tree[cur_node] = 1; // ���� ã�� value�̸� 1����

	int mid = (start + end) / 2;
	return tree[cur_node] = update(cur_node * 2, value, start, mid) + update(cur_node * 2 + 1, value, mid + 1, end);

}
int main() {
	int n;
	scanf("%d", &N);
	long long int temp;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &temp);
		arr.push_back(make_pair(temp,i));
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		arr[i].first = i;
	}//segment Ʈ���� �������ؼ� ���ڸ� ġȯ
	//(���Ƿ�,�������� ����),
	//�Ƿ��� ũ�� �� �޸��⸦ ���ϴ� ���̴�.
	sort(arr.begin(), arr.end(), cmp);
	// �������� ������� �ٽ� �����س���
	// ���� 4���� 8, 7�̸� 16���� node ����
	tree = vector<int>(1 << (int)ceil(log2(N)) + 1);

	for (int i = 0; i < N; i++) {
		printf("%d\n", 1 + search(1, arr[i].first, 0, N-1));
		update(1, arr[i].first, 0, N - 1);
	}
}