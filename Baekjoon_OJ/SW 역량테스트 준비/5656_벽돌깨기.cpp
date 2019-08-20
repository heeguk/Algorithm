#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, W, H;
vector<int> vec;
int map[15][12];
int cmap[15][12];
int ans = 12 * 15;
void bomb(int row, int col, int move) {
	cmap[row][col] = 0;
	for (int m = 1; m < move; m++) {
		if (row + m < H) {
			if (cmap[row + m][col] != 0) {
				bomb(row + m, col, cmap[row + m][col]);
			}
		}
		if (row - m >= 0) {
			if (cmap[row - m][col] != 0) {
				bomb(row - m, col, cmap[row - m][col]);
			}
		}
		if (col - m >= 0) {
			if (cmap[row][col - m] != 0) {
				bomb(row, col - m, cmap[row][col - m]);
			}
		}
		if (col + m < W) {
			if (cmap[row][col + m] != 0) {
				bomb(row, col + m, cmap[row][col + m]);
			}
		}
	}
}

void solve(int index) {
	int row, col;
	int move = 0;
	for (int i = 0; i < H; i++) {
		if (cmap[i][index] != 0) {
			row = i;
			col = index;
			move = cmap[row][col];
			bomb(row, col, move);
			break;
		}
	}

	queue<int> q;
	for (int c = 0; c < W; c++) {
		int start = 0;
		for (int r = 0; r < H; r++) {
			if (cmap[r][c] == 0) {
				start++;
			}
			else {
				q.push(cmap[r][c]);
			}
		}
		for (int r = 0; r < start; r++) {
			cmap[r][c] = 0;
		}
		for (int r = start; r < H; r++) {
			cmap[r][c] = q.front();
			q.pop();
		}
	}
}

void go(int index) {
	if (index == N) {
		if (ans == 0)
			return;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cmap[i][j] = map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			solve(vec[i]);
		}
		int result = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (cmap[i][j] != 0)	result++;
			}
		}
		ans = min(ans, result);
		return;
	}

	for (int i = 0; i < W; i++) {
		vec.push_back(i);
		go(index + 1);
		vec.pop_back();
	}

}


int main() {
	int tc;
	scanf("%d", &tc);
	for (int t = 0; t < tc; t++) {
		scanf("%d %d %d", &N, &W, &H);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		ans = 12 * 15;
		go(0);
		printf("#%d %d\n", t + 1, ans);
		vec.clear();
	}
}