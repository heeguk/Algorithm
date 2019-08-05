#include <iostream>
#include <cstring>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int N, M, P;

long long dp[101][101][101];
long long check[101][101][101];

long long solve(int k, int x, int y) {
	if (check[k][x][y])
		return dp[k][x][y];
	
	//cout << k << " " << x << " " << y << endl;
	if (k == 0) {
		if (x == 0 && y == N)	return 1;
		else return 0;
	}
	if (x < 0)	return 0;
	if (y > N)	return 0;

	check[k][x][y] = 1;

	dp[k][x][y] += solve(k - 1, x - 1, y + 1) * (y + 1);
	dp[k][x][y] %= MOD;

	if (x > M) {
		dp[k][x][y] += solve(k - 1, x, y) * (x - M);
		dp[k][x][y] %= MOD;
	}

	return dp[k][x][y] % MOD;
}


int main() {
	cin >> N >> M >> P;
	memset(check, 0, sizeof(check));
	memset(dp, 0, sizeof(dp));
	dp[0][0][N] = 1;
	
	cout << solve(P, N, 0)<< '\n';
}