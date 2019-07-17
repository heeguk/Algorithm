#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int map[1000][1000];
int H, W;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int sy, int sx) {
	
}


int main() {
	cin >> W >> H;
	queue<pair<int, int>> q;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin>>map[y][x];
			if(map[y][x] == 1){
				q.push(make_pair(y, x));
			}
		}
	}


	while (!q.empty()) {
		pair<int, int> out = q.front();
		q.pop();
		int y = out.first;
		int x = out.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < W && ny >= 0 && ny < H && map[ny][nx] == 0) {
				map[ny][nx] = map[y][x] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
	int wrong = 0;
	int result = 0;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (map[y][x] == 0){
				wrong = 1;
				break;
			}
			result = max(result, map[y][x]);
		}
	}
	if (wrong)
		cout << -1 << "\n";
	else
		cout << result - 1 << "\n";

}