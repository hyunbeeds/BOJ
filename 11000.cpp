#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#pragma warning(disable:4996)

using namespace std;
int n;
pair<int, int> arr[200001];
int main() {
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		scanf("%d%d", &arr[i].first, &arr[i].second);
	}
	sort(arr, arr + n);
	int min = 1;
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 0;i < n;i++) {
		if (pq.empty()) {	//큐가 비었으면 그냥 push
			pq.push(arr[i].second);
		}else {
			int fast = pq.top();	//제일빨리 끝나는 시간
			if (fast <= arr[i].first) {
				pq.pop();
				pq.push(arr[i].second);
			}
			else {	
				pq.push(arr[i].second);
				if ((int)pq.size() > min) {
					min = pq.size();
				}
			}

		}
	}
	printf("%d\n",min);
}