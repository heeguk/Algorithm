#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int main() {
	int W, H;
	char map[100][100];
	int dp[100][100];
	memset(dp, -1, sizeof(dp));
	vector<pair<int, int>> C;
	queue<pair<int, int>> q;
	cin >> W >> H;
	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C') {
				C.push_back(make_pair(i, j));
			}
		}
	}
	
	
	auto start = C[0];
	auto target = C[1];
	dp[start.first][start.second] = 0;
	q.push(start);
	while (!q.empty()) {
		auto out = q.front();
		q.pop();
		if (out.first == target.first && out.second == target.second) {
			cout << dp[target.first][target.second] - 1<<"\n";
			break;
		}
		for (int i = 0; i < 4; i++) {
			int y = out.first, x = out.second;
			while (1) {
				y = y + dy[i], x = x + dx[i];
				if (y >= H || y < 0 || x >= W || x < 0)	break;
				if (map[y][x] == '*')	break;
				if (dp[y][x] == -1) {
					dp[y][x] = dp[out.first][out.second] + 1;
					q.push(make_pair(y, x));
				}
			}
		}
	}
	
}