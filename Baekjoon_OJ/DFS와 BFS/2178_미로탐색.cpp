#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

//int maze[100][100];
//int check[100][100];
int n, m;

class point {
public:
	int x, y;
	int count;

	point(int Y, int X, int C) {
		x = X, y = Y, count = C;
	}
};


void bfs(int** maze, int** check) {
	deque<point> q;
	q.push_back(point(0, 0, 1));
	check[0][0] = 1;
	while (!q.empty()) {
		point next = q.front();
		q.pop_front();
		int Y = next.y;
		int X = next.x;
		int Count = next.count;

		if (X == m - 1 && Y == n - 1) {
			printf("%d\n", Count);
			return;
		}

		//down
		if (Y + 1 < n && maze[Y + 1][X] == 1 && check[Y + 1][X] == -1) {
			//cout << "down"<<endl;
			q.push_back(point(Y + 1, X, Count+1));
			check[Y+1][X] = 1;
		}
		//right
		if (X + 1 < m && maze[Y][X+1] == 1 && check[Y][X+1] == -1) {
			//cout << "right" << endl;
			q.push_back(point(Y, X + 1, Count + 1));
			check[Y][X + 1] = 1;
		}
		//up
		if (Y - 1 >= 0 && maze[Y - 1][X] == 1 && check[Y - 1][X] == -1) {
			//cout << "up" << endl;
			q.push_back(point(Y - 1, X, Count + 1));
			check[Y - 1][X] = 1;
		}
		//left
		if (X - 1 >= 0 && maze[Y][X - 1] == 1 && check[Y][X - 1] == -1) {
			//cout << "left" << endl;
			q.push_back(point(Y, X - 1, Count + 1));
			check[Y][X - 1] = 1;
		}
	}

}

int main() {
	
	
	cin >> n >> m;
	
	int count = 0;
	int** check = new int*[n];
	int** maze = new int*[n];
	for (int i = 0; i < n; i++){
		maze[i] = new int[m];
		check[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &maze[i][j]);
			check[i][j] = -1;
		}
	}
	bfs(maze, check);


	return 0;
}