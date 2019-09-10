#include <cstdio>
#include <vector>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

int parent[100001];
long long int dist[100001];
int p_score[100001]; //점수가 높을 수록 루트일 확률이 높다. 
					 // parent[i] 는  i의 최종부모
					 // dist[i]에는 부모까지 가는데 걸리는 거리가 들어가있다.
// 이번에는 disjoint set을 이용해서 풀어보자!!

/*
pair<int, long long int> find(int start, long long int cost) {
	if (parent[start] == start) {
		return{ start, cost };
	}
	return find(parent[start], cost + dist[start]);
}
void unify(int start, int end, int cost) {		//end가 start보다 cost만큼 더 무겁다.
	pair<int, long long int> a_root = find(start, 0);
	pair<int, long long int> b_root = find(end, 0);

	if (a_root.first == b_root.first) return;	//이미 연결되어있으면 끝
												//아니면 대표자를 정해서 cost비교해야됨

												// ex) 1-3 : 50, 2-4: 100일때, 3이 우선순위가 더높고, 
												// 2-3 : 150이 들어온다면
												// 1-2 는 -100일꺼다. 
	if (p_score[a_root.first] > p_score[b_root.first]) { //우선순위가 a가 더 높은경우
		dist[b_root.first] -= (b_root.second - a_root.second - cost);
		parent[b_root.first] = a_root.first;
		p_score[a_root.first] += p_score[b_root.first];
		p_score[b_root.first] = 1;
	}
	else {	//b가 우선순위 더 높은경우
		dist[a_root.first] += (b_root.second - a_root.second - cost);
		parent[a_root.first] = b_root.first;
		p_score[b_root.first] += p_score[a_root.first];
		p_score[a_root.first] = 1;
	}
}
*/
//바꾼게 더걸리네 ㅋㅋㅋ
int find(int cur) {			
	if (cur == parent[cur]) return cur;	// 최상위 부모면 return
	int par = find(parent[cur]);		// 아니면 find하는 동시에 distance도 업데이트하기 위해
										// parent의 find결과를 불러오고, 이를 이용해서 거리, 자기의 parent도 parent의 parent로 업데이트!
	dist[cur] += dist[parent[cur]];
	return parent[cur] = par;
}

void unify(int start, int end, int cost) {		//end가 start보다 cost만큼 더 무겁다.
	int a_root = find(start);
	int b_root = find(end);

	if (a_root == b_root) return;	//이미 연결되어있으면 끝
									//아니면 대표자를 정해서 cost비교해야됨
									// ex) 1-3 : 50, 2-4: 100일때, 3이 우선순위가 더높고, 												// 2-3 : 150이 들어온다면
									// 1-2 는 -100일꺼다. 
	if (p_score[a_root] > p_score[b_root]) { //우선순위가 a가 더 높은경우
		dist[b_root] = (dist[start] - dist[end] - cost);
		parent[b_root] = a_root;
		p_score[a_root] += p_score[b_root];
		p_score[b_root] = 1;
	}
	else {	//b가 우선순위 더 높은경우
		dist[a_root] = (dist[start] - dist[end] - cost)*(-1);
		parent[a_root] = b_root;
		p_score[b_root] += p_score[a_root];
		p_score[a_root] = 1;
	}
}

int main() {
	int n, m;
	int a, b, c;
	char work;
	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		//disjoint set initialize;
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
			dist[i] = 0;
			p_score[i] = 1;
		}

		for (int w = 0; w < m; w++) {
			scanf("%c", &work);		//\n 없애기 위한 노력 ㅎ
			scanf("%c %d %d", &work, &a, &b);
			if (work == '!') {	// 무게재기, 정보입력
								//scanf("%d %d %d", &a, &b, &c);
				scanf("%d", &c);
				unify(a, b, c);
				//disjoint set 추가
			}
			else if (work == '?') {	//parent 봐서 같으면 거리구함
									//scanf("%d %d", &a, &b);
				int one, two;
				one = find(a);
				two = find(b);
				if (one == two) {// a,b parent가 같니?
								// 같으면 그 거리 출력 ((a~parent거리)-(b~parent거리))
					printf("%lld\n", dist[a]-dist[b]);
				}
				else {//아니면 0출력
					printf("UNKNOWN\n");
				}
			}
		}
	}
}