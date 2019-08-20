#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


class node {
public:
	int x;
	int y;
	int c;
	int p;

	node(int Y, int X, int C, int P) {
		y = Y, x = X, c = C, p = P;
	}
};

int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, -1, 0, 1, 0};

vector<int> A;
vector<int> B;
vector<node> BC;

int solve() {
	int ay, ax;
	int by, bx;
	ay = 0, ax = 0;
	by = 9, bx = 9;

	bool bc[8][2];

	int score_a = 0;
	int score_b = 0;

	for (int i = 0; i < A.size(); i++) {
		ay += dy[A[i]], ax += dx[A[i]];
		by += dy[B[i]], bx += dx[B[i]];
		
		for (int j = 0; j < BC.size(); j++) {
			node out = BC[j];
			bc[j][0] = 0, bc[j][1] = 0;
			int y = out.y, x = out.x, c = out.c, p = out.p;
			if (abs(y - ay) + abs(x - ax) <= c) {
				bc[j][0] = 1;
			}
			if (abs(y - by) + abs(x - bx) <= c) {
				bc[j][1] = 1;
			}
		}
		
		int a = 0, b = 0;
		for (int j = 0; j < BC.size(); j++) {
			for (int k = 0; k < BC.size(); k++) {
				int temp_a = BC[j].p * bc[j][0];
				int temp_b = BC[k].p * bc[k][1];
				if (j == k && bc[j][0] == 1 && bc[k][1] == 1) {
					temp_a /= 2;
					temp_b /= 2;
				}
				if (a + b < temp_a + temp_b) {
					a = temp_a;
					b = temp_b;
				}

			}
			
		}
		score_a += a;
		score_b += b;
	}
	return score_a + score_b;
}


int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		int m, a;
		scanf("%d %d", &m, &a);

		A.push_back(0);
		for (int i = 0; i < m; i++) {
			int n;
			scanf("%d", &n);
			A.push_back(n);
		}
		B.push_back(0);
		for (int i = 0; i < m; i++) {
			int n;
			scanf("%d", &n);
			B.push_back(n);
		}
		for (int i = 0; i < a; i++) {
			int x, y, c, p;
			scanf("%d %d %d %d", &x, &y, &c, &p);
			BC.push_back(node(y - 1, x - 1, c, p));
		}

		int ans = solve();

		printf("#%d %d\n", t + 1, ans);

		BC.clear();
		A.clear();
		B.clear();
	}
}