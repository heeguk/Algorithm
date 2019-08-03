#include <iostream>
#include <string>
#include <cstring>

using namespace std;

long long dp[51][51][51][51];
int S, A, B, C;
long long mod = 1000000007;

long long solve(int s, int a, int b, int c) {
	if (s == 0 && a == 0 && b == 0 && c == 0)	return 1;
	if (a < 0 || b < 0 || c < 0)	return 0;
	if (s == 0)	return 0;

	if (dp[s][a][b][c] != -1)	return dp[s][a][b][c];

	dp[s][a][b][c] = 0;
	dp[s][a][b][c] = solve(s - 1, a - 1, b, c) + solve(s - 1, a, b - 1, c) + solve(s - 1, a, b, c - 1) + solve(s - 1, a - 1, b - 1, c)
		+ solve(s - 1, a, b - 1, c - 1) + solve(s - 1, a - 1, b, c - 1) + solve(s - 1, a - 1, b - 1, c - 1);
	dp[s][a][b][c] %= mod;
	
	return dp[s][a][b][c];
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> S >> A >> B >> C;
	if (S > A + B + C) {
		cout << 0;
		return 0;
	}
	solve(S, A, B, C);
	cout << dp[S][A][B][C];
	return 0;
}