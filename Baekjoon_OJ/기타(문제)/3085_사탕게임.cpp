#include <iostream>
#include <algorithm>

using namespace std;

char map[50][50];
int N;
int ans = 1;
void check() {
	for (int r = 0; r < N; r++) {
		int cnt = 1;
		for (int c = 1; c < N; c++) {
			if (map[r][c - 1] == map[r][c]) {
				cnt++;
			}
			else {
				cnt = 1;
			}
			ans = max(ans, cnt);
		}
	}
	
	for (int c = 0; c < N; c++) {
		int cnt = 1;
		for (int r = 1; r < N; r++) {
			if (map[r - 1][c] == map[r][c]) {
				cnt++;
			}
			else {
				cnt = 1;
			}
			ans = max(ans, cnt);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j + 1 < N) {
				swap(map[i][j], map[i][j + 1]);
				check();
				swap(map[i][j], map[i][j + 1]);
			}
			if (i + 1 < N) {
				swap(map[i][j], map[i + 1][j]);
				check();
				swap(map[i][j], map[i + 1][j]);
			}
		}
	}

	cout << ans;
}