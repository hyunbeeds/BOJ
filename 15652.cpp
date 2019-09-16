#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;
int n, m;
vector<int> temp;
void print(int cnt, int cur) {
	if (cnt == m) {
		for (int i = 0;i < temp.size();i++) {
			printf("%d ", temp[i]);
		}printf("\n");
	}
	else {
		for (int i = cur;i <= n;i++) {
			temp.push_back(i);
			print(cnt + 1, i);
			temp.pop_back();
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	print(0, 1);
}