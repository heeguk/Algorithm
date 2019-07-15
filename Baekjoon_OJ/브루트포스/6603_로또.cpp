#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	while (1) {
		vector<int> vec;
		vector<int> lotto;
		int n;
		cin >> n;
		if (n == 0)
			break;

		for (int i = 0; i < n; i++) {
			if(i < 6)	vec.push_back(0);
			else vec.push_back(1);

			int in;
			cin >> in;
			lotto.push_back(in);
		}

		do {
			for (int i = 0; i < vec.size(); i++) {
				if (!vec[i])	cout << lotto[i] << ' ';
			}
			cout << '\n';
		} while (next_permutation(vec.begin(), vec.end()));
		cout << '\n';
	}
}
	