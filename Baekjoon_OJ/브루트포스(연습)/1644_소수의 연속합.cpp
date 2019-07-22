#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
bool prime[4000001];
vector<int> prime_vec;

void prime_solve(int n) {
	for (int i = 2; i <= n; i++) {
		if (!prime[i])	continue;
		for (int j = i * 2; j <= n; j+=i) {
			prime[j] = false;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (!prime[i])	continue;
		prime_vec.push_back(i);
	}
}

int main() {
	memset(prime, 1, sizeof(prime));
	prime[0] = false, prime[1] = false;
	cin >> N;
	prime_solve(N);
	
	if (N == 1) {
		cout << 0;
		return 0;
	}


	int ans = 0;
	int left = 0;
	int right = 0;
	int sum = prime_vec[0];

	while (right < prime_vec.size()) {
		if (sum == N) {
			ans++;
			right++;
			if (right >= prime_vec.size())
				break;
			sum += prime_vec[right];
		}
		else if (sum > N) {
			sum -= prime_vec[left];
			left++;
		}
		else if (sum < N) {
			right++;
			if (right >= prime_vec.size())
				break;
			sum += prime_vec[right];
		}
	}
	cout << ans;
}