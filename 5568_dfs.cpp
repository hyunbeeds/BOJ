#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int n, k;
int ans[1000000] = { 0, };
int card[11];
int sel[5];	
int visited[11] = { 0, };
set<int> results;


void dfs(int cnt) {
	if (cnt == k) {
		int result = 0;
		for (int i = 0; i < k; i++) {
			if (sel[i] < 10)
				result = result * 10 + sel[i];
			else
				result = result * 100 + sel[i];
		}
		results.insert(result);
	}
	else {
		for (int i = 0; i < n; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				sel[cnt] = card[i];
				dfs(cnt + 1);
				visited[i] = 0;
			}
		}
	}
}

int main() {

	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &card[i]);
	}
	dfs(0);
	printf("%d\n", results.size());
}