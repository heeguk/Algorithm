#include <iostream>
#include <cstring>

using namespace std;

int N;
int num[2000];
int dp[2000][2000];

int solve(int from, int to) {
	if(dp[from][to] != -1)
		return dp[from][to];

	if (from == to) {
		dp[from][to] = 1;
	}
	else if (from + 1 == to) {
		if(num[from] == num[to])
			dp[from][to] = 1;
		else
			dp[from][to] = 0;
	}
	else {
		if (num[from] == num[to]) {
			dp[from][to] = solve(from + 1, to - 1);
		}
		else {
			dp[from][to] = 0;
		}
	}
	return dp[from][to];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	int tc;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int from, to;
		cin >> from >> to;
		cout << solve(from - 1, to - 1) << "\n";
	}

}