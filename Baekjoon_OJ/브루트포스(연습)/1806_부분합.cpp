#include <iostream>
#include <algorithm>

using namespace std;



int main() {
	int N, M;
	int num[100001];
	int ans = 100001;
	int find = 0;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	int sum = num[0];
	int left = 0;
	int right = 0;
	while (1) {
		if (sum < M) {
			right++;
			if (right >= N)
				break;
			sum += num[right];
		}
		else if (sum > M) {
			ans = min(ans, right - left + 1);
			sum -= num[left];
			left++;
			find = 1;
		}
		else if (sum == M) {
			ans = min(ans, right - left + 1);
			right++;
			find = 1;
			if (right >= N)
				break;
			sum += num[right];
		}
	}
	if (find)
		cout << ans;
	else
		cout << 0;
}