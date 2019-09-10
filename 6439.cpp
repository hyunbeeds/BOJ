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
	Line() {}
	Line(Point a, Point b) : start(a), end(b) {
		if (start>end) {
			swap(start, end);
		}
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
Line line;
int t;
Line rect[4];
Point rectangle[4];

int main() {
	long long int a, b, c, d,e,f,g,h;
	scanf("%d", &t);
	while (t--) {
		Point temp1, temp2;
		scanf("%lld %lld %lld %lld", &e, &f, &g, &h);
		temp1 = Point(e, f);
		temp2 = Point(g, h);
		line = Line(temp1, temp2);
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		if (a > c) swap(a, c);
		if (d > b) swap(b, d);
		//일단 내부에 있는지 판단
		//어느한쪽이라도 안에 있으면 무조건 true이므로
		//둘다 밖이면 교차하는지 찾아봐야한다.
		if (a <= e && e <= c && d <= f && f <= b) {
			printf("T\n");
			continue;		
		}
		else if (a <= g && g <= c && d <= h && h <= b) {
			printf("T\n");
			continue;
		}
		else {
			// 1  2     b
			// 0  3     d a  c
			rectangle[0] = Point(a, d);
			rectangle[1] = Point(a, b);
			rectangle[2] = Point(c, b);
			rectangle[3] = Point(c, d);
			rect[0] = Line(rectangle[0], rectangle[1]);
			rect[1] = Line(rectangle[1], rectangle[2]);
			rect[2] = Line(rectangle[2], rectangle[3]);
			rect[3] = Line(rectangle[3], rectangle[0]);
			int cnt = 0;
			for (int i = 0; i <= 3; i++) {
				if (check(line, rect[i])) {
					cnt++;
				}
			}
			if (cnt > 0)printf("T\n");
			else printf("F\n");
		}
	}
}