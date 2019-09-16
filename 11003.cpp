#include <cstdio>
#include <deque>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int n, m;
deque<pair<int,int> > dq;
// (index, ����)
int main() {
	scanf("%d%d", &n, &m);
	int temp;
	for (int i = 0;i < n;i++) {
		scanf("%d", &temp);
		// temp ���� ���� ���� �ʿ䰡 ����
		while (!dq.empty() && dq.back().second > temp) {
			dq.pop_back();
		}
		dq.push_back(make_pair(i, temp));
		// m�̻� index�� ���̳��� �͵��� ���� �ٻ������!
		while (!dq.empty() && i - dq.front().first >= m) {
			dq.pop_front();
		}
		printf("%d ", dq.front().second);
	}

}