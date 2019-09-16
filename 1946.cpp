#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

int main() {
	int test, n;
	scanf("%d", &test);
	for (int t = 0;t < test;t++) {
		scanf("%d", &n);
		int a, b;
		vector<pair<int, int> > arr;
		for (int i = 0;i < n;i++) {
			scanf("%d%d", &a, &b);
			arr.push_back(make_pair(a, b));
		}
		sort(arr.begin(), arr.end());
		int min = n+1;
		int cnt = 0;
		for (int i = 0;i < n;i++) {
			if (min > arr[i].second) {
				min = arr[i].second;
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
}