#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

bool pal[2002][2002];
int arr[2002];
int n,m;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		pal[i][i] = true;
	}
	for (int i = 1; i <= n; i++) {
		pal[i][i + 1] = (arr[i] == arr[i + 1]);
	}

	for (int s = 3; s <= n; s++) {
		for (int i = 1; i <= n-s+1; i++) {
			pal[i][i+s-1] = (pal[i + 1][i+s-2] && (arr[i] == arr[i+s-1]));
			// 양끝이 같고, 그 중간이 palindrome이면 palindrome
		}
	}
	scanf("%d", &m);
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", pal[a][b]);
	}
}