#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int t; 
long long int k, c;
long long int ans;
long long int great_common(long long int a, long long int b) {
	if (b > 0) return great_common(b, a%b);
	else return a;
}
void gcd(long long int a, long long int b) {
	long long int s1, s2,s3, t1, t2,t3;
	s1 = 1;
	s2 = 0;
	t1 = 0;
	t2 = 1;
	long long int r1 = a;
	long long int r2 = b;
	long long int r3, q;

	do{
		q = r1 / r2;
		r3 = r1 % r2;
		s3 = s1 - q*s2;
		t3 = t1 - q*t2;
		s1 = s2; s2 = s3;
		t1 = t2; t2 = t3;
		r1 = r2; r2 = r3;
	} while (r3 > 1);
	
	ans = t3;
}

int main() {
	//modulo 역원 구하는 문제다.
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%lld %lld", &k, &c);
		//c의 k에 대한 modulo inverse를 구해서 반환하면 된다. 
		//일단 c,k가 서로소가 아닌경우는 존재 안하므로. gcd구해서 1이면 impossible
		if (c == 1) {
			if (k + 1 > 1000000000) printf("IMPOSSIBLE\n");
			else printf("%d\n", k + 1);
		}
		else {
			gcd(k, c);
			if (great_common(k, c) != 1) {
				printf("IMPOSSIBLE\n");
				continue;
			}
			else {
				while (ans <= 0) ans = ans + k;
				if (ans > 1000000000) printf("IMPOSSIBLE\n");
				else printf("%lld\n", ans);
			}
		}
	}
}