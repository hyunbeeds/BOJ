#include <cstdio>
#include <algorithm>

#pragma warning(disable:4996)

int main() {
	char gear[4][9];
	int command;
	for (int i = 0;i < 4;i++) {
		scanf("%s", gear[i]);
	}
	scanf("%d", &command);
	for (int i = 0;i < command;i++) {
		int gear_num, cmd;
		int gear_cmd[4] = { 0, };
		scanf("%d %d", &gear_num, &cmd);
		gear_num--;
		gear_cmd[gear_num] = cmd;

		for (int left = gear_num-1;left >= 0;left--) {
			int right = left + 1;
			if (gear[left][2] != gear[right][6]) {
				gear_cmd[left] = (-1)*gear_cmd[right];
			}
			else {
				break;
			}
		}
		for (int right = gear_num+1;right <= 3;right++) {
			int left = right - 1;
			if (gear[left][2] != gear[right][6]) {
				gear_cmd[right] = (-1)*gear_cmd[left];
			}
			else {
				break;
			}
		}

		//rotate
		for (int k = 0;k < 4;k++) {
			if (gear_cmd[k] == 1) {		//시계방향
				char temp = gear[k][7];
				for (int j = 7;j >=1;j--) {
					gear[k][j] = gear[k][j-1];
				}
				gear[k][0] = temp;
			}
			else if(gear_cmd[k]==-1){	//반시계방향
				char temp = gear[k][0];
				for (int j = 0;j < 7;j++) {
					gear[k][j] = gear[k][j+1];
				}
				gear[k][7] = temp;
			}
		}
	}
	int result = 0;
	for (int i = 0;i < 4;i++) {
		if (gear[i][0] == '1')
			result += (1 << i);
	}
	printf("%d\n", result);
}