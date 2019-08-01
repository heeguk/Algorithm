#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int F, S, G, U, D;

int check[1000001];



int main() {
	memset(check, -1, sizeof(check));
	cin >> F >> S >> G >> U >> D;
	queue<int> q;
	q.push(S);
	check[S] = 0;
	bool find = 0;
	while (!q.empty()) {
		int start = q.front();
		q.pop();

		if (start == G) {
			find = 1;
			cout << check[start];
			break;
		}

		if (start + U <= F && check[start + U] == -1) {
			check[start + U] = check[start] + 1;
			q.push(start + U);
		}
		if (start - D >= 1 && check[start - D] == -1) {
			check[start - D] = check[start] + 1;
			q.push(start - D);
		}
		
	}
	if (!find)	cout << "use the stairs";
}