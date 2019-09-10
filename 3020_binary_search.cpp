#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#pragma warning(disable:4996)

using namespace std;
int n, h;
vector<int> badak;
vector<int> chun;

int main() {
	scanf("%d %d", &n, &h);
	int temp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		if (i % 2 == 0) badak.push_back(temp);
		else chun.push_back(temp);
	}
	sort(badak.begin(), badak.end());	
	sort(chun.begin(), chun.end());

	//오름차순 정렬이 되어있으므로
	//i 를 목표높이라고 하면 그것이 들어갈 수 있는 가장 작은 숫자 즉, 안부수고도
	//통과할수 있는 종유석의 개수가 나온다.
	//이를 전체 개수에서 빼면 부숴야할 종유석 개수가 나오게 된다. 
	//ex) {1,1,1,2,3,3,4,5}
	// 2의 lower bound -> 3 
	// 통과할수 있는 종유석 개수이다. 
	int x, y, ans,broke, cnt;
	cnt = 1;
	ans = 5000000;
	for (int i = 1; i <= h; i++) {
		//i-> 개똥벌레가 목표로할 높이
		//i보다 작은거 있을때 까지 해야됨
		x = badak.size() - (lower_bound(badak.begin(), badak.end(), i) - badak.begin());
		y = badak.size() - (lower_bound(chun.begin(), chun.end(), h - i + 1) - chun.begin());
		broke = x + y;
		if (broke<ans) {
			ans = broke;
			cnt = 1;
		}
		else if (broke == ans) {
			cnt++;
		}
	}
	printf("%d %d\n", ans, cnt);
}