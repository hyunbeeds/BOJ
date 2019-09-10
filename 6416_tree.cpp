#include <cstdio>
#include <vector>
#include <map>
#pragma warning(disable:4996)
using namespace std;

int main() {
	long long a, b;
	long long edge_cnt;
	long long testCases = 0;
	map<long long, long long> m, indegree;
	//m-> vertex����, indegree->������ ���� ����
	while (1) {
		bool ans = true;
		long long a, b;
		long long edgeCnt = 0;
		long long nodeCnt = 0;
		m.clear();
		indegree.clear();
		while (scanf("%lld%lld", &a, &b), (a || b)) {
			if (a == -1 && b == -1) return 0;
			edgeCnt++;
			//ó�� �Է����� ���� vertex�� m�� �߰����ش�. 
			if (m.find(a) == m.end())
				m.insert({ a, nodeCnt++ });

			if (m.find(b) == m.end())
				m.insert({ b, nodeCnt++ });

			//���� ������ ������ �ΰ��� ��尡 ������ Ʈ���� �ƴϴ�. 
			if (indegree.find(b) == indegree.end())
				indegree.insert({ b, 0 });
			else ans = false;
		}
		//Ʈ���� ���� edge�� ������ ������ vertex�������� 1�� ����.
		//�װԾƴϸ� ������� edge�� �ִ°�! ex)loop
		if (edgeCnt > 0 && m.size() != edgeCnt + 1) ans = false;
		if (ans) printf("Case %d is a tree.\n", ++testCases);
		else printf("Case %d is not a tree.\n", ++testCases);
	}
}