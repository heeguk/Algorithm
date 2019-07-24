#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int N, K;
	int map[2][100000];
	int time[2][100000];
	cin >> N >> K;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	memset(time, -1, sizeof(time));
	time[0][0] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		auto out = q.front();
		q.pop();
		int col = out.first, row = out.second;
		
		if (row + 1 >= N || row + K >= N) {
			cout << 1 << "\n";
			return 0;
		}

		if (row + 1 < N && map[col][row + 1] == 1 && time[col][row + 1] == -1) {
			time[col][row + 1] = time[col][row] + 1;
			q.push(make_pair(col, row + 1));
		}
		if (row - 1 > time[col][row] && map[col][row - 1] == 1 && time[col][row - 1] == -1) {
			time[col][row - 1] = time[col][row] + 1;
			q.push(make_pair(col, row - 1));
		}
		if (row + K < N && map[(col + 1) % 2][row + K] == 1 && time[(col + 1) % 2][row + K] == -1) {
			time[(col + 1) % 2][row + K] = time[col][row] + 1;
			q.push(make_pair((col + 1) % 2, row + K));
		}
	}
	cout << 0 << "\n";
}