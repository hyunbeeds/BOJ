#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

vector<int> arr;
vector<int> sums;
int n, m, temp;
int main() {
	scanf("%d%d", &n, &m);
	arr.push_back(0);

	for (int i = 0;i < n;i++) {
		scanf("%d", &temp);
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	int sum = 0;
	for (int i = 0;i <= n;i++) {
		sum += arr[i];
		sums.push_back(sum);
	}

	int start, end;
	for (int i = 0;i < m;i++) {
		scanf("%d%d", &start, &end);
		printf("%d\n", sums[end] - sums[start - 1]);
	}
	

}