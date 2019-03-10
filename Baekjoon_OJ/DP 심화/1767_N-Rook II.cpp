/*
������� ����.
������ ���ٹ��� �� ã�ƾ� �Ѵ�.
���� ���, �� �࿡ ���� 0��, 1��, 2�� �ִ� ���, �̷�������!
������ ���� ���̽��� �и��� ������ �� ã��!
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#define MOD 1000001

using namespace std;

int N, M, K;

long long dp[101][101][101];

long long solve(int k, int n, int m) {
	
	if (k < 0 || n < 0 || m < 0)
		return 0;

	if (dp[k][n][m] != -1)
		return dp[k][n][m];

	if (k != 0 && (n == 0 || m == 0))
		return 0;

	if (k == 0)
		return 1;

	dp[k][n][m] = 0;
	dp[k][n][m] += solve(k, n - 1, m) % MOD;
	dp[k][n][m] += solve(k - 1, n - 1, m - 1) * m % MOD;
	dp[k][n][m] += solve(k - 2, n - 1, m - 2) * m * (m - 1) / 2 % MOD;
	dp[k][n][m] += solve(k - 2, n - 2, m - 1) * (n - 1) * m % MOD;

	return dp[k][n][m] % MOD;
}


int main() {
	cin >> N >> M >> K;
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 1;
	cout << solve(K, N, M) << '\n';
}