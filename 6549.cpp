#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int arr[100001];
stack<int> s;
int main() {
	int n;

	while (1) {
		scanf("%d", &n);
		if (n == 0)	break;
		for (int i = 0;i < n;i++) {
			scanf("%d", &arr[i]);
		}
		long long int ans = 0;
		int left = 0;
		for (int i = 0;i < n;i++) {
			left = i;
			//stack���� ���� ���̺��� ������ stack���� �ٺ����ߵ�
			while (!s.empty() && arr[s.top()] > arr[i]) {
				long long int height = arr[s.top()];
				s.pop();
				long long int width = i;
				if (!s.empty()) {
					width = (long long int)(i - s.top() - 1);
				}
				
				if (ans < width * height) {
					ans = width * height;
				}
			}
			s.push(i);
		}
		//�������� stack�� �����ִ°��(�����ʳ��� �������ΰ��)
		while (!s.empty()) {
			long long int height = arr[s.top()];
			s.pop();

			long long int width = n;
			if (!s.empty()) {
				width = (long long int)(n - s.top() - 1);
			}
			
			if (ans < width * height) {
				ans = width * height;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;

}