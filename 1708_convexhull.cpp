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
int n;
vector<Point> points;
vector<Point> up_hull;
vector<Point> down_hull;


int main() {
	long long int a, b;
	scanf("%d", &n);
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
	printf("%d\n", up_hull.size() + down_hull.size() - 2);
}