#include <cstdio>
#include <algorithm>
#include <functional>
#pragma warning(disable:4996)
using namespace std;



int main() {
	long long int a, b, c, d, temp;
	long long int child, parent;

	scanf("%lld %lld", &a, &b);
	scanf("%lld %lld", &c, &d);
	child = a*d + b*c;
	parent = b*d;
	//child, parent�� �ִ����� ���ϱ�
	
	a = child;
	b = parent;
	if (b > a) swap(a, b);	//������ a�� ��Ŀ�ߵ�
	
	while (1) {
		if (a%b == 0) break;
		temp = b;
		b = a%b;
		a = temp;
	}
	//printf("gcd : %lld\n", b);
	printf("%lld %lld\n", child / b, parent / b);
}
