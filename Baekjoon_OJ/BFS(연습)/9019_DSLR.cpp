#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

void print(int start, int to, int from[10001], int how[10001]) {
	if (start != to) {
		print(start, from[to], from, how);
		if (how[to] == 0) {
			cout << "D";
		}
		else if (how[to] == 1) {
			cout << "S";
		}
		else if (how[to] == 2) {
			cout << "L";
		}
		else if (how[to] == 3) {
			cout << "R";
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int dp[10001];
		int how[10001];
		int from[10001];
		memset(dp, -1, sizeof(dp));
		memset(how, -1, sizeof(how));

		int A, B;
		cin >> A >> B;
		
		dp[A] = 0;
		from[A] = A;
		queue<int> q;
		q.push(A);

		while (!q.empty()) {
			int start = q.front();
			q.pop();

			if (start == B) {
				//cout << dp[B] << endl;
				print(A, B, from, how);
				cout << "\n";
				break;
			}
			
			for (int i = 0; i < 4; i++) {
				int to;
				if (i == 0) {
					to = (start * 2) % 10000;
				}
				else if (i == 1) {
					if (start == 0)	to = 9999;
					else to = start - 1;

				}
				else if (i == 2) {
					to = (start % 1000) * 10 + start / 1000;

				}
				else if (i == 3) {
					to = (start % 10) * 1000 + start / 10;
				}
				if (dp[to] == -1) {
					dp[to] = dp[start] + 1;
					how[to] = i;
					from[to] = start;
					q.push(to);
				}
				
			}
		}
		
	}
	
}