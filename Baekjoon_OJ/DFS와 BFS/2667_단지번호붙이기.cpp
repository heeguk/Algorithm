#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int city[25][25];
int arr[625] = {0};
int group = 0;
int num;

void dfs(int y, int x) {
	// already infected
	if (city[y][x] == 0)
		return;

	city[y][x] = 0;
	arr[group]++;

	if (y + 1 < num && city[y + 1][x] == 1) {
		dfs(y + 1, x);
	}
	if (y - 1 >= 0 && city[y - 1][x] == 1) {
		dfs(y - 1, x);
	}
	if (x + 1 < num && city[y][x + 1] == 1) {
		dfs(y, x + 1);
	}
	if (x - 1 >= 0 && city[y][x - 1] == 1) {
		dfs(y, x - 1);
	}

}

int main() {
	cin >> num;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			scanf("%1d", &city[i][j]);
		}
	}
	

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (city[i][j] == 1) {
				group++;
				dfs(i, j);
			}
		}
	}
	sort(arr + 1, arr + group + 1);
	printf("%d\n", group);
	for (int i = 1; i <= group; i++) {
		printf("%d\n", arr[i]);
	}

}