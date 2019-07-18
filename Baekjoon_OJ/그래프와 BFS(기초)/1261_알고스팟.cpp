#include <iostream>
#include <cstring>
#include <queue>

int map[100][100];
int dp[100][100];

using namespace std;

int W, H;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


void bfs(int sy, int sx) {
	memset(dp, -1, sizeof(dp));
	deque<pair<int, int>> q;
	q.push_front(make_pair(sy, sx));
	dp[sy][sx] = 0;

	while (!q.empty()) {
		pair<int, int> out = q.front();
		q.pop_front();
		int y = out.first;
		int x = out.second;

		if (y == H - 1 && x == W - 1) {
			cout << dp[y][x] << "\n";
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			bool check = (ny >= 0 && ny < H && nx >= 0 && nx < W);
			
			if (check && dp[ny][nx] == -1) {
				if(map[ny][nx] == 0){
					dp[ny][nx] = dp[y][x];
					q.push_front(make_pair(ny, nx));
				}
				else{
					dp[ny][nx] = dp[y][x] + 1;
					q.push_back(make_pair(ny, nx));
				}
			}
		}
	}
}

int main() {
	cin >> W >> H;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			scanf("%1d", &map[y][x]);
		}
	}
	
	bfs(0, 0);
}