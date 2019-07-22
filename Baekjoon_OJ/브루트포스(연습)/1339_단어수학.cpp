#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string str[10];
vector<char> alpha;
vector<int> num;
vector<int> str_alpha_index[10];

int calculate() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int local_sum = 0;
		for (int j = 0; j < str_alpha_index[i].size(); j++) {
			local_sum = local_sum * 10 + num[str_alpha_index[i][j]];
		}
		sum += local_sum;
	}
	return sum;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) { 
		cin >> str[i];
		for (int j = 0; j < str[i].size(); j++)	alpha.push_back(str[i][j]);
	}
	sort(alpha.begin(), alpha.end());
	alpha.erase(unique(alpha.begin(), alpha.end()), alpha.end());
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < str[i].size(); j++) {
			for (int k = 0; k < alpha.size(); k++) {
				if (str[i][j] == alpha[k]) {
					str_alpha_index[i].push_back(k);
					break;
				}
			}
		}
	}

	for (int i = 0; i < alpha.size(); i++) {
		num.push_back(9 - i);
	}
	int ans = -1;
	int i = 0;
	do {
		i++;
		int result = calculate();
		ans = max(ans, result);
	} while (prev_permutation(num.begin(), num.end()));
	cout << ans;
}