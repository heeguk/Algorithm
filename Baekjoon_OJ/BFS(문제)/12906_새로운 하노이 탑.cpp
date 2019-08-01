#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

class node {
public:
	string str[3];

	node(string a, string b, string c) {
		str[0] = a, str[1] = b, str[2] = c;
	}

	string get_sum() {
		return str[0] +" "+str[1] +" " + str[2];
	}

	bool is_ok() {
		char c[3] = {'A', 'B', 'C'};
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < str[i].size(); j++) {
				if (c[i] != str[i][j])	return false;
			}
		}
		return true;
	}
};

int main() {
	map<string, int> check;
	string str[3];
	for (int i = 0; i < 3; i++) {
		int n;
		cin >> n;
		if (n == 0) {
			str[i] = "";
		}
		else {
			cin >> str[i];
		}
	}

	node start(str[0], str[1], str[2]);
	queue<node> q;
	check[start.get_sum()] = 0;
	q.push(start);
	
	while (!q.empty()) {
		node out = q.front();
		q.pop();
		string index = out.get_sum();
		if (out.is_ok()) {
			cout << check[index] << endl;
			break;
		}
		//cout << index<<" "<<check[index] << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				// i에서 j번째 막대로 원판을 보낸다.
				string str[3];
				if (i == j)	continue;
				if (out.str[i].size() == 0)	continue;
				str[0] = out.str[0], str[1] = out.str[1], str[2] = out.str[2];
				str[j].push_back(str[i].back());
				str[i].pop_back();
				if (check.count(str[0] + " " + str[1] + " " + str[2]) == 0) {
					check[str[0] + " " + str[1] + " " + str[2]] = check[index] + 1;
					q.push(node(str[0], str[1], str[2]));
				}
			}
		}
	}
}