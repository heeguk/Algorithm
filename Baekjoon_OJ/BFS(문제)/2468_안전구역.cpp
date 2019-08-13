#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
bool check[100][100];
bool check2[100][100];
int map[100][100];
int h_min, h_max;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny >= N || ny < 0 || nx >= N || nx < 0)	continue;
		if (check[ny][nx] == 0 && check2[ny][nx] == 0) {
			check2[ny][nx] = 1;
			dfs(ny, nx);
		}
	}
}

int main() {
	memset(check, 0, sizeof(check));
	scanf("%d", &N);
	h_min = 100;
	h_max = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			h_min = min(h_min, map[i][j]);
			h_max = max(h_max, map[i][j]);
		}
	}

	// 최소의 안전구역은 1이다.
	int ans = 1;
	queue<pair<int, int>> empty;
	queue<pair<int, int>> nq;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == h_min) {
				nq.push(make_pair(i, j));
				check[i][j] = 1;
			}
		}
	}

	

	for (int w = h_min; w <= h_max; w++) {
		memset(check, 0, sizeof(check));
		memset(check2, 0, sizeof(check2));
		queue<pair<int, int>> q;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] <= w) {
					q.push(make_pair(i, j));
					check[i][j] = 1;
				}
			}
		}
		int result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] == 0 && check2[i][j] == 0) {
					result++;
					check2[i][j] = 1;
					dfs(i, j);
				}
			}
		}
		ans = max(ans, result);
	}

	cout << ans;
}