#include <iostream>
#include <algorithm>

using namespace std;

int R, C;
int map[4][4];
bool dir[4][4];
int ans = 0;

void solve(int index) {
	if (index == R * C) {
		int sum = 0;

		// row direction
		int row_sum = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (dir[i][j] == 0) {
					row_sum = row_sum * 10 + map[i][j];
				}
				else {
					sum += row_sum;
					row_sum = 0;
				}
			}
			sum += row_sum;
			row_sum = 0;
		}

		// col direction
		int col_sum = 0;
		for (int i = 0; i < C; i++) {
			for (int j = 0; j < R; j++) {
				if (dir[j][i] == 1) {
					col_sum = col_sum * 10 + map[j][i];
				}
				else {
					sum += col_sum;
					col_sum = 0;
				}
			}
			sum += col_sum;
			col_sum = 0;
		}

		ans = max(ans, sum);
		return;
	}


	int y = index / C;
	int x = index % C;
	
	dir[y][x] = 0;
	solve(index + 1);
	
	dir[y][x] = 1;
	solve(index + 1);
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	solve(0);
	cout << ans;
}