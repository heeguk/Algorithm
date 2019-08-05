#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, K;

long long dp[1001][1001];

long long solve(int n, int k) {
	if (dp[n][k] != -1)	return dp[n][k];
	if (k > n)	return 0;
	if (k == 0)	return 1;
	if (k == 1)	return n;

	dp[n][k] = 0;
	dp[n][k] = solve(n - 1, k) % 10007 + solve(n - 1, k - 1) % 10007;
	dp[n][k] %= 10007;
	return dp[n][k];
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	long long ans = solve(N, K) % 10007;
	cout << ans;
}