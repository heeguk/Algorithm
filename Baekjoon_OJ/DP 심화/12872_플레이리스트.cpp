/*
상당히 까다로움.
DP 배열이 1, 2차원일 필요는 없음.
이 문제는 Top-down 방식으로 접근해야함.
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int N, M, P;

long long dp[101][101][101];

long long solve(int k, int x, int y) {
	if (dp[k][x][y] != 0)
		return dp[k][x][y];

	if (k == 0)
		return 0;

	if (k < x)
		return 0;

	if (k > 0 && x == 0)
		return 0;

	dp[k][x][y] += (solve(k - 1, x - 1, y + 1) * (y + 1)) % MOD;

	if (x >= M)
		dp[k][x][y] += (solve(k - 1, x, y) * (x - M)) % MOD;
	
	//cout << k << " " << x << " " << y << " is " << dp[k][x][y] << endl;

	return dp[k][x][y] % MOD;
}


int main() {
	cin >> N >> M >> P;
	memset(dp, 0, sizeof(dp));
	dp[0][0][N] = 1;
	cout << solve(P, N, 0) << '\n';
}