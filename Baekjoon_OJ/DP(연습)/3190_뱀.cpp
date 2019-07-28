#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

int map[100][100];
int N, K, L;
int command[10001];
int dy[4] = { 0, 1, 0, -1};
int dx[4] = { 1, 0, -1, 0 };
deque<pair<int, int>> body;
bool check[100][100];	// 뱀의 몸이 존재하는 공간을 1로 표시
// 왼쪽 이동: (index + 3) % 4, 오른쪽 이동: (index + 1) % 4

int main() {
	memset(check, 0, sizeof(check));
	memset(map, 0, sizeof(map));
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;
		map[y - 1][x - 1] = 1; // 사과가 존재
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int num;
		char c;
		cin >> num >> c;
		if (c == 'L') {	// 왼쪽
			command[num] = 1;
		}
		else {	// 오른쪽
			command[num] = 2;
		}
	}

	body.push_front(make_pair(0, 0));
	check[0][0] = 1;
	int time = 0;
	int dir = 0;
	while (1) {
		time++;
		auto out = body.front();
		int y = out.first, x = out.second;
		int ny = y + dy[dir], nx = x + dx[dir];

		//게임이 끝나는 경우
		bool map_out = ny >= N || ny < 0 || nx >= N || nx < 0;
		if (map_out || check[ny][nx] == 1) {
			cout << time;
			break;
		}
		
		// 게임이 끝나지 않는 경우, 다음 칸으로 이동
		body.push_front(make_pair(ny, nx));
		check[ny][nx] = 1;

		if (map[ny][nx] == 1) {	// 사과를 먹는 경우
			map[ny][nx] = 0;
		}
		else {	// 사과를 먹지 않는 경우
			auto out2 = body.back();
			body.pop_back();
			check[out2.first][out2.second] = 0;
		}

		// 방향을 바꾸는 경우
		if (command[time] == 1) {
			dir = (dir + 3) % 4;
		}
		else if (command[time] == 2) {
			dir = (dir + 1) % 4;
		}
		//cout << ny << " " << nx << endl;
	}

}