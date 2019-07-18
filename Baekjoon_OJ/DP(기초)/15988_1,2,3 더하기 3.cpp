#include <iostream>

using namespace std;

// D[N] = D[N-1] + D[N-2] + D[N-3]


int main() {
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int N;
		cin >> N;
		
		long long int dp[1000001];
		dp[0] = 1;
		dp[1] = dp[0];
		dp[2] = dp[1] + dp[0];
		for (int i = 3; i <= N; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
		}
		cout << dp[N]<<"\n";
	}

	
}