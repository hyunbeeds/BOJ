#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Node *treePointer;
typedef struct Node {
	char data;
	treePointer left, right;
}node;

treePointer head;
treePointer cur;

treePointer create_node(char data) {
	treePointer newNode;
	newNode = (node*)malloc(sizeof(node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;

	return newNode;
}

void preOrder(treePointer ptr) {
	if (ptr != NULL)
	{
		printf("%c", ptr->data);
		preOrder(ptr->left);
		preOrder(ptr->right);
	}
}

void inOrder(treePointer ptr) {
	if (ptr != NULL)
	{
		inOrder(ptr->left);
		printf("%c", ptr->data);
		inOrder(ptr->right);
	}
}

void postOrder(treePointer ptr) {
	if (ptr != NULL)
	{
		postOrder(ptr->left);
		postOrder(ptr->right);
		printf("%c", ptr->data);
	}
}
void search_node(char data, treePointer current) {
	if (current->data == data) {
		cur = current;
		return;
	}

	if (current->right != NULL) search_node(data, current->right);
	if (current->left != NULL) search_node(data, current->left);
}
int main() {
	int num;

	scanf("%d", &num);
	scanf("\n");

	//A는 항상 루트 노드가 되므로
	head = (node*)malloc(sizeof(node));
	head->data = 'A';
	cur = (node*)malloc(sizeof(node));

	for (int i = 0; i < num; i++) {
		char parent, left, right;
		treePointer A, B, C;

		scanf(" %c", &parent);
		scanf(" %c", &left);
		scanf(" %c", &right);

		search_node(parent, head);
		A = cur;
		B = create_node(left);
		C = create_node(right);

		if (left == '.') B = NULL;
		if (right == '.') C = NULL;

		A->left = B;
		A->right = C;
	}
	preOrder(head);
	printf("\n");

	inOrder(head);
	printf("\n");

	postOrder(head);
	printf("\n");
}