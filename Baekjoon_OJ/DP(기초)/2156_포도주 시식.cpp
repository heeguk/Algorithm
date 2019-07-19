#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[10001];
int arr[10001];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(max(arr[2] + arr[1], arr[2] + arr[0]), arr[0]+ arr[1]);
	for (int i = 3; i < N; i++) {
		dp[i] = max(max(arr[i] + arr[i - 1] + dp[i - 3], arr[i] + dp[i - 2]), dp[i - 1]);
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
}