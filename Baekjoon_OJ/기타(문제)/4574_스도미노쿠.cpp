#include <iostream>
#include <cstring>

using namespace std;

int N;

bool row[10][10];
bool col[10][10];
bool square[10][10];
int map[10][10];
int ok = 0;
bool domino[10][10];

int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

int get_square(int y, int x) {
	return ((y / 3) * 3 + x / 3);
}

void go(int index) {
	if (ok)	return;
	if (index == 81) {
		ok = 1;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j];
			}
			cout << endl;
		}
		return;
	}

	int y = index / 9, x = index % 9;
	int snum = get_square(y, x);

	if (map[y][x] > 0)	go(index + 1);
	else {
		for (int k = 0; k < 2; k++) {
			int ny = y + dy[k], nx = x + dx[k];
			if (ny >= 9 || nx >= 9)	continue;
			for (int i = 1; i <= 9; i++) {
				if (row[y][i] == 0 && col[x][i] == 0 && square[snum][i] == 0) {
					for (int j = 1; j <= 9; j++) {
						if (i == j)	continue;
						if (map[ny][nx] != 0)	continue;
						if (domino[i][j] || domino[j][i])	continue;
						if (row[ny][j] == 0 && col[nx][j] == 0 && square[get_square(ny, nx)][j] == 0) {
							row[y][i] = true;
							col[x][i] = true;
							square[snum][i] = true;
							row[ny][j] = 1;
							col[nx][j] = 1;
							square[get_square(ny, nx)][j] = 1;
							map[y][x] = i;
							map[ny][nx] = j;
							domino[i][j] = 1;
							domino[j][i] = 1;

							go(index + 1);


							row[y][i] = 0;
							col[x][i] = 0;
							square[snum][i] = 0;
							row[ny][j] = 0;
							col[nx][j] = 0;
							square[get_square(ny, nx)][j] = 0;
							map[y][x] = 0;
							map[ny][nx] = 0;
							domino[i][j] = 0;
							domino[j][i] = 0;
						}
					}
				}
			}
		}
		
		
	}
	
}

int main() {
	int tc = 1;
	while (1) {
		ok = 0;
		cin >> N;
		if (N == 0) break;
		
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(square, 0, sizeof(square));
		memset(map, 0, sizeof(map));
		memset(domino, 0, sizeof(domino));
		for (int i = 0; i < N; i++) {
			int n1, n2;
			char r1, r2, c1, c2;
			cin >> n1 >> r1 >> c1 >> n2 >> r2 >> c2;
			map[r1 - 'A'][c1 - '1'] = n1;
			map[r2 - 'A'][c2 - '1'] = n2;
			row[r1 - 'A'][n1] = true;
			row[r2 - 'A'][n2] = true;
			col[c1 - '1'][n1] = true;
			col[c2 - '1'][n2] = true;
			domino[n1][n2] = true;
			domino[n2][n1] = true;
			square[get_square(r1 - 'A', c1 - '1')][n1] = true;
			square[get_square(r2 - 'A', c2 - '1')][n2] = true;
		}
		

		for (int i = 1; i <= 9; i++) {
			char r1, c1;
			cin >> r1 >> c1;
			map[r1 - 'A'][c1 - '1'] = i;
			row[r1 - 'A'][i] = true;
			col[c1 - '1'][i] = true;
			square[get_square(r1 - 'A', c1 - '1')][i] = true;
		}
		cout << "Puzzle " << tc << '\n';
		go(0);
		tc++;
		
	}
}