#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// dp[길이][마지막 자리수]
long long int dp[101][10];

int main() {
	int N;
	cin >> N;
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++)	dp[1][i] = 1;
	
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][1] % 1000000000;
		for (int j = 1; j <= 8; j++)	dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		dp[i][9] = dp[i - 1][8] % 1000000000;
	}
	long long int sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += dp[N][i];
		sum %= 1000000000;
	}
	cout << sum << "\n";
}