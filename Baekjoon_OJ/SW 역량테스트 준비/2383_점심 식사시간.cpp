#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int N;
int map[10][10];
vector<pair<int, int>> vec;
vector<int> use;
vector<pair<int, int>> stair;
int ans;

void solve() {
	deque<int> w1, w2, q1, q2;
	
	for (int i = 0; i < use.size(); i++) {
		pair<int, int> out = vec[i];
		int y = out.first, x = out.second;
		if (use[i] == 0) {
			w1.push_back(abs(y - stair[0].first) + abs(x - stair[0].second));
		}
		else {
			w2.push_back(abs(y - stair[1].first) + abs(x - stair[1].second));
		}
	}
	sort(w1.begin(), w1.end());
	sort(w2.begin(), w2.end());

	int time = 0;
	
	while (!(w1.empty() && w2.empty() && q1.empty() && q2.empty())) {
		time++;
		// cout << time << endl;
		if (!q1.empty()) {
			int iter = q1.size();
			for (int i = 0; i < iter; i++) {
				int out = q1.front();
				q1.pop_front();
				if (out - 1 > 0) {
					q1.push_back(out - 1);
				}
			}
		}

		if (!q2.empty()) {
			int iter = q2.size();
			for (int i = 0; i < iter; i++) {
				int out = q2.front();
				q2.pop_front();
				if (out - 1 > 0) {
					q2.push_back(out - 1);
				}
			}
		}
		
		if (!w1.empty()) {
			int iter = w1.size();
			for (int i = 0; i < iter; i++) {
				int out = w1.front();
				w1.pop_front();
				if (out == 0) {
					if (q1.size() < 3) {
						q1.push_back(map[stair[0].first][stair[0].second]);
					}
					else {
						w1.push_back(0);
					}
				}
				else {
					w1.push_back(out - 1);
				}
			}
		}
		if (!w2.empty()) {
			int iter = w2.size();
			for (int i = 0; i < iter; i++) {
				int out = w2.front();
				w2.pop_front();
				if (out == 0) {
					if (q2.size() < 3) {
						q2.push_back(map[stair[1].first][stair[1].second]);
					}
					else {
						w2.push_back(0);
					}
				}
				else {
					w2.push_back(out - 1);
				}
			}
		}
	}

	ans = min(ans, time);
}

void go(int index) {
	if (index == vec.size()) {
		solve();
		return;
	}
	// 1번째 계단을 이용
	use.push_back(0);
	go(index + 1);
	use.pop_back();
	// 2번째 계단을 이용
	use.push_back(1);
	go(index + 1);
	use.pop_back();
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		scanf("%d", &N);
		ans = 99999999;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1)	vec.push_back(make_pair(i, j));
				else if (map[i][j] > 1)	stair.push_back(make_pair(i, j));
			}
		}

		go(0);
		
		printf("#%d %d\n", t + 1, ans);

		vec.clear();
		use.clear();
		stair.clear();
	}
}