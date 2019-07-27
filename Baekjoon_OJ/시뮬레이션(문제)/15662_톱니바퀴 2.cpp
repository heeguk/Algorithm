#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

deque<int> gear[1001];
vector<pair<int, int>> dir_vec;

void rotate(int gear_index, int dir) {
	if (dir == 1) {	// 시계 방향
		int last = gear[gear_index].back();
		gear[gear_index].pop_back();
		gear[gear_index].push_front(last);
	}
	else if (dir == -1) {	// 반시계 방향
		int first = gear[gear_index].front();
		gear[gear_index].pop_front();
		gear[gear_index].push_back(first);
	}
}

int main() {
	deque<int> a;
	int gear_num;
	cin >> gear_num;
	for (int i = 1; i <= gear_num; i++) {
		for (int j = 0; j < 8; j++) {
			// 0 : N, 1: S
			int a;
			scanf("%1d", &a);
			gear[i].push_back(a);
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		dir_vec.push_back(make_pair(a, b));
	}

	for (int i = 0; i < dir_vec.size(); i++) {
		queue<pair<int, int>> q;	// 해당 큐를 통해 회전시킬 톱니 바퀴를 찾아 rotate_arr에 체크
		q.push(dir_vec[i]);
		
		int rotate_arr[1001];
		memset(rotate_arr, 0, sizeof(rotate_arr));	// 0이면 회전 x
		rotate_arr[dir_vec[i].first] = dir_vec[i].second;
		
		while (!q.empty()) {
			auto out = q.front();
			q.pop();

			//회전
			int index = out.first;
			int dir = out.second;
			
			int counter_dir;
			if (dir == -1)
				counter_dir = 1;
			else
				counter_dir = -1;

			// 인접 톱니바퀴 검사
			if (index - 1 >= 1) {
				if (gear[index][6] != gear[index - 1][2] && rotate_arr[index-1] == 0) {
					q.push(make_pair(index - 1, counter_dir));
					rotate_arr[index - 1] = counter_dir;
				}
			}
			if (index + 1 <= gear_num) {
				if (gear[index][2] != gear[index + 1][6] && rotate_arr[index + 1] == 0) {
					q.push(make_pair(index + 1, counter_dir));
					rotate_arr[index + 1] = counter_dir;
				}
			}
		}

		for (int i = 1; i <= gear_num; i++) {
			if (rotate_arr[i] != 0)	rotate(i, rotate_arr[i]);
		}

	}
	int ans = 0;
	for (int i = 1; i <= gear_num; i++) {
		if (gear[i][0])	ans++;
	}
	cout << ans;
}
