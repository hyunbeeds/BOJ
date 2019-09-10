#include <cstdio>
#include <vector>
#pragma warning(disable:4996)


typedef struct Point {
	int x, y;
	Point() {}
	Point(int a, int b):x(a), y(b){}
}Point;
typedef struct Line {
	Point x, y;
	int vec_x, vec_y;
	Line(){}
	Line(Point a, Point b): x(a), y(b){
		vec_x = y.x - x.x;
		vec_y = y.y - x.y;
	}
}Line;

int ccw(Point a, Point b, Point c) {
	return (a.x*b.y + b.x*c.y + c.x*a.y - (a.y*b.x+b.y*c.x+c.y*a.x));
}

Point points[3];
Line lines[2];

int main() {
	int a, b;
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &a,&b);
		points[i] = Point(a, b);
	}
	if (ccw(points[0], points[1], points[2]) > 0) {
		printf("1\n");
	}
	else if (ccw(points[0], points[1], points[2]) < 0) {
		printf("-1\n");
	}
	else {
		printf("0\n");
	}
}