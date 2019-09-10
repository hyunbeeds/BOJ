#include <stdio.h>
#pragma warning(disable:4996)
int ar[3];
int ans;

int main() {
	scanf("%d %d %d", &ar[0], &ar[1], &ar[2]);
	if ((ar[1] - ar[0]) > (ar[2] - ar[1])) ans = ar[1] - ar[0];
	else ans = ar[2] - ar[1];
	printf("%d\n", ans - 1);
}