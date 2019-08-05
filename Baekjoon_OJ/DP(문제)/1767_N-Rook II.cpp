#include <iostream>
#include <cstring>

using namespace std;

int N, M, K;
long long dp[101][101][101];
long long solve(int n, int m, int k) {
	//cout << n << " " << m << " " << k << endl;
	if (n < 0 || m < 0 || k < 0)	return 0;
	if (dp[n][m][k] != -1)	return dp[n][m][k];
	if (k == 0) return 1;
	
	//if (n == 0 && k == 0)	return 1;
	

	
	dp[n][m][k] = 0;
	// N 번째 행에 룩을 놓지 않는 경우
	dp[n][m][k] += solve(n - 1, m, k);
	dp[n][m][k] %= 1000001;
	// N 번째 행에 룩을 1개 놓는 경우
	dp[n][m][k] += solve(n - 1, m - 1, k - 1) * m + solve(n - 2, m - 1, k - 2) * m * (n - 1);
	dp[n][m][k] %= 1000001;
	// N 번째 행에 룩을 2개 놓는 경우
	dp[n][m][k] += solve(n - 1, m - 2, k - 2) * m * (m - 1) / 2;
	dp[n][m][k] %= 1000001;
	return dp[n][m][k];
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K;
	cout << solve(N, M, K);
	
}