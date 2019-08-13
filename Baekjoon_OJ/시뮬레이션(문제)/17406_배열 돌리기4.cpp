#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class node {
public:
	int y;
	int x;
	int l;

	node(int a, int b, int c) {
		y = a, x = b, l = c;
	}
};

int N, M, K;
int cmap[50][50];
vector<node> vec;
vector<int> permu;

int get_min(int map[50][50]) {
	int ret = 50 * 100 + 1;
	for (int i = 0; i < N; i++) {
		int local = 0;
		for (int j = 0; j < M; j++) {
			local += map[i][j];
		}
		ret = min(ret, local);
	}
	return ret;
}

int solve() {
	int map[50][50];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = cmap[i][j];
		}
	}
	
	for (int k = 0; k < permu.size(); k++) {
		int index = permu[k];
		int Y = vec[index].y, X = vec[index].x, L = vec[index].l;
		for (int l = 1; l <= L; l++) {
			int temp = map[Y - l][X - l];
			for (int x = X - l; x < X + l; x++) {
				int temp2 = map[Y - l][x + 1];
				map[Y - l][x + 1] = temp;
				temp = temp2;
			}

			for (int y = Y - l; y < Y + l; y++) {
				int temp2 = map[y + 1][X + l];
				map[y + 1][X + l] = temp;
				temp = temp2;
			}

			for (int x = X + l; x > X - l; x--) {
				int temp2 = map[Y + l][x - 1];
				map[Y + l][x - 1] = temp;
				temp = temp2;
			}

			for (int y = Y + l; y > Y - l; y--) {
				int temp2 = map[y - 1][X - l];
				map[y - 1][X - l] = temp;
				temp = temp2;
			}
		}
	}
	int ret = get_min(map);
	
	return ret;
}

int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> cmap[i][j];
		}
	}
	
	
	for (int i = 0; i < K; i++) {
		int y, x, k;
		cin >> y >> x >> k;
		vec.push_back(node(y - 1, x - 1, k));
		permu.push_back(i);
	}
	int ans = 50 * 100 + 1;
	do {
		ans = min(ans, solve());
	} while (next_permutation(permu.begin(), permu.end()));
	cout << ans;
}