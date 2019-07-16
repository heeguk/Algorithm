#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
bool check[9];
int num[9];

void solve(int index, int cnt, int start) {
	// M elements are selected
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[num[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	if (index >= N)
		return;

	for (int i = start; i < N; i++) {
		if (check[i])	continue;
		num[cnt] = i;
		check[i] = true;
		solve(index + 1, cnt + 1, i + 1);
		num[cnt] = 0;
		check[i] = false;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	solve(0, 0, 0);

}