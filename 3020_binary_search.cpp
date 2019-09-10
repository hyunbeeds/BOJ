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

	//�������� ������ �Ǿ������Ƿ�
	//i �� ��ǥ���̶�� �ϸ� �װ��� �� �� �ִ� ���� ���� ���� ��, �Ⱥμ���
	//����Ҽ� �ִ� �������� ������ ���´�.
	//�̸� ��ü �������� ���� �ν����� ������ ������ ������ �ȴ�. 
	//ex) {1,1,1,2,3,3,4,5}
	// 2�� lower bound -> 3 
	// ����Ҽ� �ִ� ������ �����̴�. 
	int x, y, ans,broke, cnt;
	cnt = 1;
	ans = 5000000;
	for (int i = 1; i <= h; i++) {
		//i-> ���˹����� ��ǥ���� ����
		//i���� ������ ������ ���� �ؾߵ�
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