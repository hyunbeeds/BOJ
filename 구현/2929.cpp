#include <cstdio>

#pragma warning(disable:4996)

using namespace std;

int main() {
	char s[201];
	int nop_cnt=0;
	int small_cnt = 0;
	scanf("%s", s);
	for (int i = 0;i < 200;i++) {
		if (s[i] >= 'A'&&s[i] <= 'Z') {
			nop_cnt = nop_cnt + 3 - (small_cnt % 4);
			small_cnt = 0;
			continue;
		}
		else if (s[i] >= 'a'&&s[i] <= 'z') {
			small_cnt++;
		}
		else break;
	}
	printf("%d\n", nop_cnt-3);
	
}