#include <iostream>

using namespace std;

int N, M;
bool check[9];
int num[9];

void solve(int index, int cnt, int start) {
	// M elements are selected
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}
	if (index >= N)
		return;

	for (int i = start; i <= N; i++) {
		num[cnt] = i;
		solve(index + 1, cnt + 1, i);
		num[cnt] = 0;
	}
}

int main() {
	cin >> N >> M;
	solve(0, 0, 1);

}