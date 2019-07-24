#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

int main() {
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		char map[102][102];
		bool check[102][102];
		bool key[26];

		int R, C;
		cin >> R >> C;
		string keys;
		queue<pair<int, int>> key_q[26];
		
		memset(key, 0, sizeof(key));
		memset(check, 0, sizeof(check));
	
		// Map Initialization
		for (int i = 0; i < R + 2; i++) {
			for (int j = 0; j < C + 2; j++) {
				map[i][j] = '.';
			}
		}
		for (int i = 1; i < R + 1; i++) {
			for (int j = 1; j < C + 1; j++) {
				cin >> map[i][j];
			}
		}
		cin >> keys;
		if (keys[0] != '0') {
			for (int i = 0; i < keys.size(); i++) {
				key[keys[i] - 'a'] = true;
			}
		}
		
		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		check[0][0] = 1;
		int document = 0;

		while (!q.empty()) {
			auto out = q.front();
			q.pop();
			int y = out.first, x = out.second;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i], nx = x + dx[i];
				if (ny >= R + 2 || ny < 0 || nx >= C + 2 || nx < 0)	continue;
				if (map[ny][nx] == '*')	continue;

				if (map[ny][nx] == '.' && !check[ny][nx]) {
					check[ny][nx] = 1;
					q.push(make_pair(ny, nx));
				}
				else if (map[ny][nx] >= 'A' && map[ny][nx] <= 'Z') {
					int key_index = map[ny][nx] - 'A';
					if (key[key_index]) {
						map[ny][nx] = '.';
						check[ny][nx] = 1;
						q.push(make_pair(ny, nx));
					}
					else {
						key_q[key_index].push(make_pair(ny, nx));
					}
				}
				else if (map[ny][nx] >= 'a' && map[ny][nx] <= 'z') {
					int key_index = map[ny][nx] - 'a';
					key[key_index] = 1;
					map[ny][nx] = '.';
					check[ny][nx] = 1;
					q.push(make_pair(ny, nx));
					while (!key_q[key_index].empty()) {
						auto k_out = key_q[key_index].front();
						check[k_out.first][k_out.second] = 1;
						map[k_out.first][k_out.second] = '.';
						q.push(k_out);
						key_q[key_index].pop();
					}
				}
				else if (map[ny][nx] == '$') {
					document++;
					map[ny][nx] = '.';
					check[ny][nx] = 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
		/*
		for (int i = 0; i < R + 2; i++) {
			for (int j = 0; j < C + 2; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		*/
		cout << document << "\n";
	}
}