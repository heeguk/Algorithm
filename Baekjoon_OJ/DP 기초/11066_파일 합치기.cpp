#include <iostream>
#include <cstring>
#include <algorithm>

#define INF 100000000

using namespace std;

long long dp[501][501];
int arr[501];
long long sum[501];
int n;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		
		memset(dp, -1, sizeof(dp));
		cin >> n;
		arr[0] = 0;
		sum[0] = 0;
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
			dp[i][i] = 0;
			sum[i] = arr[i] + sum[i - 1];
		}
		
		for (int c = 1; c <= n - 1; c++) {
			for (int i = 1; i + c <= n; i++) {
				int j = i + c;
				dp[i][j] = INF;
				for (int k = i; k <= j - 1; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
				}
			}
		}

		cout << dp[1][n] << '\n';
	}

	

}