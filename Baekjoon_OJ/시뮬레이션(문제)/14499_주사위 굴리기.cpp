#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int map[21][21];
int dir[1000];

int dice[6];

int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

void move_dice(int d) {
	if (d == 1) {	// 동쪽, 1, 4 그대로
		int temp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = temp;
	}
	else if (d == 2) {	// 서쪽, 1, 4 그대로
		int temp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = temp;
		
	}
	else if (d == 3) {	// 북쪽, 2, 3 그대로
		int temp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = temp;
	}
	else if (d == 4) {
		int temp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = temp;

	}
}

int main() {
	int N, M, x, y, K;
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < K; i++)	cin >> dir[i];
	for (int i = 0; i < K; i++) {
		int direction = dir[i];
		int ny = y + dy[direction], nx = x + dx[direction];
		
		if (ny >= M || ny < 0 || nx >= N || nx < 0)	continue;

		y = ny, x = nx;
		// 윗면은 0 인덱스, 아랫면은 5 인덱스
		move_dice(direction);
		if (map[nx][ny] == 0) {
			map[nx][ny] = dice[5];
		}
		else {
			dice[5] = map[nx][ny];
			map[nx][ny] = 0;
		}
		printf("%d\n", dice[0]);
	}
	
}