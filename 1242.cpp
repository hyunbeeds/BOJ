#include <cstdio>
#pragma warning(disable:4996)

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int current = N;	// 현재 인구수
	int next;			// 다음 퇴장할 친구
	// K에 해당하는 친구의 상대위치를 계속 구하는 방법으로 구한다.
	// ex) 1 2 3 4 5
	//   ->4   1 2 3
	//   ->2   3   1
	//   ->    1   2
	//   ->    1
	for (int i = 1;i <= N;i++) {
		current = N - i + 1;
		//M이 남아있는 친구들보다 많을 경우 대비해서 이렇게 만들어준다.
		if (M % current == 0) {
			next = current;
		}
		else {
			next = M % current;
		}
		
		if (K == next || i==N) {	//이번차례에 나가는 경우
			printf("%d\n", i);
			break;
		}
		else {
			if (K > next) K = K - next;
			else K = current + K - next;
		}
	}
}