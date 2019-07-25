#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int coin[100];
	int dp[10001];
	int N, K;
	cin >> N >> K;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	
	for (int i = 0; i < N; i++)	cin >> coin[i];

	for (int c = 0; c < N; c++) {
		for (int i = 1; i <= K; i++) {
			if (i - coin[c] < 0)	continue;
			dp[i] += dp[i - coin[c]];
		}
	}
	cout << dp[K] << endl;
}