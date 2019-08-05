#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, a, b, X, Y;
int garo[500];
int dp[501][101];

int main() {
	cin >> N >> M >> a >> b >> X >> Y;
	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		garo[i] = n;
	}

	for (int i = 1; i <= N; i++) {
		dp[0][i] = abs(a - i) * Y;
	}


	for (int i = 0; i < M; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i + 1][j] = 2000000000;
			for (int k = 1; k <= N; k++) {
				if (j == k) {
					if (garo[i] == j || garo[i] == j - 1) {
						dp[i + 1][j] = min(dp[i + 1][j], dp[i][k] + X);
					}
					else {
						dp[i + 1][j] = min(dp[i + 1][j], dp[i][k]);
					}
				}
				else {
					if ((garo[i] < k && garo[i] >= j) || (garo[i] >= k && garo[i] < j))
						dp[i + 1][j] = min(dp[i + 1][j], dp[i][k] + (abs(k - j) - 1) * Y);
					else
						dp[i + 1][j] = min(dp[i + 1][j], dp[i][k] + abs(k - j) * Y);

				}
			}
		}
	}
	cout << dp[M][b];
}