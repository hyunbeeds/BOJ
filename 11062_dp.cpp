#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int t, n;
vector<int> arr;
int sum[1001][1001] = { 0, };
int dp[1001][1001] = { 0, };
// i-j�������� �����ϴ� ����� ��� �ִ�

int play(int start, int end) {
	if (start == end) return arr[start];
	if (dp[start][end] != 0) return dp[start][end];
	else {
		//�ڿ����̳� �տ��� �̳� ���� �ϳ��� �ִ밪�� ����
		dp[start][end] = max(arr[end] + sum[start][end - 1] - play(start, end - 1), arr[start] + sum[start + 1][end] - play(start+1,end));
		return dp[start][end];
	}
}
int main() {
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		arr = vector<int>(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sum[i][j] = 0;
				dp[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			int temp = 0;
			for (int j = i; j < n; j++) {
				temp += arr[j];
				sum[i][j] = temp;
			}
		}
		printf("%d\n", play(0, n - 1));
		
		arr.clear();
	}
}