#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int seq[5000001];

int main() {
	int n, l, min, min_num, idx, temp;
	scanf("%d", &n);
	scanf("%d", &l);
	scanf("%d", &temp);
	seq[0] = temp;
	min = temp;
	min_num = 0;

	printf("%d ", seq[0]);
	for (int i = 1;i < n;i++) {
		scanf("%d", &temp);
		idx = i%l;
		seq[idx] = temp;

		if (idx == min_num) {	//ÀÌ·²¶§´Â ´ÙÃ£¾ÆºÁ¾ßµÊ
			min = seq[0];
			min_num = 0;
			for (int k = 1;k < l;k++) {
				if (seq[k] < min) {
					min = seq[k];
					min_num = k;
				}
			}
		}
		else {
			if (temp <= min) {
				min = temp;
				min_num = idx;
			}
		}

		printf("%d ", min);
	}
}