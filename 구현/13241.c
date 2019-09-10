#include <stdio.h>
#pragma warning(disable:4996)

long long int a;
long long int b;

long long int gcd_decide(long long int a, long long int b) {	//a°¡ ´õÅ­
	if (a%b == 0) return b;
	else {
		if (a - b > b)gcd_decide(a - b, b);
		else gcd_decide(b, a - b);
	}
}

int main() {
	scanf("%lld %lld", &a, &b);
	if(a>b)
	printf("%lld\n", a*b/gcd_decide(a, b));
	else printf("%lld\n", a*b/gcd_decide(b, a));
}