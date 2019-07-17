#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

bool check[25][25];
int map[25][25];
int N;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int flag_num;

void dfs(int x, int y) {
	check[x][y] = true;
	flag_num++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N &&!check[nx][ny] && map[nx][ny] == 1)
			dfs(nx, ny);
	}
	
}


int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	vector<int> ans;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 집이 없는 곳이거나, 이미 방문한 집인 경우
			if (!map[i][j] || check[i][j])	continue;
			flag_num = 0;
			dfs(i, j);
			ans.push_back(flag_num);
		}
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)	cout << ans[i] << '\n';

}