#include <stdio.h>
#pragma warning(disable:4996)

int arr[10001];
int front = -1;
int rear = -1;
int order;


int main() {
	int j, temp;
	scanf("%d", &order);
	fflush(stdin);
	char command[7];
	char *orders[6];
	orders[0] = "push";
	orders[1] = "pop";
	orders[2] = "size";
	orders[3] = "empty";
	orders[4] = "front";
	orders[5] = "back";

	for (int i = 0; i < order; i++) {
		scanf("%s", command);
		fflush(stdin);
		for (j = 0; j < 5; j++) {
			if (strcmp(command, orders[j]) == 0) break;
		}
		if (j == 0) {	//push
			scanf("%d", &temp);
			arr[++rear] = temp;
		}
		else if (j == 1) { //pop
			if (front==rear) printf("-1\n");
			else printf("%d\n", arr[++front]);
		}
		else if (j == 2) {//size
			printf("%d\n", rear-front);
		}
		else if (j == 3) { //empty
			if (front==rear)printf("1\n");
			else printf("0\n");
		}
		else if (j == 4) { // front
			if (front==rear) printf("-1\n");
			else printf("%d\n", arr[front+1]);
		}
		else if (j == 5) { // back
			if (front == rear) printf("-1\n");
			else printf("%d\n", arr[rear]);
		}
	}
}