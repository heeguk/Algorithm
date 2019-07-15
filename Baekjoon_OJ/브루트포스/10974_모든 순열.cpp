#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	vector<int> vec;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vec.push_back(i+1);
	}
	
	do {
		for (int i = 0; i < vec.size(); i++)	cout << vec[i] << ' ';
		cout << '\n';
	} while (next_permutation(vec.begin(), vec.end()));
}