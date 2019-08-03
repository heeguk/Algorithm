#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

bool dp[31][31][31][31 * 30];
vector<char> ans;
int N, K;
void solve(int l, int a, int b, int k) {
	if (dp[l][a][b][k] == 1)	return;
	dp[l][a][b][k] = 1;
	if (k > K)	return;
	if (l == N && k == K) {
		for (int i = 0; i < ans.size(); i++)	cout << ans[i];
		exit(0);
	}
	if (l == N)	return;
	

	// A를 추가
	ans.push_back('A');
	solve(l + 1, a + 1, b, k);
	ans.pop_back();
	// B를 추가
	ans.push_back('B');
	solve(l + 1, a, b + 1, k + a);
	ans.pop_back();
	// C를 추가
	ans.push_back('C');
	solve(l + 1, a, b, k + a + b);
	ans.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, 0, sizeof(dp));
	cin >> N >> K;
	//dp[0][0][0][0] = 1;
	solve(0, 0, 0, 0);
	cout << -1;
	return 0;
}