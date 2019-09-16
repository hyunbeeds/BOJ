#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

vector<pair<int, int> > arr;
int n;
int main() {
	scanf("%d", &n);
	int a, b;
	for (int i = 0;i < n;i++) {
		scanf("%d %d", &a, &b);
		arr.push_back(make_pair(a, b));
	}
	sort(arr.begin(), arr.end());
	for (int i = 0;i < n;i++) {
		printf("%d %d\n", arr[i].first,arr[i].second);
	}
}