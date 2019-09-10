#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <iostream>

#pragma warning(disable:4996)
using namespace std;

pair<int, int> tree[100005];
//first가 왼쪽, second가 오른쪽 자식 
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
	//이제부터 이진트리 생성해보자
	//전위순서결과가 곧 이진검색트리에서 입력순서와 같으므로 
	//그냥 순서대로 생성하면된다. 
	while (scanf("%d",&temp) != EOF){
		cur = root;
		while (1) {
			if (temp < cur) {	// 왼쪽가야됨
				if (tree[cur].first != 0) {
					cur = tree[cur].first;
				}
				else {
					tree[cur].first = temp;
					break;
				}
			}
			else {	//오른쪽 가야됨
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