#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, K;
bool check[51][51][1276];
vector<char> ans;

void solve(int n, int a, int k) {
	if (check[n][a][k])	return;
	if (n == N) {
		if (k == K) {
			for (int i = 0; i < ans.size(); i++)	cout << ans[i];
			exit(0);
		}
		else
		{
			return;
		}
	}
	check[n][a][k] = 1;
	// 'A'를 추가
	ans.push_back('A');
	solve(n + 1, a + 1, k);
	ans.pop_back();
	// 'B'를 추가
	ans.push_back('B');
	solve(n + 1, a, k + a);
	ans.pop_back();
}
int main() {
	memset(check, 0, sizeof(check));
	cin >> N >> K;
	solve(0, 0, 0);
	cout << -1;
}