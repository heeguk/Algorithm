#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1000];
int dp2[1000];
vector<int >arr;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	reverse(arr.begin(), arr.end());
	dp2[0] = 1;
	for (int i = 1; i < n; i++) {
		dp2[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i] + dp2[n - i - 1] - 1);
	}
	cout << ans;
}