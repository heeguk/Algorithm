#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>

int map[1000][1000];
int dp[1000][1000][2];

using namespace std;

int W, H;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


void bfs(int sy, int sx) {
	memset(dp, -1, sizeof(dp));
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(sy, sx, 0));
	dp[sy][sx][0] = 1;
	int find = 0;
	while (!q.empty()) {
		tuple<int, int, int> out = q.front();
		q.pop();
		int y = get<0>(out);
		int x = get<1>(out);
		int chance = get<2>(out);

		if (y == H - 1 && x == W - 1) {
			find = 1;
			cout << dp[y][x][chance] << "\n";
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			bool check = (ny >= 0 && ny < H && nx >= 0 && nx < W);
			
			if (check && dp[ny][nx][chance] == -1) {
				if (map[ny][nx] == 0) {
					dp[ny][nx][chance] = dp[y][x][chance] + 1;
					q.push(make_tuple(ny, nx, chance));

				}
				else if (map[ny][nx] == 1 && chance == 0) {
					dp[ny][nx][1] = dp[y][x][chance] + 1;
					q.push(make_tuple(ny, nx, 1));
				}
			}
		}
	}
	if (find == 0)
		cout << -1 << "\n";
}

int main() {
	cin >> H >> W;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			scanf("%1d", &map[y][x]);
		}
	}
	
	bfs(0, 0);
}