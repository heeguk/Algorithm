/*
음반을 만들 수 있는 경우의 수를 배열로 만들어서 표현.
Top-down 방식의 접근을 이용
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define MOD 1000000007

using namespace std;

int N, A, B, C;
long long dp[51][51][51][51];

int combination[7][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {1, 1, 1} };

long long solve(int n, int a, int b, int c) {
	if (dp[n][a][b][c] != -1) {
		return dp[n][a][b][c];
	}

	if (n == 0) {
		if (a == 0 && b == 0 && c == 0)
			return 1;
		else
			return 0;
	}

	dp[n][a][b][c] = 0;

	for (int i = 0; i < 7; i++) {
		int new_a = a - combination[i][0];
		int new_b = b - combination[i][1];
		int new_c = c - combination[i][2];
		if (new_a < 0 || new_b < 0 || new_c < 0)
			continue;

		dp[n][a][b][c] += solve(n - 1, new_a, new_b, new_c) % MOD;
	}

	return dp[n][a][b][c] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> N >> A >> B >> C;

	dp[0][0][0][0] = 1;

	cout << solve(N, A, B, C) << '\n';
}