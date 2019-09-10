#include <cstdio>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

char str[35];
pair<char, int> stack[35];
int top = -1;

int main() {
	scanf("%s", str);
	int idx = 0;

	while (str[idx] != '\0') {
		if (str[idx] == '(' || str[idx] == '[') { // push
			stack[++top] = make_pair(str[idx],0);
		}
		else if (str[idx] == ')') {
			// ( 나올때 까지 pop 해야되는데 중간에 숫자는 나와도 되지만 [ 나오면 종료
			int result = 0;
			int okay = 0;
			while (top != -1) {	
				if (stack[top].first == ' ') {
					result += stack[top--].second;
				}
				else if (stack[top].first == '[') {
					printf("0\n");
					return 0;
				}
				else if (stack[top].first == '(') {
					if (result == 0) stack[top] = make_pair(' ', 2);
					else stack[top] = make_pair(' ', 2 * result);
					okay = 1;
					break;
				}
			}
			if (okay != 1) {
				printf("0\n");
				return 0;
			}
		}
		else if (str[idx] == ']') {
			// [ 나올때 까지 pop 해야되는데 중간에 숫자는 나와도 되지만 ( 나오면 종료
			int result = 0;
			int okay = 0;
			while (top != -1) {
				if (stack[top].first == ' ') {
					result += stack[top--].second;
				}
				else if (stack[top].first == '(') {
					printf("0\n");
					return 0;
				}
				else if (stack[top].first == '[') {
					if (result == 0) stack[top] = make_pair(' ', 3);
					else stack[top] = make_pair(' ', 3 * result);
					okay = 1;
					
					break;
				}
			}
			if (okay != 1) {
				printf("0\n");
				return 0;
			}
		}
		idx++;
	}
	int ans = 0;
	while (top != -1) {
		if (stack[top].first != ' ') {
			printf("0\n");
			return 0;
		}
		else {
			ans += stack[top--].second;
		}
	}
	printf("%d\n", ans);
}