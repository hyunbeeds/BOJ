#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;


int main() {
	long long int x, y;
	long long int z;
	while (scanf("%lld %lld", &x, &y) != EOF) {
		z = (y*100)/x;
		long long int start = 0;
		long long int end = 9223372036854770;
		long long int ans = 9223372036854770;
		long long int mid = 0;
		long long int new_z;
		if (z == 99) {
			printf("-1\n");
			return 0;
		}
		while (start <= end) {
			mid = (start + end) / 2;
			new_z = ((y + mid) * 100) / (x + mid);
			if (new_z > z) {
				end = mid - 1;
				if (ans > mid) ans = mid;
			}
			else if (new_z <= z) {
				start = mid + 1;
			}
		}
		if (ans == 9223372036854770) printf("-1\n");
		else printf("%lld\n", ans);
	}
}