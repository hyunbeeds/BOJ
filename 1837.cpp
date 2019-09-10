#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

int mod(char *S, int p)
{
	// S는 수를 문자열로 표현한 것, 1324 -> "1324"
	int ret = 0;
	for (int i = 0; S[i]; i++) ret = (ret * 10 + (S[i] - '0')) % p;
	return ret;
}

int main() {
	char S[105];
	int k;
	scanf("%s %d", S, &k);

	for (int i = 2; i < k; i++) {
		if (mod(S, i) == 0) {
			printf("BAD %d\n", i);
			return 0;
		}
	}
	printf("GOOD\n");
}