#include <cstdio>
#include <vector>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

int parent[100001];
long long int dist[100001];
int p_score[100001]; //������ ���� ���� ��Ʈ�� Ȯ���� ����. 
					 // parent[i] ��  i�� �����θ�
					 // dist[i]���� �θ���� ���µ� �ɸ��� �Ÿ��� ���ִ�.
// �̹����� disjoint set�� �̿��ؼ� Ǯ���!!

/*
pair<int, long long int> find(int start, long long int cost) {
	if (parent[start] == start) {
		return{ start, cost };
	}
	return find(parent[start], cost + dist[start]);
}
void unify(int start, int end, int cost) {		//end�� start���� cost��ŭ �� ���̴�.
	pair<int, long long int> a_root = find(start, 0);
	pair<int, long long int> b_root = find(end, 0);

	if (a_root.first == b_root.first) return;	//�̹� ����Ǿ������� ��
												//�ƴϸ� ��ǥ�ڸ� ���ؼ� cost���ؾߵ�

												// ex) 1-3 : 50, 2-4: 100�϶�, 3�� �켱������ ������, 
												// 2-3 : 150�� ���´ٸ�
												// 1-2 �� -100�ϲ���. 
	if (p_score[a_root.first] > p_score[b_root.first]) { //�켱������ a�� �� �������
		dist[b_root.first] -= (b_root.second - a_root.second - cost);
		parent[b_root.first] = a_root.first;
		p_score[a_root.first] += p_score[b_root.first];
		p_score[b_root.first] = 1;
	}
	else {	//b�� �켱���� �� �������
		dist[a_root.first] += (b_root.second - a_root.second - cost);
		parent[a_root.first] = b_root.first;
		p_score[b_root.first] += p_score[a_root.first];
		p_score[a_root.first] = 1;
	}
}
*/
//�ٲ۰� ���ɸ��� ������
int find(int cur) {			
	if (cur == parent[cur]) return cur;	// �ֻ��� �θ�� return
	int par = find(parent[cur]);		// �ƴϸ� find�ϴ� ���ÿ� distance�� ������Ʈ�ϱ� ����
										// parent�� find����� �ҷ�����, �̸� �̿��ؼ� �Ÿ�, �ڱ��� parent�� parent�� parent�� ������Ʈ!
	dist[cur] += dist[parent[cur]];
	return parent[cur] = par;
}

void unify(int start, int end, int cost) {		//end�� start���� cost��ŭ �� ���̴�.
	int a_root = find(start);
	int b_root = find(end);

	if (a_root == b_root) return;	//�̹� ����Ǿ������� ��
									//�ƴϸ� ��ǥ�ڸ� ���ؼ� cost���ؾߵ�
									// ex) 1-3 : 50, 2-4: 100�϶�, 3�� �켱������ ������, 												// 2-3 : 150�� ���´ٸ�
									// 1-2 �� -100�ϲ���. 
	if (p_score[a_root] > p_score[b_root]) { //�켱������ a�� �� �������
		dist[b_root] = (dist[start] - dist[end] - cost);
		parent[b_root] = a_root;
		p_score[a_root] += p_score[b_root];
		p_score[b_root] = 1;
	}
	else {	//b�� �켱���� �� �������
		dist[a_root] = (dist[start] - dist[end] - cost)*(-1);
		parent[a_root] = b_root;
		p_score[b_root] += p_score[a_root];
		p_score[a_root] = 1;
	}
}

int main() {
	int n, m;
	int a, b, c;
	char work;
	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		//disjoint set initialize;
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
			dist[i] = 0;
			p_score[i] = 1;
		}

		for (int w = 0; w < m; w++) {
			scanf("%c", &work);		//\n ���ֱ� ���� ��� ��
			scanf("%c %d %d", &work, &a, &b);
			if (work == '!') {	// �������, �����Է�
								//scanf("%d %d %d", &a, &b, &c);
				scanf("%d", &c);
				unify(a, b, c);
				//disjoint set �߰�
			}
			else if (work == '?') {	//parent ���� ������ �Ÿ�����
									//scanf("%d %d", &a, &b);
				int one, two;
				one = find(a);
				two = find(b);
				if (one == two) {// a,b parent�� ����?
								// ������ �� �Ÿ� ��� ((a~parent�Ÿ�)-(b~parent�Ÿ�))
					printf("%lld\n", dist[a]-dist[b]);
				}
				else {//�ƴϸ� 0���
					printf("UNKNOWN\n");
				}
			}
		}
	}
}