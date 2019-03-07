#include <iostream>

using namespace std;

long long int dp[101][10];

int main() {
	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	int N;
	cin >> N;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0)
				dp[i][0] = dp[i - 1][1] % 1000000000;
			else if (j == 9)
				dp[i][9] = dp[i - 1][8] % 1000000000;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	long long int sum = 0;

	for (int i = 0; i <= 9; i++)
		sum += dp[N][i];

	cout << sum % 1000000000 << endl;

}