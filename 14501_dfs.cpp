#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

struct work {
	int day;
	int cost;
};

struct work work[16];
int dp[16];
int N;
int max = 0;

//current->지금 날짜, money-> 현재 벌은 돈 
void dfs(int current, int money) {
	if (money > max) {
		max = money;
	}

	if (current >= N+1) {		//이상한곳
		return;
	}

	//current날짜 일을 하느냐 안하느냐
	if (work[current].day + current <= N + 1) {	//한다
		dfs(current + work[current].day, money + work[current].cost);
	}
	//안한다.
	dfs(current + 1, money);
}

int main() {

	scanf("%d", &N);
	for (int i = 1;i <= N;i++) {
		int day, cost;
		struct work temp;
		scanf("%d %d",&day, &cost);
		work[i].day = day;
		work[i].cost = cost;
	}
	dfs(1,0);
	printf("%d", max);

	return 0;
}