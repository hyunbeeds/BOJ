#include <cstdio>
#pragma warning(disable:4996)

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int current = N;	// ���� �α���
	int next;			// ���� ������ ģ��
	// K�� �ش��ϴ� ģ���� �����ġ�� ��� ���ϴ� ������� ���Ѵ�.
	// ex) 1 2 3 4 5
	//   ->4   1 2 3
	//   ->2   3   1
	//   ->    1   2
	//   ->    1
	for (int i = 1;i <= N;i++) {
		current = N - i + 1;
		//M�� �����ִ� ģ���麸�� ���� ��� ����ؼ� �̷��� ������ش�.
		if (M % current == 0) {
			next = current;
		}
		else {
			next = M % current;
		}
		
		if (K == next || i==N) {	//�̹����ʿ� ������ ���
			printf("%d\n", i);
			break;
		}
		else {
			if (K > next) K = K - next;
			else K = current + K - next;
		}
	}
}