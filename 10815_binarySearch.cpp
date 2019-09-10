#include <cstdio>
#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;
int M, N;
int num[500001];

int check(int question) {
	int start = 0;
	int end = M-1;
	
	while (start <= end) {
		int mid = (start + end) / 2;
		if (num[mid] == question) return 1;
		else if (question < num[mid]) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return 0;
}
int main() {

	scanf("%d", &M);
	for (int i = 0;i < M;i++) {
		scanf("%d", &num[i]);
	}
	sort(num,num+M);
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		int temp;
		scanf("%d", &temp);
		printf("%d ", check(temp));
	}
}
