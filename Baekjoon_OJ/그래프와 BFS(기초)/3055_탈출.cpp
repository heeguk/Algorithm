#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>

char map[50][50];
int dp[50][50];

using namespace std;

int W, H;
int Y, X;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<pair<int, int>> water;

void bfs(int sy, int sx) {
	memset(dp, -1, sizeof(dp));
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	dp[sy][sx] = 0;
	int find = 0;

	queue<pair<int, int>> w;
	for (int i = 0; i < water.size(); i++) {
		w.push(water[i]);
	}
	
	while (!q.empty() && !find) {
		int water_cell = w.size();
		// water spreads
		for (int k = 0; k < water_cell; k++) {
			pair<int, int> out = w.front();
			w.pop();
			int y = out.first;
			int x = out.second;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				bool check = (ny >= 0 && ny < H && nx >= 0 && nx < W);
				if (check && map[ny][nx] == '.') {
					map[ny][nx] = '*';
					w.push(make_pair(ny, nx));
				}
			}
		}

		int S = q.size();
		for (int k = 0; k < S; k++) {
			// S moves
			pair<int, int> out = q.front();
			q.pop();
			int y = out.first;
			int x = out.second;
			if (y == Y && x == X) {
				find = 1;
				cout << dp[y][x] << "\n";
				break;
			}

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				bool check = (ny >= 0 && ny < H && nx >= 0 && nx < W);

				if (check && dp[ny][nx] == -1) {
					if (map[ny][nx] == '.' || map[ny][nx] == 'D') {
						dp[ny][nx] = dp[y][x] + 1;
						q.push(make_pair(ny, nx));
					}
				}
			}
		}
	}
	if (find == 0)
		cout << "KAKTUS\n";
	
}

int main() {
	cin >> H >> W;
	int sy, sx;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> map[y][x];
			if (map[y][x] == '*') {
				water.push_back(make_pair(y, x));
			}
			else if (map[y][x] == 'S') {
				sy = y;
				sx = x;
				map[y][x] = '.';
			}
			else if (map[y][x] == 'D') {
				Y = y;
				X = x;
			}
		}
	}
	
	bfs(sy, sx);
}