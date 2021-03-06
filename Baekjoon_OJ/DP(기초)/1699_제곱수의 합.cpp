#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[100001];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)	dp[i] = i;
	for (int i = 1; i*i <= N; i++)	dp[i*i] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j*j < i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[N];
}