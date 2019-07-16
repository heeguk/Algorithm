#include <iostream>
#include <vector>

using namespace std;

int N, S;
int ans = 0;
vector<int> vec;

void go(int index, int sum) {
	if (index == N) {
		if(sum == S)
			ans++;
		return;
	}
	
	go(index + 1, sum + vec[index]);
	go(index + 1, sum);
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int in;
		cin >> in;
		vec.push_back(in);
	}

	// 0인 경우 정답에 공집합이 포함된다.
	if (S == 0)	ans--;
	go(0, 0);
	cout << ans << '\n';
}