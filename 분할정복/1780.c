#include <stdio.h>
#pragma warning(disable:4996)

int paper[2200][2200];
int n;
int ar[3]; //ar[0] 0개수 ar[1] 1개수 ar[2] -1개수

void cut(int sx, int sy, int len) {
	int next = len / 3;
	int first = paper[sx][sy];
	if (len == 1) {
		if (first == 1) {
			ar[1]++;
		}
		else if (first == 0) {
			ar[0]++;
		}
		else {
			ar[2]++;
		}
		return;
	}

	for (int i = sx;i <= sx+len-1;i++) {
		for (int j = sy;j <= sy+len-1;j++) {
			if (paper[i][j] != first) {
				goto end;
			}
		}
	}

	if (first == 1) {
		ar[1]++;
	}
	else if (first == 0) {
		ar[0]++;
	}
	else {
		ar[2]++;
	}
	return;

	end:;
		cut(sx, sy, next);
		cut(sx, sy+next, next);
		cut(sx, sy+next+next, next);

		cut(sx+next, sy, next);
		cut(sx+next, sy+next, next);
		cut(sx+next, sy+next+next, next);

		cut(sx+next+next, sy, next);
		cut(sx+next+next, sy+next, next);
		cut(sx+next+next, sy+next+next, next);
}
int main() {
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			scanf("%d", &paper[i][j]);
		}
	}
	for (int i = 0;i < 3;i++) {
		ar[i] = 0;
	}
	cut(1, 1, n);
	printf("%d\n%d\n%d\n", ar[2], ar[0], ar[1]);
}