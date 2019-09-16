#include <cstdio>
#include <cmath>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int n, m;
int cost[51][2];
int main() {
	scanf("%d%d", &n, &m);
	int six_min = 1000;
	int one_min=1000;
	for (int i = 0;i < m;i++) {
		scanf("%d %d", &cost[i][0], &cost[i][1]);
		if (cost[i][0] < six_min) {
			six_min = cost[i][0];
		}
		if (cost[i][1] < one_min) {
			one_min = cost[i][1];
		}
	}
	printf("%d\n",min((n/6)*six_min, n/6*6*one_min)+ min(six_min, one_min * (n%6)));
}