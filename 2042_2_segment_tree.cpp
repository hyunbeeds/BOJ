#include <cstdio>
#include <cmath>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

int N, M, K;
vector<long long int> arr;
vector<long long int> tree;

// 2042만 붙어있는 파일은 인터넷에 많이 나온 코드이고
// 이 파일은 리프노드의 높이를 모두 갖게 해서 update시에 리프노드에 바로
// 접근할 수 있게 만들고, update하는 것은 부모노드로 올라가면서 update하는방식을 취해서
// 조금이라도 실행시간을 줄여보고자 하는 시도였습니다. 
// 사실 별차이가 나지 않았고, 오히려 메모리를 이 방법이 조금 더 쓰므로, 인터넷에서 검색이 가능한 쉬운 코드를 쓰는것이 바람직한 것 같습니다.  

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
	}// 리프 노드에 arr다 위치시킴
	
	// 자식 이용해서 다채워줌

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
			while (cur_node != 1) {	//올라가면서 합노드들 바꿔줌
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
