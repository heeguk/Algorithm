#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int map[100][100];
bool check[100][100][4];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int ans = 0;
vector<pair<int, int>> hole[11];

class node {
public:
	int y;
	int x;
	int d;

	node(int a, int b, int c) {
		y = a, x = b, d = c;
	}
};

void bfs(int sy, int sx, int sd) {
	int ny, nx, nd;
	ny = sy, nx = sx, nd = sd;

	int score = 0;
	while (1) {
		ny += dy[nd];
		nx += dx[nd];

		//게임이 끝나는 경우
		if ((ny == sy && nx == sx) || map[ny][nx] == -1) {
			ans = max(ans, score);
			break;
		}
		// 벽과 부딪히는 경우
		if (ny >= N || ny < 0 || nx >= N || nx < 0) {
			nd = (nd + 2) % 4;
			score = score * 2 + 1;
			ans = max(ans, score);
			return;
		}
		else {
			if (map[ny][nx] >= 6 && map[ny][nx] <= 10) {
				int index = map[ny][nx];
				pair<int, int> h = hole[index][0];
				pair<int, int> h2 = hole[index][1];
				if (h.first == ny && h.second == nx) {
					ny = h2.first, nx = h2.second;
				}
				else {
					ny = h.first, nx = h.second;
				}
			}
			else if (map[ny][nx] == 5) {
				nd = (nd + 2) % 4;
				score = score * 2 + 1;
				ans = max(ans, score);
				return;

			}
			else if (map[ny][nx] == 1) {
				if (nd == 0 || nd == 1) {
					nd = (nd + 2) % 4;

				}
				else if (nd == 2) {
					nd = 1;
				}
				else if (nd == 3) {
					nd = 0;
				}
				score++;
			}
			else if (map[ny][nx] == 2) {
				if (nd == 2 || nd == 1) {
					nd = (nd + 2) % 4;

				}
				else if (nd == 0) {
					nd = 1;
				}
				else if (nd == 3) {
					nd = 2;
				}
				score++;
			}
			else if (map[ny][nx] == 3) {
				if (nd == 2 || nd == 3) {
					nd = (nd + 2) % 4;

				}
				else if (nd == 0) {
					nd = 3;
				}
				else if (nd == 1) {
					nd = 2;
				}
				score++;
			}
			else if (map[ny][nx] == 4) {
				if (nd == 0 || nd == 3) {
					nd = (nd + 2) % 4;

				}
				else if (nd == 1) {
					nd = 0;
				}
				else if (nd == 2) {
					nd = 3;
				}
				score++;
			}
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int t = 0; t < tc; t++) {
		ans = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] >= 6 && map[i][j] <= 10) {
					hole[map[i][j]].push_back(make_pair(i, j));
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0) {
					for (int d = 0; d < 4; d++) {
						bfs(i, j, d);
					}
				}
			}
		}

		for (int i = 6; i < 11; i++) {
			hole[i].clear();
		}
		printf("#%d %d\n", t + 1, ans);
	}
}