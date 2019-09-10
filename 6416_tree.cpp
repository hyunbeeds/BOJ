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
	//m-> vertex저장, indegree->들어오는 간선 저장
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
			//처음 입력으로 들어온 vertex를 m에 추가해준다. 
			if (m.find(a) == m.end())
				m.insert({ a, nodeCnt++ });

			if (m.find(b) == m.end())
				m.insert({ b, nodeCnt++ });

			//만약 들어오는 간선이 두개인 노드가 있으면 트리가 아니다. 
			if (indegree.find(b) == indegree.end())
				indegree.insert({ b, 0 });
			else ans = false;
		}
		//트리를 보면 edge의 개수가 무조건 vertex개수보다 1개 많다.
		//그게아니면 쓸모없는 edge가 있는것! ex)loop
		if (edgeCnt > 0 && m.size() != edgeCnt + 1) ans = false;
		if (ans) printf("Case %d is a tree.\n", ++testCases);
		else printf("Case %d is not a tree.\n", ++testCases);
	}
}