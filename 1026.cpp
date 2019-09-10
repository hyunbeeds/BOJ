#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

vector<int> a;
vector<int> b;

int main() {
	int n,temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		a.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		b.push_back(temp);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[n-1- i];
	}
	printf("%d\n",sum);
}
