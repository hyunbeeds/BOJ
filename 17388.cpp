#include <cstdio>
#pragma warning(disable:4996)

int main() {
	int arr[3];
	int min = 100;
	int min_index = 0;
	int sum = 0;
	for (int i = 0;i < 3;i++) {
		scanf("%d", &arr[i]);
		if (arr[i] < min) {
			min = arr[i];
			min_index = i;
		}
		sum += arr[i];
	}
	if (sum >= 100) {
		printf("OK\n");
	}
	else {
		if (min_index == 0) printf("Soongsil\n");
		else if (min_index == 1) printf("Korea\n");
		else if (min_index == 2) printf("Hanyang\n");
	}
}