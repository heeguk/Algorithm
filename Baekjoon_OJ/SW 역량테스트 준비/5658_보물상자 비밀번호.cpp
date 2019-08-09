#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


int main() {
	int tc;
	scanf("%d\n", &tc);

	for (int t = 0; t < tc; t++) {
		int N, K;
		scanf("%d %d\n", &N, &K);
		int digit = N / 4;
		vector<int> vec;
		deque<int> q;
		map<int, bool> check;
		for (int i = 0; i < N; i++) {
			char n;
			scanf("%c", &n);
			//cin >> n;
			if (n >= 'A' && n <= 'F') {
				q.push_back(10 + n - 'A');
			}
			else {
				q.push_back(n - '0');
			}
		}
		for (int k = 0; k < digit; k++) {
			for (int i = 0; i < 4; i++) {
				int sum = 0;
				int index = i * digit;
				for (int d = 0; d < digit; d++) {
					sum = sum * 16 + q[index + d];
				}
				if (check.count(sum) == 0) {
					check[sum] = 1;
					vec.push_back(sum);
				}
			}
			int l = q.back();
			q.pop_back();
			q.push_front(l);
		}

		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		printf("#%d %d\n", t + 1, vec[K - 1]);
	}
}