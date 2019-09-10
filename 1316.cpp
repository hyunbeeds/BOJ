#include <cstdio>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

vector<int> alpha;

int n,num,last;
int main() {
	char str[105];
	scanf("%d", &n);
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		alpha.clear();
		alpha = vector<int>(30,0);
		last = 100;
		for (int j = 0; j <= 100; j++) {
			if (str[j] == '\0') {
				cnt++;
				break;
			}
			num=str[j] - 'a';
			if (num == last)continue;
			else {
				if (alpha[num] > 0) break;
				else {
					last = num;
					alpha[num] = 1;
				}
			}
		}
	}
	printf("%d\n", cnt);
}