#include <cstdio>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;
int T, N;							//T->testcase ��, N -> �����ͼ�
int A[501], S[501], D[501][501];	//s[i]->a[0]~a[i]���� ���Ѱ�, s[j]-s[i-1]->a[i]~a[j]���Ѱ� 

int min(int a, int b) {
	if (a <= b)return a;
	else return b;
}

int dy(int start, int end)		//dy(i,j) ->i~j���� ���� �ּ� ��
{
	if (start >= end) return 0;
	if (start + 1 == end) return A[start] + A[end];
	int &ret = D[start][end];					//ret�ٲ��,D�� �ٲ�
	if (ret < (int)2e9) return ret;		//�޸������̼�, D�� ������������ �װ� ������
	for (int k = start;k < end;k++) {
		ret = min(ret, dy(start, k) + dy(k + 1, end) + S[end] - S[start - 1]);
	}
	return ret;
}

int main()
{
	for (scanf("%d", &T);T--;) {
		scanf("%d", &N);
		for (int i = 1;i <= N;i++) scanf("%d", &A[i]), S[i] = S[i - 1] + A[i];
		for (int i = 1;i <= N;i++) for (int j = i;j <= N;j++) D[i][j] = (int)2e9;
		printf("%d\n", dy(1, N));
	}
}

