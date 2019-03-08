/*
정답률이 낮은 문제이지만
점화식을 잘 생각하면 문제는 쉽게 풀린다.
논리적으로 점화식을 잘 유추하는게 키 포인트
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[100001];
int arr[100001];
int main() {
	memset(dp, 0, sizeof(dp));
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}

	int result = -1001;

	for (int i = 0; i <  n; i++) {
		result = max(result, dp[i]);
	}

	cout << result << '\n';
	

	return 0;
}