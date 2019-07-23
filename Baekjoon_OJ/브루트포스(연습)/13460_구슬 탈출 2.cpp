#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char rmap[10][10];
int dp[10][10][10][10]; //dp[red_y][red_x][blue_y][blue_x]
int hy, hx;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
queue<pair<int, int>> red, blue;
int R, C;

void copy_map(char a[10][10]) {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			a[i][j] = rmap[i][j];
}

// color 0:red, 1:blue
int move(int dir, int color, int& y, int& x, char map[10][10]) {
	int yy = y, xx = x;
	bool move = 0;
	while (1) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (map[ny][nx] == '#' || map[ny][nx] == 'R' || map[ny][nx] == 'B')	break;
		if (map[ny][nx] == 'O') {
			map[y][x] = '.';
			return 1;
		}
		swap(map[y][x], map[ny][nx]);
		y = ny, x = nx;
		move = 1;
	}

	if (move == 0)	return 0;
	return 2;
}

void move_set(int order, int dir, int ry, int rx, int by, int bx, int move_cnt, char map[10][10]) {
	int rry = ry, rrx = rx, bby = by, bbx = bx;
	if (order) {	// Red first
		int red_move = move(dir, 0, ry, rx, map);
		int blue_move = move(dir, 1, by, bx, map);
		
		if (blue_move == 1) {
			return;
		}
		else if (red_move == 1) {
			cout << move_cnt + 1;
			exit(0);
		}
		else if (red_move + blue_move == 0)	return;
		else {
			if (dp[ry][rx][by][bx] == -1) {
				dp[ry][rx][by][bx] = move_cnt + 1;
				red.push(make_pair(ry, rx));
				blue.push(make_pair(by, bx));
			}
		}
	}
	else {	// Blue first
		int blue_move = move(dir, 1, by, bx, map);
		int red_move = move(dir, 0, ry, rx, map);
		if (blue_move == 1) {
			return;
		}
		else if (red_move == 1) {
			cout << move_cnt + 1;
			exit(0);
		}
		else if (red_move + blue_move == 0)	return;
		else {
			if (dp[ry][rx][by][bx] == -1) {
				dp[ry][rx][by][bx] = move_cnt + 1;
				red.push(make_pair(ry, rx));
				blue.push(make_pair(by, bx));
			}
		}
	}

}

int main() {
	memset(dp, -1, sizeof(dp));
	
	cin >> R >> C;
	int ry1, rx1, by1, bx1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> rmap[i][j];
			if (rmap[i][j] == 'O') {
				hy = i, hx = j;
			}
			else if (rmap[i][j] == 'R') {
				red.push(make_pair(i, j));
				rmap[i][j] = '.';
				ry1 = i, rx1 = j;
			}
			else if (rmap[i][j] == 'B') {
				blue.push(make_pair(i, j));
				rmap[i][j] = '.';
				by1 = i, bx1 = j;
			}
		}
	}
	dp[ry1][rx1][by1][bx1] = 0;
	while (!red.empty() && !blue.empty()) {
		auto r_out = red.front();
		auto b_out = blue.front();
		red.pop();
		blue.pop();
		int ry = r_out.first;
		int rx = r_out.second;
		int by = b_out.first;
		int bx = b_out.second;
		int rry = ry, rrx = rx, bby = by, bbx = bx;
		int move_cnt = dp[ry][rx][by][bx];
		if (move_cnt == 10) {
			cout << -1;
			exit(0);
		}

		
		bool same_row = (ry == by);
		bool same_col = (rx == bx);

		// 4 방향으로 움직인다. 0: 왼쪽, 1: 오른쪽, 2: 위, 3: 아래
		for (int i = 0; i < 4; i++) {
			char map[10][10];
			copy_map(map);
			map[ry][rx] = 'R', map[by][bx] = 'B';
			if (i == 0 && same_row) {
				if (rx > bx) {
					move_set(0, i, ry, rx, by, bx, move_cnt, map);
				}
				else {
					move_set(1, i, ry, rx, by, bx, move_cnt, map);
				}
			}
			else if (i == 1 && same_row) {
				if (rx > bx) {
					move_set(1, i, ry, rx, by, bx, move_cnt, map);
				}
				else {
					move_set(0, i, ry, rx, by, bx, move_cnt, map);
				}
			}
			else if (i == 2 && same_col) {
				if (ry > by) {
					move_set(0, i, ry, rx, by, bx, move_cnt, map);
				}
				else {
					move_set(1, i, ry, rx, by, bx, move_cnt, map);
				}
			}
			else if (i == 3 && same_col) {
				if (ry > by) {
					move_set(1, i, ry, rx, by, bx, move_cnt, map);
				}
				else {
					move_set(0, i, ry, rx, by, bx, move_cnt, map);
				}
			}
			else {
				move_set(1, i, ry, rx, by, bx, move_cnt, map);
			}
		}
	}
	cout << -1;
}