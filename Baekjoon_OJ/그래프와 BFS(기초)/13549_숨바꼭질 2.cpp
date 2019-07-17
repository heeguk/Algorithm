#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int check[100001];
int A, B;

int main() {
	memset(check, 0, sizeof(check));
	cin >> A >> B;
	queue<int> q;
	check[A] = 1;
	q.push(A);

	while (!q.empty()) {
		int out = q.front();
		q.pop();
		if (out == B)
			break;
		// move 1: x - 1
		if (out - 1 >= 0) {
			if (check[out - 1] == 0) {
				check[out - 1] = check[out] + 1;
				q.push(out - 1);
			}
			else if (check[out] + 1 < check[out - 1]) {
				check[out - 1] = check[out] + 1;
				q.push(out - 1);
			}
		}
		// move 2: x + 1
		if (out + 1 < 100001) {
			if (check[out + 1] == 0) {
				check[out + 1] = check[out] + 1;
				q.push(out + 1);
			}
			else if (check[out] + 1 < check[out + 1]) {
				check[out + 1] = check[out] + 1;
				q.push(out + 1);
			}
		}
		// move 3: x * 2
		if (out * 2 < 100001) {
			if (check[out * 2] == 0) {
				check[out * 2] = check[out];
				q.push(out * 2);
			}
			else if (check[out] < check[out * 2]) {
				check[out * 2] = check[out];
				q.push(out * 2);
			}
		}
	}

	cout << check[B] - 1 << endl;
}