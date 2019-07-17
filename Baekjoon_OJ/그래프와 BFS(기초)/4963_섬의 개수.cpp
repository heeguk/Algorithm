#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

bool check[50][50];
int map[50][50];
int W, H;
int dx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, 1, -1, 1, -1, -1, 1 };
int flag_num;

void dfs(int y, int x) {
	check[y][x] = true;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < W && ny >= 0 && ny < H && !check[ny][nx] && map[ny][nx] == 1)
			dfs(ny, nx);
	}
	
}


int main() {
	
	while (1) {
		cin >> W >> H;
		if (W == 0 && H == 0)
			break;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}

		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				// 땅이 없는 곳이거나, 이미 방문한 땅인 경우
				if (!map[y][x] || check[y][x])	continue;
				dfs(y, x);
				flag_num++;
			}
		}
		cout << flag_num << '\n';

		memset(check, 0, sizeof(check));
		memset(map, 0, sizeof(map));
		flag_num = 0;
	}

	

}