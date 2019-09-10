#include <cstdio>
#include <cmath>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

int N, M, K;
vector<int> arr;
vector<long long int> tree;

long long int init(int node, int start, int end){
	//node -> arr의 몇번째 node인가, update하고 싶은 value의 값
	//start~end 현재 보고있는 구간
	if(start==end){
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);

}
void update(int node, int index, int start, int end, long long int diff) {
	//index를 포함하는 노드들은 diff만큼 다 더해준다. 
	if (index<start || end<index) { //범위 벗어난 경우
		return;
	}
	printf("update : [%d-%d] : %lld->%lld\n", start, end, tree[node], tree[node] + diff);
	tree[node] =tree[node]+ diff;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(node * 2, index, start, mid, diff);
	update(node * 2+1, index, mid+1, end, diff);
}
long long int sum(int node, int left, int right, int start, int end) {
	// left~right의 구간합을 구하고 싶음
	// 현재 구간 start~end
	if (end < left || right < start) { // 구간 벗어난 경우
		return 0;
	}
	if (left<=start && end<=right) {// 구간안에 완전히 들어오는 경우
		//printf("[%d-%d] : %d\n", start, end, tree[node]);
		return tree[node];
	}
	int mid = (start + end) / 2;
	return sum(node * 2, left, right, start, mid) + sum(node * 2+1, left, right, mid + 1, end);
}
int main() {
	scanf("%d %d %d", &N, &M, &K);
	arr = vector<int>(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	tree = vector<long long int>(1 << ((int)ceil(log2(N)) + 1));
	init(1, 0, arr.size()-1);
	int a, b;
	long long int c;
	for (int i = 0; i < M + K; i++) {
		scanf("%d %d %lld", &a, &b, &c);
		if (a == 1) {
			update(1, b-1, 0, arr.size()-1, c - arr[b-1]);
			arr[b-1] = c;
			for (int j = 0; j < arr.size(); j++) {
				printf("%d ", arr[j]);
			}printf("\n");
			for (int j = 0; j < tree.size(); j++) {
				printf("%lld ", tree[j]);
			}printf("\n");
		}
		else if (a == 2) {
			printf("%lld\n", sum(1, b-1, c-1, 0, arr.size()-1));
		}
	}
}
