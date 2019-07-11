#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int m, n;
int map[1000][1000];
deque<pair<int, int>> tomato;
int tomato_num = 0;
int total;

int main() {
	cin >> m >> n;

	total = m * n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				tomato.push_back(make_pair(i, j));
				tomato_num++;
			}
			if (map[i][j] == -1)
				total--;
		}
	}


	int count = 0;
	while (1) {
		if (tomato_num == total) {
			printf("%d\n", count);
			break;
		}

		int change = 0;
		int size = tomato.size();
		int before = tomato_num;
		count++;

		for (int i = 0; i < size; i++) {
			pair<int, int> t = tomato.front();
			tomato.pop_front();
			int X = t.second;
			int Y = t.first;

			if (Y + 1 < n && map[Y + 1][X] == 0) {
				tomato.push_back(make_pair(Y + 1, X));
				map[Y + 1][X] = 1;
				tomato_num++;
			}
			if (X + 1 < m && map[Y][X + 1] == 0) {
				tomato.push_back(make_pair(Y, X + 1));
				map[Y][X + 1] = 1;
				tomato_num++;
			}
			if (Y - 1 >= 0 && map[Y - 1][X] == 0) {
				tomato.push_back(make_pair(Y - 1, X));
				map[Y - 1][X] = 1;
				tomato_num++;
			}
			if (X - 1 >= 0 && map[Y][X - 1] == 0) {
				tomato.push_back(make_pair(Y, X - 1));
				map[Y][X - 1] = 1;
				tomato_num++;
			}
			
		}

		

		if (before == tomato_num){
			printf("%d\n", -1);
			break;
		}

		
		
	}



	return 0;
}