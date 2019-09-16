#include <cstdio>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int N; // ������ ��
int map[21][21];

int temp[21];
bool check[21] = { false, };

int answer = 987654321;
int flag = 0;



void dfs(int x, int from) {
	if (x >= N / 2) { // ���� N���� N/2���� ���� ���
		vector<int> one, two;

		for (int i = 0; i < N; i++) { // one���� two���� ������.
			if (check[i] == true) {
				one.push_back(i);
			}
			else {
				two.push_back(i);
			}
		}
		int team1_score = 0, team2_score = 0; // �� ���� �ó��� ������ ���� ���Ѵ�.
		for (int i = 0; i < N / 2; i++) { // 1 2
			for (int j = i + 1; j < N / 2; j++) {
				if (i != j) {
					team1_score += map[one[i]][one[j]];
					team1_score += map[one[j]][one[i]];

					team2_score += map[two[i]][two[j]];
					team2_score += map[two[j]][two[i]];
				}
			}
		}

		if (abs(team1_score-team2_score) < answer) { // ���̰� �ּҰ� �Ǵ� ���� ����
			answer = abs(team1_score-team2_score);
		}
	}
	else {
		for (int i = from; i < N; i++) {
			if (check[i] == false) { // i�� ������� �ʾҴٸ�
				check[i] = true;
				temp[x] = i;
				dfs(x + 1, i + 1);
				check[i] = false;
			}
		}
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dfs(0, 0);

	printf("%d\n", answer);

	return 0;
}