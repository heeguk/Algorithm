#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[100000];
int dp[100000];
int dp_rev[100000];
vector<int> arr_rev;

int main() {
	int N;	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr_rev.push_back(arr[i]);
	}
	reverse(arr_rev.begin(), arr_rev.end());
	dp[0] = arr[0];
	dp_rev[0] = arr_rev[0];

	//수를 제거하지 않았을 때
	int ans = dp[0];
	for (int i = 1; i < N; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		dp_rev[i] = max(dp_rev[i - 1] + arr_rev[i], arr_rev[i]);
		ans = max(ans, dp[i]);
	}
	
	// 수를 제거하였을 때
	ans = max(ans, dp_rev[N - 2]);
	for (int i = 1; i <= N - 2; i++) {
		ans = max(ans, dp[i - 1] + dp_rev[N - 2 - i]);
	}
	ans = max(ans, dp[N - 2]);

	cout << ans;
}