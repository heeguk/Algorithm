#include <iostream>
#include <cstring>

using namespace std;

int N, M, H;
int map[31][11];


bool simulate() {
	for (int i = 0; i < N; i++) {
		int x = i;
		for (int y = 0; y < H; y++) {
			if (map[y][x] == 1)	x++;
			else if (map[y][x] == 2) x--;
		}
		if (x != i)
			return false;
	}
	return true;
}

void solve(int cnt, int target_cnt, int y, int x) {
	if (cnt == target_cnt) {
		int ok = simulate();
		if (ok) {
			cout << cnt;
			exit(0);
		}
		return;
	}

	// 이 점에서는 더 이상 가로 선을 추가할 수 없음
	if (y == H - 1 && x == N - 1)	return;

	x++;
	if (x == N) {
		x = 0;
		y++;
	}
	if (x + 1 < N && map[y][x] == 0 && map[y][x + 1] == 0) {
		map[y][x] = 1;
		map[y][x + 1] = 2;
		solve(cnt + 1, target_cnt, y, x);
		map[y][x] = 0;
		map[y][x + 1] = 0;
	}
	solve(cnt, target_cnt, y, x);
}

int main() {
	memset(map, 0, sizeof(map));
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a - 1][b - 1] = 1;
		map[a - 1][b] = 2;
	}

	for (int i = 0; i <= 3; i++) {
		solve(0, i, 0, 0);
	}
	cout << -1;
}