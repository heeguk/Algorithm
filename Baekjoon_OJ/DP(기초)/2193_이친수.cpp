#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// dp[길이][마지막 자리수]
long long int dp[91];

int main() {
	int N;
	cin >> N;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	for (int i = 4; i <= N; i++)	dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[N] << "\n";
}