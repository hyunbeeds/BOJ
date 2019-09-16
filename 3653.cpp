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
		i += (i & -i);	//마지막 1의자리에 1더해주기
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
			arr[i] = n - i + 1;	//처음 위치기록
		}
		int goal;
		for (int i = 0;i < m;i++) {
			scanf("%d", &goal);
			int cur;	//지금위치
			cur = arr[goal];
			// 현재위치~n+i 의 영화개수 세서 반환하면된다.
			printf("%d ", sum(n + i) - sum(cur));
			//그리고 위로 올린거 위치 바꿔준다.
			update(cur, -1);
			update(n + i + 1, 1);
			arr[goal] = n + i + 1;
		}printf("\n");
		
	}
}