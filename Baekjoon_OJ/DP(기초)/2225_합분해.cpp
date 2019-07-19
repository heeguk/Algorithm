#include <iostream>
#include <cstring>

using namespace std;

long long dp[201][201];

int main() {
	int N, K;
	cin >> N >> K;
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= N; i++)	dp[i][1] = 1;

	for (int k = 2; k <= K; k++) {
		for(int i = 0; i <= N; i++) {
			for (int j = 0; j <= i; j++) {
				dp[i][k] += dp[j][k - 1];
				dp[i][k] %= 1000000000;
			}
		}
	}
	cout << dp[N][K];
}