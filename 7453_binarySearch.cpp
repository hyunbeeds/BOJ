#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

int N;
int a[4001];
int b[4001];
int c[4001];
int d[4001];
vector<int> ab;
vector<int> cd;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ab.push_back(a[i] + b[j]);
			cd.push_back(c[i] + d[j]);
		}
	}
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());
	long long int start, end;
	start = 0;
	end = cd.size() - 1;
	long long int sum;
	long long int cur_a, cur_b;
	long long int cnt_a, cnt_b;
	long long int ans = 0;

	while (start < ab.size() && end>=0) {
		sum = ab[start] + cd[end];
		if (sum > 0) {
			end--;
		}
		else if (sum < 0) {
			start++;
		}
		else if (sum == 0) {
			cur_a = ab[start];
			cnt_a = 0;
			while (start<ab.size() && cur_a == ab[start]) {
				cnt_a++;
				start++;
			}
			cur_b = cd[end];
			cnt_b = 0;
			while (end >= 0 && cur_b == cd[end]) {
				cnt_b++;
				end--;
			}
			ans += cnt_a*cnt_b;
		}
	}
	printf("%lld\n", ans);
}