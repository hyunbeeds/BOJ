#include <cstdio>
#include <deque>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int n, m;
deque<pair<int,int> > dq;
// (index, 숫자)
int main() {
	scanf("%d%d", &n, &m);
	int temp;
	for (int i = 0;i < n;i++) {
		scanf("%d", &temp);
		// temp 보다 작은 값은 필요가 없음
		while (!dq.empty() && dq.back().second > temp) {
			dq.pop_back();
		}
		dq.push_back(make_pair(i, temp));
		// m이상 index가 차이나는 것들은 이제 다빼줘야함!
		while (!dq.empty() && i - dq.front().first >= m) {
			dq.pop_front();
		}
		printf("%d ", dq.front().second);
	}

}