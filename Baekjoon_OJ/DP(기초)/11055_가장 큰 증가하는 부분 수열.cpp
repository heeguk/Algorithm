#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1000];
int arr[1000];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + arr[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
}