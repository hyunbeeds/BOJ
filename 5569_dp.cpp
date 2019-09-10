/*#include <cstdio>
#pragma warning(disable:4996)

int main() {
	int w, h;
	int arr[101][101][4] = { 0, };
	//arr[i][j][xx]
	// x->0이면 위로, 1이면 오른쪽
	// 00->0 이면 위위를 통해서 여기로 왔다는 것이고,
	// 01->1 이면 위오른쪽을 통해서 여기로 왔다는 것이고,
	// 10->2 이면 오른쪽위를 통해서 여기로 왔다는 것이고,
	// 11->3이면 오른쪽오른쪽을 통해서 여기로 왔다는 것이다. 
	scanf("%d %d", &w, &h);
	// i==h, j==w면 종료
	for (int i = 2; i <= h; i++) arr[i][1][0] = 1;
	for (int j = 2; j <= w; j++) arr[1][j][3] = 1;

	for (int i = 2; i <= h; i++) {
		for (int j = 2; j <= w; j++) {
			arr[i][j][0] = (arr[i-1][j][0]+arr[i-1][j][2]) % 100000;
			arr[i][j][1] = arr[i][j-1][0];
			arr[i][j][2] = arr[i-1][j][3];
			arr[i][j][3] = (arr[i][j-1][1]+arr[i][j-1][3]) %100000;
		}
	}
	printf("%d\n", (arr[h][w][0] + arr[h][w][1] + arr[h][w][2] + arr[h][w][3]) % 100000);
	return 0;
}*/