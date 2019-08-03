#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[61][61][61];
int ans = 999999999;
void solve(int a, int b, int c, int t) {
	
	if (a <= 0 && b <= 0 && c <= 0) {
		ans = min(ans, t);
		return;
	}
	if (a < 0)	a = 0;
	if (b < 0)	b = 0;
	if (c < 0)	c = 0;
	if (dp[a][b][c] != -1 && dp[a][b][c] <= t)	return;

	dp[a][b][c] = t;
	
	int attack[3] = { 1, 3, 9 };
	do {
		solve(a - attack[0], b - attack[1], c - attack[2], t + 1);
	} while (next_permutation(attack + 0, attack + 3));
	
}

int main() {
	memset(dp, -1, sizeof(dp));
	int hp[3] = {0, 0, 0};
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> hp[i];
	}
	solve(hp[0], hp[1], hp[2], 0);
	cout << ans;
}