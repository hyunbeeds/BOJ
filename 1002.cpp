/*#include <cstdio>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;

typedef struct Circle {
	int x, y, r;
	Circle(int a, int b, int c) : x(a), y(b), r(c) {}
}Circle;
int t;

int main() {
	Circle a(0, 0, 0);
	Circle b(0, 0, 0);
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d %d %d %d", &a.x, &a.y, &a.r, &b.x, &b.y, &b.r);
		int dis = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
		if (a.x == b.x && a.y == b.y) {	
			if (a.r == b.r) printf("-1\n");		//원이 같을때
			else printf("0\n");					//중심은 같지만..반지름다른경우
			continue;
		}
		if (dis > (a.r + b.r)*(a.r+b.r)) {		//안만남
			printf("0\n");
			continue;
		}
		if (dis < (a.r - b.r)*(a.r - b.r)) {	// 안만남
			printf("0\n");
			continue;
		}
		if (dis == (a.r + b.r)*(a.r + b.r)) {	//외적
			printf("1\n");
			continue;
		}
		if (dis == (a.r - b.r)*(a.r - b.r))  {	//내적
			printf("1\n");
			continue;
		}
		if (dis > (a.r - b.r)*(a.r - b.r) && dis < (a.r + b.r)*(a.r + b.r)) {
			printf("2\n");
			continue;
		}
	}
}*/