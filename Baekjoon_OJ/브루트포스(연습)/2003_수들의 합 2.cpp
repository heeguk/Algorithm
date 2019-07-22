#include <iostream>

using namespace std;



int main() {
	int N, M;
	int num[10001];
	int ans = 0;
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
			sum -= num[left];
			left++;
		}
		else if (sum == M) {
			ans++;
			right++;
			if (right >= N)
				break;
			sum += num[right];
		}
	}
	cout << ans;
}