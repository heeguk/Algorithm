#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool row[100];
bool col[100];
int N, L;
int map[100][100];


bool row_same(int r, int from, int to) {
	int n = map[r][from];
	for (int i = from + 1; i <= to; i++) {
		if (n != map[r][i])
			return 0;
	}
	return 1;
}

bool col_same(int c, int from, int to) {
	int n = map[from][c];
	for (int i = from + 1; i <= to; i++) {
		if (n != map[i][c])
			return 0;
	}
	return 1;
}

void checked(int check[100], int from, int to) {
	for (int i = from; i <= to; i++) {
		check[i]++;
	}
}

int main() {
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	// row를 체크
	for (int r = 0; r < N; r++) {
		int low = map[r][0];
		int high = map[r][0];
		for (int c = 0; c < N; c++) {
			low = min(low, map[r][c]);
			high = max(high, map[r][c]);
		}
		int diff = high - low;
		if (diff == 0)	ans++;
		else if (diff != 0)	row[r] = true;
	}

	for (int c = 0; c < N; c++) {
		int low = map[0][c];
		int high = map[0][c];
		for (int r = 0; r < N; r++) {
			low = min(low, map[r][c]);
			high = max(high, map[r][c]);
		}
		int diff = high - low;
		if (diff == 0)	ans++;
		else if (diff != 0)	col[c] = true;
	}

	int check[100];
	for (int r = 0; r < N; r++) {
		// 같은 row에 있는 원소들의 높이 차이가 1일때
		if (row[r]) {
			memset(check, 0, sizeof(check));
			int possible = 1;
			for (int c = 0; c < N - 1;) {
				if (map[r][c] == map[r][c + 1]) {
					c++;
					continue;
				}
				if (map[r][c] > map[r][c + 1]) {
					if (c + L >= N || map[r][c] - map[r][c + 1] != 1) {
						possible = 0;
						break;
					}
					bool same = row_same(r, c + 1, c + L);
					if (!same) {
						possible = 0;
						break;
					}
					else {
						checked(check, c + 1, c + L);
						c = c + L;
					}
				}
				else if (map[r][c] < map[r][c + 1]) {
					if (c - L + 1< 0 || map[r][c + 1] - map[r][c] != 1) {
						possible = 0;
						break;
					}
					if (check[c - L + 1] == 1) {
						possible = 0;
						break;
					}
					bool same = row_same(r, c - L + 1, c);
					if (!same) {
						possible = 0;
						break;
					}
					else {
						checked(check, c - L + 1, c);
						c++;
					}
				}
			}
			if (possible) {
				ans++;
			}
		}
	}

	for (int c = 0; c < N; c++) {
		// 같은 row에 있는 원소들의 높이 차이가 1일때
		if (col[c]) {
			memset(check, 0, sizeof(check));
			int possible = 1;
			for (int r = 0; r < N - 1;) {
				
				if (map[r][c] == map[r + 1][c]) {
					r++;
					continue;
				}
				if (map[r][c] > map[r + 1][c]) {
					if (r + L >= N || map[r][c] - map[r + 1][c] != 1) {
						possible = 0;
						break;
					}
					bool same = col_same(c, r + 1, r + L);
					if (!same) {
						possible = 0;
						break;
					}
					else {
						checked(check, r + 1, r + L);
						r = r + L;
					}
				}
				else if (map[r][c] < map[r + 1][c]) {
					if (r - L + 1 < 0 || map[r + 1][c] - map[r][c] != 1) {
						possible = 0;
						break;
					}
					if (check[r - L + 1] == 1) {
						possible = 0;
						break;
					}
					bool same = col_same(c, r - L + 1, r);
					if (!same) {
						possible = 0;
						break;
					}
					else {
						checked(check, r - L + 1, r);
						r++;
					}
				}
			}
			if (possible) {
				ans++;
			}
		}
	}
	cout << ans;
}
