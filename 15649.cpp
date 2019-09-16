#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)

using namespace std;
vector<int> visited;
vector<int> ans;
int n, m;
void recur(int cnt) {
	if (cnt == m) {
		for (int i = 0;i < ans.size();i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}
	cnt++;
	for (int i = 0;i < n;i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			ans.push_back(i+1);
			recur(cnt);
			ans.pop_back();
			visited[i] = 0;
		}
	}

}
int main() {
	scanf("%d%d", &n, &m);
	visited = vector<int>(n, 0);
	recur(0);
}