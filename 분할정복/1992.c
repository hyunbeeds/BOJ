#include <stdio.h>
char Matrix[64][64];

void exec(int size, int x, int y)
{
	int i, j;
	int total0 = size*size, total1 = size*size;

	//	printf("\n(%d, %d) size:%d : ", x, y, size);
	for (i = x; i < x + size; i++) {
		for (j = y; j < y + size; j++) {
			if (Matrix[i][j] == '0') {
				//printf("0");
				total0--;
			}
			else {
				//printf("1");
				total1--;
			}
		}
	}


	if (total0 == 0) {
		printf("0");
		return;
	}
	else if (total1 == 0) {
		printf("1");
		return;
	}
	else {
		printf("(");
		exec(size / 2, x, y);
		exec(size / 2, x, y + size / 2);
		exec(size / 2, x + size / 2, y);
		exec(size / 2, x + size / 2, y + size / 2);
		printf(")");
	}
}

int main()
{
	int i, j, N;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", Matrix[i]);
	}

	exec(N, 0, 0);

}