#include <stdio.h>
#pragma warning(disable:4996)

int vertex, line,start;
int connect[20001][20001] = { 0 };
int cost[20001];
int queue[20001];
int front = 0;
int rear = 0;

void push(int i) {
	queue[rear] = i;
	rear = rear + 1;
}
int pop() {
	return queue[front++];
}
int main() {
	scanf("%d", &vertex);
	scanf("%d", &line);
	scanf("%d", &start);
	for (int i = 0;i < line;i++) {
		int start, end,c;
		scanf("%d%d%d", &start,&end,&c);
		connect[start][end] = c;
	}
	
	for (int i = 1;i <= vertex;i++) {		//무한대로 초기화
		cost[i] = 300000;
	}
	push(start);
	cost[start] = 0;

	while (front != rear) {
		int current;
		current = pop();
		for (int i = 1;i <= vertex;i++) {
			if (connect[current][i] > 0) {
				push(i);
				if (connect[current][i] + cost[current] < cost[i]) {
					cost[i] = connect[current][i] + cost[current];
				}
			}
		}
	}

	for (int i = 1;i <= vertex;i++) {
		if (cost[i] == 300000)printf("INF\n");
		else printf("%d\n", cost[i]);
	}
}