/*
아이디어는 쉽지만
vector에서 제공하는 함수를 잘 모른다면 풀기 어려움
erase와 insert 함수를 사용해야 풀 수 있음.
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

int N, M;
int result = 0;
vector<int> bead;

void solve(int n, int sum) {
	if (n == 2) {
		result = max(result, sum);
		return;
	}

	for (int i = 1; i < n - 1; i++) {
		int temp = bead[i];
		int local_sum = bead[i - 1] * bead[i + 1];
		bead.erase(bead.begin() + i);
		solve(n - 1, sum + local_sum);
		bead.insert(bead.begin() + i, temp);
	}
}

int main() {
	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		bead.push_back(num);
	}

	solve(N, 0);

	cout << result << '\n';
}