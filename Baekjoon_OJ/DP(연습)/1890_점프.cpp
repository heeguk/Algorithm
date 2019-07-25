#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int map[100][100];
long long dp[100][100];
int N;
int main() {
	memset(dp, 0, sizeof(dp));
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int move = map[i][j];
			if (move == 0) continue;
			if (i + move < N) {
				dp[i + move][j] += dp[i][j];
			}
			if (j + move < N) {
				dp[i][j + move] += dp[i][j];
			}
		}
	}


	cout << dp[N - 1][N - 1] << endl;
}