#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<int> gen_dir(int index) {
	vector<int> ret;
	for (int i = 0; i < 5; i++) {
		ret.push_back(index & 3);
		index >>= 2;
	}
	return ret;
}

void copy_map(int a[20][20], int b[20][20], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void move_dir(int map[20][20], int dir, int N) {
	bool merged[20][20];
	memset(merged, 0, sizeof(merged));
	if (dir == 0) {	// 왼쪽
		for (int c = 1; c < N; c++) {
			for (int r = 0; r < N; r++) {
				if (map[r][c] != 0) {
					int cc = c, rr = r;
					while (1) {
						int nc = cc + dx[dir], nr = rr + dy[dir];
						if (nc >= N || nc < 0 || nr >= N || nr < 0)	break;
						if (map[nr][nc] == 0) {
							swap(map[nr][nc], map[rr][cc]);
							cc = nc, rr = nr;
						}
						else if (map[nr][nc] > 0) {
							if (map[nr][nc] == map[rr][cc] && merged[nr][nc] == 0 && merged[rr][cc] == 0) {
								map[nr][nc] *= 2;
								map[rr][cc] = 0;
								merged[nr][nc] = 1;
								cc = nc, rr = nr;
							}
							else
							{
								break;
							}
						}
					}
				}
			}
		}
	}
	else if (dir == 1) {	// 오른쪽
		for (int c = N - 2; c >= 0; c--) {
			for (int r = 0; r < N; r++) {
				if (map[r][c] != 0) {
					int cc = c, rr = r;
					while (1) {
						int nc = cc + dx[dir], nr = rr + dy[dir];
						if (nc >= N || nc < 0 || nr >= N || nr < 0)	break;
						if (map[nr][nc] == 0) {
							swap(map[nr][nc], map[rr][cc]);
							cc = nc, rr = nr;
						}
						else if (map[nr][nc] > 0) {
							if (map[nr][nc] == map[rr][cc] && merged[nr][nc] == 0 && merged[rr][cc] == 0) {
								map[nr][nc] *= 2;
								map[rr][cc] = 0;
								merged[nr][nc] = 1;
								cc = nc, rr = nr;
							}
							else
							{
								break;
							}
						}
					}
				}
			}
		}
	}
	else if (dir == 2) {	// 위
		for (int r = 1; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (map[r][c] != 0) {
					int cc = c, rr = r;
					while (1) {
						int nc = cc + dx[dir], nr = rr + dy[dir];
						if (nc >= N || nc < 0 || nr >= N || nr < 0)	break;
						if (map[nr][nc] == 0) {
							swap(map[nr][nc], map[rr][cc]);
							cc = nc, rr = nr;
						}
						else if (map[nr][nc] > 0) {
							if (map[nr][nc] == map[rr][cc] && merged[nr][nc] == 0 && merged[rr][cc] == 0) {
								map[nr][nc] *= 2;
								map[rr][cc] = 0;
								merged[nr][nc] = 1;
								cc = nc, rr = nr;
							}
							else
							{
								break;
							}
						}
					}
				}
			}
		}
	}
	else if (dir == 3) {	// 아래
		for (int r = N - 2; r >= 0; r--) {
			for (int c = 0; c < N; c++) {
				if (map[r][c] != 0) {
					int cc = c, rr = r;
					while (1) {
						int nc = cc + dx[dir], nr = rr + dy[dir];
						if (nc >= N || nc < 0 || nr >= N || nr < 0)	break;
						if (map[nr][nc] == 0) {
							swap(map[nr][nc], map[rr][cc]);
							cc = nc, rr = nr;
						}
						else if (map[nr][nc] > 0) {
							if (map[nr][nc] == map[rr][cc] && merged[nr][nc] == 0 && merged[rr][cc] == 0) {
								map[nr][nc] *= 2;
								map[rr][cc] = 0;
								merged[nr][nc] = 1;
								cc = nc, rr = nr;
							}
							else
							{
								break;
							}
						}
					}
				}
			}
		}
	}
}

void move(vector<int>& dir, int map[20][20], int N) {
	for (int i = 0; i < dir.size(); i++) {
		move_dir(map, dir[i], N);
	}
}

int get_max(int map[20][20], int N) {
	int m = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			m = max(m, map[i][j]);
		}
	}
	return m;
}

int main() {

	int N;
	int map[20][20];
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < (1 << 10); i++) {
		int cmap[20][20];
		copy_map(cmap, map, N);
		vector<int> dir = gen_dir(i);
		move(dir, cmap, N);
		int result = get_max(cmap, N);
		ans = max(ans, result);
	}
	cout << ans;
}