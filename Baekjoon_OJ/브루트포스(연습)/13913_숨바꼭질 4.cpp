#include <iostream>
#include <cstring>
#include <queue>

using namespace std;


int d[100001];
int from[100001];
int N, K;
void print(int start, int to) {
	if (start != to) {
		print(start, from[to]);
	}
	cout << to << " ";
}

int main() {
	memset(from, -1, sizeof(from));
	memset(d, -1, sizeof(d));
	cin >> N >> K;
	
	queue<int> q;
	q.push(N);
	d[N] = 0;
	from[N] = N;

	while (!q.empty()) {
		int start = q.front();
		q.pop();
		
		if (start == K) {
			cout << d[K] << "\n";
			print(N, K);
			break;
		}
		
		

		for (int i = 0; i < 3; i++) {
			int to;
			if (i == 0)	to = start - 1;
			else if (i == 1) to = start + 1;
			else if (i == 2) to = start * 2;
			
			if (to < 0 || to > 100000) continue;
			if (d[to] == -1) {
				d[to] = d[start] + 1;
				from[to] = start;
				q.push(to);
			}
		}
	}
}