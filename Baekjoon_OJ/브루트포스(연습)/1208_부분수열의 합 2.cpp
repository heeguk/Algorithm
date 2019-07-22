#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, S;

vector<int> first, second;
vector<int> first_vec, second_vec;

void make_vec(int index, int sum, vector<int>& vec, vector<int>& result_vec) {
	if (index == vec.size()) {
		result_vec.push_back(sum);
		return;
	}

	make_vec(index + 1, sum, vec, result_vec);
	make_vec(index + 1, sum + vec[index], vec, result_vec);

}

long long int get_left_same(int index, vector<int>& vec) {
	long long int same = 1;
	int n = vec[index];
	for (int i = index + 1; i < vec.size(); i++) {
		if (n == vec[i])	same++;
		else break;
	}
	return same;
}
long long int get_right_same(int index, vector<int>& vec) {
	long long int same = 1;
	int n = vec[index];
	for (int i = index - 1; i >= 0; i--) {
		if (n == vec[i])	same++;
		else break;
	}
	return same;
}

int main() {
	cin >> N >> S;

	// N이 1인 경우 예외 처리
	if (N == 1) {
		int n;
		cin >> n;
		if (n == S)
			cout << 1;
		else
			cout << 0;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (i < N / 2)	first.push_back(n);
		else second.push_back(n);
	}

	make_vec(0, 0, first, first_vec);
	make_vec(0, 0, second, second_vec);
	sort(first_vec.begin(), first_vec.end());
	sort(second_vec.begin(), second_vec.end());

	long long int ans = 0;
	long long int left = 0;
	long long int right = second_vec.size() - 1;
	long long int sum = first_vec[left] + second_vec[right];
	while (1) {
		if (sum == S) {
			//cout << left << " " << right << endl;
			long long int left_same = get_left_same(left, first_vec);
			long long int right_same = get_right_same(right, second_vec);
			//cout << left_same << " " << right_same << endl;
			ans += left_same * right_same;
			if (left + left_same >= first_vec.size() || right - right_same < 0)
				break;
			left += left_same;
			right -= right_same;
			sum = first_vec[left] + second_vec[right];
		}
		else if (sum > S) {
			if (right - 1 < 0)
				break;
			right--;
			sum = first_vec[left] + second_vec[right];
		}
		else if (sum < S) {
			if (left + 1 >= first_vec.size())
				break;
			left++;
			sum = first_vec[left] + second_vec[right];
		}
	}
	// S = 0 인경우 아무것도 선택하지 않은 경우가 정답에 포함된다.
	if (S == 0)
		ans--;
	cout << ans;
}