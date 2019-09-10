#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#pragma warning(disable:4996)

using namespace std;						


int main() {
	vector<pair<int,int> > orders;
	pair<int, int> temp;
	int ar[32001] = { 0 };	//들어오는 간선 수
	int n;			//학생수
	int m;			//간선수
	int temp1, temp2;
	priority_queue <int,vector<int>,greater<int>> q1;

	scanf("%d %d", &n, &m);
	for (int i = 0;i < m;i++) {
		scanf("%d %d", &temp1, &temp2);
		orders.push_back(make_pair(temp1, temp2));
		ar[temp2]++;
	}
	sort(orders.begin(), orders.end());
	for (int i = 1;i <= n;i++) {
		if (ar[i] == 0) {//들어오는 간선수가 0이라면
			q1.push(i);
		}
	}

	while (!q1.empty()) {
		int current = q1.top();
		q1.pop();
		int next;
		
		printf("%d ", current);
		for (int i = 0;i < m;i++) {
			if (current == orders[i].first) {
				while (current == orders[i].first) {
					next = orders[i].second;
					ar[next]--;	
					if (ar[next] == 0) {
						q1.push(next);
					}
					if (i == m - 1) break;
					i++;
				}
				break;
			}
		}
	}
}