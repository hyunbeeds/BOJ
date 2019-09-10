#include <stdio.h>
#pragma warning(disable:4996)

int n, k;

int binary_search(int left, int right) {
	int mid, ans;
	while (left <= right) {
		int cnt = 0;
		mid = (left + right) / 2;
		for (int i = 1;i <= n;i++) {
			if (n > (mid / i)) cnt += mid / i;
			else cnt += n;
		}
		if (cnt < k) left = mid + 1;
		else {
			right = mid - 1;
			ans = mid;
		}
	}
	return ans;
}

int main() {
	scanf("%d", &n);		//�迭�� ũ�� n
	scanf("%d", &k);		//ã������ k��°����
	printf("%d\n", binary_search(1, k));
	return 0;
}