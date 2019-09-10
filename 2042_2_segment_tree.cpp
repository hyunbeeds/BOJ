#include <cstdio>
#include <cmath>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

int N, M, K;
vector<long long int> arr;
vector<long long int> tree;

// 2042�� �پ��ִ� ������ ���ͳݿ� ���� ���� �ڵ��̰�
// �� ������ ��������� ���̸� ��� ���� �ؼ� update�ÿ� ������忡 �ٷ�
// ������ �� �ְ� �����, update�ϴ� ���� �θ���� �ö󰡸鼭 update�ϴ¹���� ���ؼ�
// �����̶� ����ð��� �ٿ������� �ϴ� �õ������ϴ�. 
// ��� �����̰� ���� �ʾҰ�, ������ �޸𸮸� �� ����� ���� �� ���Ƿ�, ���ͳݿ��� �˻��� ������ ���� �ڵ带 ���°��� �ٶ����� �� �����ϴ�.  

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
	scanf("%d %d %d", &N, &M, &K);
	arr = vector<long long int>(N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}
	int start = 1 << ((int)ceil(log2(N)));
	//printf("start : %d", start);
	tree = vector<long long int>(1 << ((int)ceil(log2(N)) + 1),0);
	
	for (int i = start; i < start + arr.size(); i++) {
		tree[i] = arr[i - start];
	}// ���� ��忡 arr�� ��ġ��Ŵ
	
	// �ڽ� �̿��ؼ� ��ä����

	for (int i = start - 1; i >= 1; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	
	for (int j = 0; j < tree.size(); j++) {
		printf("%lld ", tree[j]);
	}printf("\n");


	int a, b;
	long long int c;
	for (int i = 0; i < M + K; i++) {
		scanf("%d %d %lld", &a, &b, &c);
		if (a == 1) {
			long long int dif= c - arr[b - 1];
			int cur_node = start + b - 1;
			tree[cur_node] = c;
			while (cur_node != 1) {	//�ö󰡸鼭 �ճ��� �ٲ���
				cur_node = cur_node / 2;
				tree[cur_node] += dif;
			}
			arr[b - 1] = c;
			
			for (int j = 0; j < arr.size(); j++) {
				printf("%d ", arr[j]);
			}printf("\n");
			for (int j = 0; j < tree.size(); j++) {
				printf("%lld ", tree[j]);
			}printf("\n");
		}
		else if (a == 2) {
			printf("%lld\n", sum(1, b , c, 1, start));
		}
	}
}
