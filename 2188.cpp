#include <cstdio>
#include <vector>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

int n, m;
vector<int> arr[201];
int visited[201];
int connect[201];

int dfs(int cur) {
	if (visited[cur]==1) return 0;
	visited[cur] = 1;
	for (int i = 0;i < arr[cur].size();i++) {
		int next = arr[cur][i];
		if (!connect[next] || dfs(connect[next])) {
			//���� ������ �ȵǾ��ְų�, �̹� ��Ī�� ���� �ٸ� ��ü���� �ִ� ���
			//�����Ҽ� �ִ� ���̹Ƿ�
			//�����ϰ� 1�� return �Ѵ�.
			connect[next] = cur;
			return 1;
		}
	}
	return 0;
}
int main() {
	scanf("%d%d", &n, &m);
	int num, temp;
	for (int i = 1;i <= n;i++){
		scanf("%d", &num);
		while (num--) {
			scanf("%d", &temp);
			arr[i].push_back(temp);
		}
	}
	int ret = 0;
	for (int i = 1;i <= n;i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i)) ret++;
	}
	printf("%d", ret);
}