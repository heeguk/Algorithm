#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int coin[100];
	int dp[10001];
	int N, K;
	cin >> N >> K;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	
	for (int i = 0; i < N; i++)	cin >> coin[i];

	for (int c = 0; c < N; c++) {
		for (int i = 1; i <= K; i++) {
			if (i - coin[c] < 0)	continue;
			if (dp[i - coin[c]] != -1) {
				if (dp[i] == -1) {
					dp[i] = dp[i - coin[c]] + 1;
				}
				else {
					dp[i] = min(dp[i], dp[i - coin[c]] + 1);
				}
			}
			
		}
	}
	cout << dp[K] << endl;
}