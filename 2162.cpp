#include <cstdio>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

typedef struct Point {
	long long int x, y;
	Point() {}
	Point(long long int a, long long int b){
		x = a;
		y = b;
	}
	bool operator < (Point a){
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
Line lines[3001];
int n;
int par[3001];

int find(int cur) {
	if (par[cur] == cur) return cur;
	else {
		int p = find(par[cur]);
		par[cur] = p;
		return p;
	}
}

void unify(int a, int b) {
	int par_a=find(a);
	int par_b=find(b);
	if (a == b) return;
	else {
		if (par_a < par_b) par[par_b] = par_a;
		else {
			par[par_a] = par_b;
		}
		//합치기
	}

}

int main() {
	long long int a, b,c,d;
	scanf("%d", &n);
	Point temp1, temp2;
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		temp1 = Point(a, b);
		temp2 = Point(c, d);
		lines[i] = Line(temp1, temp2);
		par[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (check(lines[i], lines[j]) == true) {
				//교차하는 경우
				unify(i, j);
			}
			else continue;
		}
	}
	int parents[3001] = { 0, };
	for (int i = 1; i <= n; i++) {
		parents[find(i)]++;
	}
	int max = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (parents[i] != 0) {
			cnt++;
			if (max < parents[i]) max = parents[i];
		}
	}
	printf("%d\n%d\n", cnt, max);
}