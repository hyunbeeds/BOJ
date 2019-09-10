/*#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;


int main() {
	int n, m;
	int a[1001];
	int b[1001];
	vector<long long int> sum_a;
	vector<long long int> sum_b;

	long long int goal;
	scanf("%lld", &goal);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	long long int sum;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			sum_a.push_back(sum);
		}
	}
	for (int i = 0; i < m; i++) {
		sum = 0;
		for (int j = i; j < m; j++) {
			sum += b[j];
			sum_b.push_back(sum);
		}
	}
	sort(sum_a.begin(), sum_a.end());
	sort(sum_b.begin(), sum_b.end());

	long long int start = 0;
	long long int end = sum_b.size() - 1;
	long long int cur_a, cur_b;
	long long int cnt_a, cnt_b;
	long long int ans=0;
	while (start<sum_a.size() && end>=0) {
		sum = sum_a[start] + sum_b[end];
		if (sum > goal) {
			end--;
		}
		else if (sum < goal) {
			start++;
		}
		else if (sum == goal) {
			cur_a = sum_a[start];
			cnt_a = 0;
			while (start<sum_a.size() && cur_a == sum_a[start]) {
				cnt_a++;
				start++;
			}
			cur_b = sum_b[end];
			cnt_b = 0;
			while (end >= 0 && cur_b == sum_b[end]) {
				cnt_b++;
				end--;
			}
			ans += cnt_a*cnt_b;
		}
	}
	printf("%lld\n", ans);

}*/