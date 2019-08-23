#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int map[20][20];
bool use[201];

int dx[4] = { 1, -1, -1, 1 };
int dy[4] = { 1, 1, -1, -1 };

int solve(int y, int x, int right, int left) {
	
	for (int i = 0; i < right; i++) {
		y += dy[0], x += dx[0];
		if (use[map[y][x]])	return -1;
		use[map[y][x]] = 1;
	}
	for (int i = 0; i < left; i++) {
		y += dy[1], x += dx[1];
		if (use[map[y][x]])	return -1;
		use[map[y][x]] = 1;
	}
	for (int i = 0; i < right; i++) {
		y += dy[2], x += dx[2];
		if (use[map[y][x]])	return -1;
		use[map[y][x]] = 1;
	}
	for (int i = 0; i < left; i++) {
		y += dy[3], x += dx[3];
		if (use[map[y][x]])	return -1;
		use[map[y][x]] = 1;
	}

	return 1;
}

int main() {
	int tc;
	scanf("%d", &tc);
	
	for (int t = 0; t < tc; t++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		
		int ans = -1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int left = j;
				int right = N - j - 1;
				
				for (int r = 1; r <= right; r++) {
					for(int l = 1; l <= left; l++) {
						if (l + r + i >= N)	break;
						memset(use, 0, sizeof(use));
						int result = solve(i, j, r, l);
						if (result == 1) {
							ans = max(ans, r * 2 + l * 2);
						}
					}
				}

			}
		}

		printf("#%d %d\n", t + 1, ans);
	}
}