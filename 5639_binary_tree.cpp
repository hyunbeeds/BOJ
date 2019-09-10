#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <iostream>

#pragma warning(disable:4996)
using namespace std;

pair<int, int> tree[100005];
//first�� ����, second�� ������ �ڽ� 
void postorder(int cur) {
	if (tree[cur].first != 0)postorder(tree[cur].first);
	if (tree[cur].second != 0) postorder(tree[cur].second);
	printf("%d\n", cur);
}
int main() {
	int root=0;
	int temp;
	int cur;
	scanf("%d", &root);
	//�������� ����Ʈ�� �����غ���
	//������������� �� �����˻�Ʈ������ �Է¼����� �����Ƿ� 
	//�׳� ������� �����ϸ�ȴ�. 
	while (scanf("%d",&temp) != EOF){
		cur = root;
		while (1) {
			if (temp < cur) {	// ���ʰ��ߵ�
				if (tree[cur].first != 0) {
					cur = tree[cur].first;
				}
				else {
					tree[cur].first = temp;
					break;
				}
			}
			else {	//������ ���ߵ�
				if (tree[cur].second != 0) {
					cur = tree[cur].second;
				}
				else {
					tree[cur].second = temp;
					break;
				}
			}
		}
	}
	
	postorder(root);
}