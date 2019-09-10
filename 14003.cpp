#include <cstdio>
#include <vector>
#include <algorithm>

#pragma warning(disable:4996)
using namespace std;

int arr[1000001];
//int dp[1000001] = { 0, };
int par[1000001] = { 0, };
vector<pair<int,int> > stack;	// (����, index)

bool comp(pair<int,int> a, pair<int, int> b){
	return a.first < b.first;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		par[i] = i;
	}
	stack.push_back({ -1000000001,0 });
	stack.push_back({ arr[1],1 });
	int start, end;
	for (int i = 2; i <= n; i++) {
		//binary search�� stack���� �ڽ��� ��ġã�´�.
		// stack������ �ڱ��� ��ġ�� �� dp��
		start = 1;
		end = stack.size() - 1;
		if (stack[end].first < arr[i]) {	//�������� Ŭ�� ���ÿ� �ϳ� ����
			par[i] = stack[end].second;
			stack.push_back({ arr[i], i });
			//dp[i] = stack.size()-1;
			
			//printf("%d ����\n", arr[i]);
			//for (int i = 1; i < stack.size(); i++) {
			//	printf("%d ", stack[i].first);
			//}printf("\n");
			
			continue;
		}
		else {
			auto it = lower_bound(stack.begin(), stack.end(), pair<int,int>(arr[i], 0), comp)-stack.begin();

			//for (int i = 1; i < stack.size(); i++) {
			//	printf("%d ", stack[i].first);
			//}printf("\n");
			//printf("%d's lower bound : %d\n", arr[i],it);

			if (it >= 2) {
				par[i] = stack[it-1].second;
			}
			else {
				par[i] = i;
			}
			stack[it].first = arr[i];
			stack[it].second = i;
			//printf("->\n");
			//for (int i = 1; i < stack.size(); i++) {
			//	printf("%d ", stack[i].first);
			//}printf("\n");
			//arr[i]�� stack������ ��ġ ã��
		}

	}

	//printf("������� ������ : %d\n", max_i);
	int cur=stack[stack.size()-1].second;
	vector<int> ans;
	while (1) {
		ans.push_back(arr[cur]);
		if (par[cur] == cur || cur==1) break;
		else {
			cur = par[cur];
		}
	}
	printf("%d\n", ans.size());
	for (int i = ans.size() - 1; i >= 0; i--) {
		printf("%d ", ans[i]);
	}printf("\n");
	//for (int i = 1; i <= n; i++) {
	//	printf("%d ", par[i]);
	//}printf("\n");
}