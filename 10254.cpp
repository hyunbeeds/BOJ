#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
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
	Point operator -(Point a) {
		return Point(x-a.x, y-a.y);
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
bool line_ccw(Point a, Point b, Point c, Point d) {
	//a~b , c~d가 이루어진 것이 시계방향이면 false,반시계면 true 반환
	long long int vec_ax=b.x - a.x;
	long long int vec_ay = b.y - a.y;
	long long int vec_bx = d.x - c.x;
	long long int vec_by = d.y - c.y;
	return ((vec_ax*vec_by - vec_ay*vec_bx)>=0);
}
Line line;
int n;
int t;
vector<Point> points;
vector<Point> up_hull;
vector<Point> down_hull;


int main() {
	long long int a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		points.clear();
		up_hull.clear();
		down_hull.clear();

		while (n--) {
			scanf("%lld %lld", &a, &b);
			points.push_back(Point(a, b));
		}
		sort(points.begin(), points.end());

		//위껍질 탐색
		up_hull.push_back(points[0]);
		up_hull.push_back(points[1]);
		for (int i = 2; i < points.size(); i++) {
			while (up_hull.size() >= 2 && ccw(up_hull[up_hull.size() - 2], up_hull[up_hull.size() - 1], points[i]) <= 0) {
				up_hull.pop_back();
			}up_hull.push_back(points[i]);
		}

		//아래껍질 탐색
		down_hull.push_back(points[points.size() - 1]);
		down_hull.push_back(points[points.size() - 2]);
		for (int i = points.size() - 3; i >= 0; i--) {
			while (down_hull.size() >= 2 && ccw(down_hull[down_hull.size() - 2], down_hull[down_hull.size() - 1], points[i]) <= 0) {
				down_hull.pop_back();
			}down_hull.push_back(points[i]);
		}
		for (int i = 1; i < down_hull.size() - 1; i++) {
			up_hull.push_back(down_hull[i]);
		}

		long long int max = 0;
		Point xx, yy;	// 최대로 먼 두점

		//rotating calipers
		//
		int p2=0;
		long long int dist;
		for (int i = 0; i < up_hull.size(); i++) {
			while(p2 + 1 < up_hull.size() && line_ccw(up_hull[i], up_hull[i+1], up_hull[p2], up_hull[p2+1])) {
				dist = (up_hull[i].x - up_hull[p2].x)*(up_hull[i].x - up_hull[p2].x) + (up_hull[i].y - up_hull[p2].y)*(up_hull[i].y - up_hull[p2].y);
				if (dist > max) {
					max = dist;
					xx = up_hull[i];
					yy = up_hull[p2];
				}
				p2++;
			}
			dist = (up_hull[i].x - up_hull[p2].x)*(up_hull[i].x - up_hull[p2].x) + (up_hull[i].y - up_hull[p2].y)*(up_hull[i].y - up_hull[p2].y);
			if (dist > max) {
				max = dist;
				xx = up_hull[i];
				yy = up_hull[p2];
			}
			//두 켈리퍼스가 반시계방향일때까지 아래 캘리퍼스를 돌린다.
		}
		printf("%lld %lld %lld %lld\n", xx.x, xx.y, yy.x, yy.y);
	}
}

