#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int map[20][20];
bool check[20][20];
int N, M;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int MAX = 0;

int get_cost(int n) {
	return (n * n) + (n - 1) * (n - 1);
}


int solve(int y, int x) {
	int ans = 0;
	for (int n = 1; ; n++) {
		if (get_cost(n) >  MAX * M)	break;
		int house = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (abs(y - i) + abs(x - j) < n && map[i][j] == 1)	house++;
			}
		}

		int propit = house * M - get_cost(n);
		if (propit >= 0) {
			ans = house;
		}
		
	}
	return ans;
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		MAX = 0;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1)	MAX++;
			}
		}

		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int ret = solve(i, j);
				ans = max(ans, ret);
			}
		}

		printf("#%d %d\n", t + 1, ans);
	}
}