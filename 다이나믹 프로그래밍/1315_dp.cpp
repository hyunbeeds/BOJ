#include <cstdio>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

int stat[1001][1001];	//stat[x][y], str x, int y 일때 얻는 보상들 합
bool can[1001][1001];

int main() {
	int n;
	int answer = 0;

	int str[101];
	int intp[101];
	int pnt[101];
	scanf("%d", &n);

	for (int i = 0;i < n;i++) {
		scanf("%d %d %d", &str[i], &intp[i], &pnt[i]);
	}
	for (int s = 1;s <= 1000;s++) {
		for (int i = 1;i <= 1000;i++) {
			stat[s][i] = 2 - s - i;
			int cnt = 0;
			for (int x = 0;x < n;x++) {
				if (str[i] <= s || intp[i] <= i) {	//깰수있는 퀘스트들 다깨서 포인트얻음
					stat[s][i] += pnt[i];
					cnt++;
				}
			}
			if ((s == 1 && i == 1) || (s > 1 && can[s - 1][i] && stat[s - 1][i] > 0) || i > 1 && can[s][i - 1] && stat[s][i - 1] > 0) {
				can[s][i] = true;
			}
			if (can[s][i] && answer < cnt) answer = cnt;
		}
	}
	printf("%d\n", answer);

}