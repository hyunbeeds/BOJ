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
	// 자기보다 상대실력이 큰놈의 수를 세는 것이다.
	// ex) 내 상대실력이 2고 n이 8이라면,3,4,5,6,7번째 사람이 있는지 없는지 체크해서
	// 그 숫자를 다더한값을 반환해주면된다. 
	if (value < start) {
		return tree[cur_node];
	}
	else if(end < value || start==end){
		// 구하는 범위 안에 안들때!!
		return 0;
	}
	int mid = (start + end) / 2;
	return search(cur_node * 2, value, start, mid) + search(cur_node * 2 + 1, value, mid + 1, end);
}

int update(int cur_node,int value, int start, int end) {
	// 사람한명(상대 실력지수가 value)이 들어왔을때, 인덱스 트리 갱신!
	if (value < start || end < value) return tree[cur_node]; // 범위 벗어나면 그냥 리턴
	else if (start == end) return tree[cur_node] = 1; // 내가 찾는 value이면 1리턴

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
	}//segment 트리에 쓰기위해서 숫자를 치환
	//(상대실력,원래들어온 순서),
	//실력이 크면 더 달리기를 잘하는 것이다.
	sort(arr.begin(), arr.end(), cmp);
	// 원래들어온 순서대로 다시 복구해놓음
	// 원소 4개면 8, 7이면 16개의 node 생성
	tree = vector<int>(1 << (int)ceil(log2(N)) + 1);

	for (int i = 0; i < N; i++) {
		printf("%d\n", 1 + search(1, arr[i].first, 0, N-1));
		update(1, arr[i].first, 0, N - 1);
	}
}