#include <cstdio>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

int n, m;
vector<int> joint;

int par(int a) {
	if (joint[a] == a) return a;
	else return joint[a]= par(joint[a]);
}

void unify(int a, int b) {
	int aroot = par(a);
	int broot = par(b);
	joint[aroot] = broot;
}

int main() {
	scanf("%d %d", &n, &m);
	int order;
	int a, b;
	joint = vector<int>(n+1);
	for (int i = 0; i <= n; i++) {
		joint[i] = i;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &order, &a, &b);
		
		if (order == 0) {	//합집합
			unify(a, b);
		}
		else if (order == 1) {	//같은집합인가?
			if (par(a) == par(b)) printf("YES\n");
			else printf("NO\n");
		}
	}
}