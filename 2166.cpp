#include <cstdio>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

typedef struct Point {
	long long int x, y;
	Point() {}
	Point(long long int a, long long int b) :x(a), y(b) {}
}Point;
typedef struct Line {
	Point x, y;
	long long int vec_x, vec_y;
	Line() {}
	Line(Point a, Point b) : x(a), y(b) {
		vec_x = y.x - x.x;
		vec_y = y.y - x.y;
	}
}Line;

long long int ccw(Point a, Point b, Point c) {
	return (a.x*b.y + b.x*c.y + c.x*a.y - (a.y*b.x + b.y*c.x + c.y*a.x));
}

Point points[10001];
Line lines[2];
int n;

int main() {
	long long int a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a, &b);
		points[i] = Point(a, b);
	}

	Point one;
	one = points[0];
	long long int sum = 0;
	for (int i = 1; i < n-1; i++) {
		sum += ccw(one, points[i], points[i + 1]);
	}
	sum = abs(sum);
	printf("%lld", sum/2);
	if (sum % 2 == 0)printf(".0\n");
	else printf(".5\n");
}