#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#define INF 2e9

using namespace std;

int n;
int dp[16][1 << 16], adj[16][16];		//dp[current][status]->마지막 방문한게 current이고, status(비트마스크로 표현)
										//ex) 4개 정점, 1 2 방문 완료일시 -> 1100
int TSP(int cur, int visited) {
	if (visited == (1 << n) - 1) return adj[cur][0];	// 다 방문되었을때

	int& ret = dp[cur][visited];						
	if (ret != 0) return ret;												//ret가 계산된적 있는곳이라면 그냥 반환
	ret = INF;
	for (int next = 0; next < n; next++) {
		if (visited&(1 << next))continue;									// next가 방문한적 있는 곳일때
		if (adj[cur][next] == 0)continue;									// next가 자기 자신일때
		ret = min(ret, TSP(next, visited | (1 << next)) + adj[cur][next]);	// (next를 추가하는데 쓰는 비용+현재)과 dp중에 next가 추가된것과 최소값 구해서 dp
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &adj[i][j]);
		}
	printf("%d\n", TSP(0, 1));		//0을 초기값으로 잡음
	return 0;
}