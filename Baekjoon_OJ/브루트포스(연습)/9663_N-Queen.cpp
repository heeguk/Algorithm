#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;

int ans = 0;
bool col[15];
vector<pair<int, int>> queen;

bool valid(int index) {
	pair<int, int> A = queen[index];
	for (int i = 0; i < index; i++) {
		pair<int, int> B = queen[i];
		if (abs(A.first - B.first) == abs(A.second - B.second))
			return false;
	}
	return true;
}

void solve(int index) {
	if (index == N) {
		ans++;
	}
	for (int i = 0; i < N; i++) {
		if (col[i])	continue;
		col[i] = true;
		queen.push_back(make_pair(index, i));
		if (valid(index)) {
			solve(index + 1);
		}
		col[i] = false;
		queen.pop_back();
	}
}

int main() {
	memset(col, 0, sizeof(col));
	cin >> N;
	solve(0);
	cout << ans;
}