#include <cstdio>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;
int point[100010];

int main() {
	int start, end;
	int cnt = 0;
	queue<pair<int, int> > queue;

	std::cin >> start;
	std::cin >> end;
	if (start == end) {
		printf("0\n");
		return 1;
	}
	for (int i = 0;i < 100010;i++) {
		point[i] = 0;
	}
	point[start] = 1;
	queue.push(make_pair(start, 0));

	while (1) {
		int current = queue.front().first;
		int cnt = queue.front().second;
		queue.pop();
		if (current - 1 >= 0 && point[current - 1] == 0) {
			if (current - 1 == end) {
				printf("%d\n", cnt + 1);
				break;
			}
			else {
				point[current - 1] = cnt + 1;
				queue.push(make_pair(current - 1, cnt + 1));
			}
		}
		if (current > end) continue;

		if (current + 1 < 100002 && point[current + 1] == 0) {
			if (current + 1 == end) {
				printf("%d\n", cnt + 1);
				break;
			}
			else {
				point[current + 1] = cnt + 1;
				queue.push(make_pair(current + 1, cnt + 1));
			}
		}
		if (current * 2 < 100002 && point[current * 2] == 0) {
			if (current * 2 == end) {
				printf("%d\n", cnt + 1);
				break;
			}
			else {
				point[current * 2] = cnt + 1;
				queue.push(make_pair(current * 2, cnt + 1));
			}
		}
	}
}