#include <cstdio>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int N; // 선수의 수
int map[21][21];

int temp[21];
bool check[21] = { false, };

int answer = 987654321;
int flag = 0;



void dfs(int x, int from) {
	if (x >= N / 2) { // 선수 N명중 N/2명을 뽑은 경우
		vector<int> one, two;

		for (int i = 0; i < N; i++) { // one팀과 two팀을 나눈다.
			if (check[i] == true) {
				one.push_back(i);
			}
			else {
				two.push_back(i);
			}
		}
		int team1_score = 0, team2_score = 0; // 각 팀의 시너지 점수를 각각 구한다.
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

		if (abs(team1_score-team2_score) < answer) { // 차이가 최소가 되는 답이 정답
			answer = abs(team1_score-team2_score);
		}
	}
	else {
		for (int i = from; i < N; i++) {
			if (check[i] == false) { // i를 등록하지 않았다면
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