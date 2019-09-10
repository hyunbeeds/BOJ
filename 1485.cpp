#include <cstdio>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

typedef struct Point {
	long long int x, y;
	Point() {}
	Point(long long int a, long long int b) {
		x = a;
		y = b;
	}
	bool operator < (Point a) {
		if (x == a.x) {
			return y < a.y;
		}
		else return x < a.x;
	}
	bool operator > (Point a) {
		if (x == a.x) {
			return y > a.y;
		}
		else return x > a.x;
	}
	bool operator <= (Point a) {
		if (x == a.x) {
			return y <= a.y;
		}
		else return x <= a.x;
	}
}Point;
typedef struct Line {
	Point start, end;
	long long int vec_x, vec_y;
	Line() {}
	Line(Point a, Point b) : start(a), end(b) {
		if (start>end) {
			swap(start, end);
		}
		vec_x = end.x - start.x;
		vec_y = end.y - start.y;
	}
}Line;

long long int ccw(Point a, Point b, Point c) {
	return (a.x*b.y + b.x*c.y + c.x*a.y - (a.y*b.x + b.y*c.x + c.y*a.x));
}
bool check(Line a, Line b) {
	long long int result_ab = ccw(a.start, a.end, b.start)*ccw(a.start, a.end, b.end);
	long long int result_cd = ccw(b.start, b.end, a.start)*ccw(b.start, b.end, a.end);
	if (result_ab == 0 && result_cd == 0) {
		// 선분 a,b가 한 직선위에 있는 경우 처리
		return (a.start <= b.end && b.start <= a.end);
	}
	return (result_ab <= 0 && result_cd <= 0);
}
long long int inner_product(Line a, Line b) {
	return (a.vec_x*b.vec_x + a.vec_y*b.vec_y);
}

Line line;
int t;
Line rect[6];
Point rectangle[4];

int main() {
	scanf("%d", &t);
	while (t--) {
		//점이 네개면 선이 6개
		//그 선 6개중 두개뽑아서 하는 경우의수 15개
		// 정사각형은 15개경우의수중 5가지 경우가 수직이다.
		// 그말은 결국 내적해서 5가지 경우가 답이 0이나온다는 것이다.
		for (int i = 0; i < 4; i++) {
			scanf("%lld %lld", &rectangle[i].x, &rectangle[i].y);
		}
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				rect[cnt++] = Line(rectangle[i], rectangle[j]);
				//printf("%d,%d line : (%lld %lld)-> (%lld %lld)\n", i, j, rect[i].start.x, rect[i].start.y, rect[i].end.x, rect[i].end.y);
			}
		}
		cnt = 0;
		for (int i = 0; i < 6; i++) {
			for (int j = i + 1; j < 6; j++) {
				if (inner_product(rect[i], rect[j]) == 0) {
					cnt++;
				}
			}
		}
		if (cnt == 5)printf("1\n");
		else printf("0\n");
	}
}