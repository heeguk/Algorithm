#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[9];
bool check[9];
int num[9];

vector<int> vec;
vector<int> use;

vector<int> unique(int arr[9]) {
	vector<int> v;
	v.push_back(arr[0]);
	int before = arr[0];
	
	for (int i = 1; i < N; i++) {
		if (before != arr[i])
			v.push_back(arr[i]);
		before = arr[i];
	}
	return v;
}

void solve(int index, int cnt, int start) {
	// M elements are selected
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << vec[num[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	if (index >= N)
		return;

	for (int i = start; i < vec.size(); i++) {
		//if (use[i] == 0)	continue;
		num[cnt] = i;
		//use[i]--;
		solve(index + 1, cnt + 1, i);
		num[cnt] = 0;
		//use[i]++;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	vec = unique(arr);
	for(int i = 0; i < vec.size(); i++){
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (vec[i] == arr[j])	cnt++;
		}
		use.push_back(cnt);
	}
	//N = vec.size();
	solve(0, 0, 0);

}