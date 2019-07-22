#include <iostream>
#include <cstring>
using namespace std;

int map[9][9];
bool row[9][10];
bool col[9][10];
bool matrix[9][10];

int get_location(int i, int j) {
	return ((i / 3) * 3 + j / 3);
}

void solve(int index) {
	if (index == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	int y = index / 9;
	int x = index % 9;

	if (map[y][x] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (!row[y][i] && !col[x][i] && !matrix[get_location(y, x)][i]) {
				map[y][x] = i;
				row[y][i] = true;
				col[x][i] = true;
				matrix[get_location(y, x)][i] = true;
				solve(index + 1);
				map[y][x] = 0;
				row[y][i] = false;
				col[x][i] = false;
				matrix[get_location(y, x)][i] = false;
			}
		}
	}
	else {
		solve(index + 1);
	}
}

int main() {
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(matrix, 0, sizeof(matrix));

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			row[i][map[i][j]] = true;
			col[j][map[i][j]] = true;
			matrix[get_location(i, j)][map[i][j]] = true;
		}
	}
	solve(0);
}