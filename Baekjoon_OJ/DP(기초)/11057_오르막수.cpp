#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// dp[길이][마지막 자리수]
long long int dp[1001][10];

int main() {
	int N;
	cin >> N;
	dp[1][0] = 0;
	for (int i = 0; i < 10; i++)	dp[1][i] = 1;
	
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 10007;
			}
		}
	}
	long long int sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += dp[N][i];
		sum %= 10007;
	}
	cout << sum << "\n";
}