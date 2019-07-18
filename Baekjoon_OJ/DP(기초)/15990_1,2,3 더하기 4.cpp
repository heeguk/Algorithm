#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long dp[100001][3];

int main() {
	int tc;
	cin >> tc;
	int prev = 3;
	memset(dp, 0, sizeof(dp));
	for (int t = 0; t < tc; t++) {
		int N;
		cin >> N;
		dp[0][0] = 1;
		dp[1][0] = 1;
		dp[2][1] = 1;

		for (int i = prev; i <= N; i++) {
			dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % 1000000009;
			dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % 1000000009;
			dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % 1000000009;
		}
		long long ans = dp[N][0] + dp[N][1] + dp[N][2];
		ans %= 1000000009;
		cout << ans <<"\n";
		if (prev < N)
			prev = N;
		
	}
	
	
}