#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

class node {
public:
	int x;
	int y;
	int h;

	node(int H, int Y, int X) {
		h = H;
		y = Y;
		x = X;
	}
};

int m, n, h;
int tomato_num = 0;
int total;
int map[100][100][100];
deque<node> tomato;


int main() {
	cin >> m >> n >> h;
	
	

	total = m * n * h;

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[k][i][j];
				if (map[k][i][j] == 1) {
					tomato.push_back(node(k, i, j));
					tomato_num++;
				}
				if (map[k][i][j] == -1)
					total--;
			}
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
			node t = tomato.front();
			tomato.pop_front();
			int X = t.x;
			int Y = t.y;
			int H = t.h;

			if (Y + 1 < n && map[H][Y + 1][X] == 0) {
				tomato.push_back(node(H, Y + 1, X));
				map[H][Y + 1][X] = 1;
				tomato_num++;
			}
			if (X + 1 < m && map[H][Y][X + 1] == 0) {
				tomato.push_back(node(H, Y, X + 1));
				map[H][Y][X + 1] = 1;
				tomato_num++;
			}
			if (Y - 1 >= 0 && map[H][Y - 1][X] == 0) {
				tomato.push_back(node(H, Y - 1, X));
				map[H][Y - 1][X] = 1;
				tomato_num++;
			}
			if (X - 1 >= 0 && map[H][Y][X - 1] == 0) {
				tomato.push_back(node(H, Y, X - 1));
				map[H][Y][X - 1] = 1;
				tomato_num++;
			}
			if (H + 1 < h && map[H + 1][Y][X] == 0) {
				tomato.push_back(node(H + 1, Y, X));
				map[H + 1][Y][X] = 1;
				tomato_num++;
			}
			if (H - 1 >= 0 && map[H - 1][Y][X] == 0) {
				tomato.push_back(node(H - 1, Y, X));
				map[H - 1][Y][X] = 1;
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