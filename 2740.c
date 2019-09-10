#include <stdio.h>
#pragma warning(disable:4996)
int first[101][101] = { 0 };
int second[101][101] = { 0 };
int result[101][101] = { 0 };

int main() {
	int first_hang, first_rul,second_hang,second_rul;
	
	scanf("%d", &first_hang);
	scanf("%d", &first_rul);
	for (int i = 0;i < first_hang;i++) {
		for(int j=0;j<first_rul;j++)
		scanf("%d", &first[i][j]);
	}

	scanf("%d", &second_hang);
	scanf("%d", &second_rul);
	for (int i = 0;i < second_hang;i++) {
		for (int j = 0;j<second_rul;j++)
			scanf("%d", &second[i][j]);
	}

	for (int i = 0;i < first_hang;i++) {
		for (int j = 0;j < second_rul;j++) {
			for (int k = 0;k < first_rul;k++) {
				result[i][j] = result[i][j] + first[i][k] * second[k][j];
			}
		}
	}

	for (int i = 0;i < first_hang;i++) {
		for (int j = 0;j < second_rul;j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}