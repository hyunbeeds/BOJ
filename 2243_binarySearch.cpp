#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int order, start;
int ans;
int ret=0;
vector<long long int> candy;

long long int out(int node, int goal, int begin, int end) {
	//goal : ã�����ϴ� ĵ���� ���� 
	//node : ������ġ
	//start-end : ���� �����ִ� ����
	//(0-end)�� candy���� goal�̸� �װ� ����ϸ��.
	//�����ڽĺ��� goal���� ũ�� ���ʰ���ǰ�,
	//��ũ�� ���������� ���ߵ�.
	if (begin == end && ret == 0) {
		return begin;
	}

	int mid = (begin + end) / 2;
	if (ret==0 && node*2 <= candy.size() && candy[node * 2] >= goal) {	//�������� ��
		return ret=out(node * 2, goal, begin, mid);
	}
	else if (ret==0 && node * 2 + 1 <= candy.size() && candy[node * 2 + 1] >= goal-candy[node*2]) {
		//���������� ��
		return ret=out(node * 2+1, goal - candy[node * 2], mid + 1, end);
	}
}
int main() {
	scanf("%d", &order);
	int a, b, c, flavor;
	candy = vector<long long int>(1 << ((int)ceil(log2(1000000)) + 1));
	start = 1 << (int)ceil(log2(1000000));
	for (int t = 0; t< order; t++) {
		scanf("%d %d", &a, &b);
		if (a == 2) {	// ���� �߰�
			scanf("%d", &c);
			flavor = start + b - 1;
			candy[flavor] += c;
			while (flavor != 1) {
				flavor = flavor / 2;
				candy[flavor] += c;
			}
			
		}
		else if (a == 1) { //���� ����
			long long int k=out(1, b, 1, start);
			ret = 0;
			printf("%d\n", k);
			//�������� ������Ʈ
			flavor = start + k - 1;
			candy[flavor] -=1;
			while (flavor != 1) {
				flavor = flavor / 2;
				candy[flavor] -= 1;
			}
		}
	}

}