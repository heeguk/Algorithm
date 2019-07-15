#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	vector<int> vec;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int in;
		cin >> in;
		vec.push_back(in);
	}

	if (prev_permutation(vec.begin(), vec.end())) {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << ' ';
		}
	}
	else {
		cout << -1;
	}

}