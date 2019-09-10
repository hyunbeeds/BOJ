#include <stdio.h>
#pragma warning(disable:4996)

int connect[1001];
int visited[1001];
int n;
int cycle = 0;

void dfs(int current, int first) {
	if (connect[current] == first) {
		cycle++;
		return;
	}
	else {
		if(visited[connect[current]]==0)
		dfs(connect[current], first);
	}
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d", &n);
		for (int i = 1;i <= n;i++) {
			scanf("%d", &connect[i]);
		}

		for (int i = 1;i <= n;i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				dfs(i, i);
			}
		}
		printf("%d\n", cycle);
		for (int i = 1;i <= n;i++) {
			visited[i] = 0;
			connect[i] = 0;
			cycle = 0;
		}
	}
}