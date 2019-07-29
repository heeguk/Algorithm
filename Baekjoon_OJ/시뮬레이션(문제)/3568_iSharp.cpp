#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int main() {
	string v_type;
	cin >> v_type;
	while (1) {
		string str;
		cin >> str;
		bool out = str[str.size() - 1] == ';';

		vector<char> v_name;
		stack<char> sub_type;
		for (int i = 0; i < str.size() - 1; i++) {	// 마지막은 항상 ; or , 이므로 제외
			// 변수 명
			if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
				v_name.push_back(str[i]);
			}
			// 변수 자료형
			if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z')) {
				if (str[i] == '[') {
					if (str[i + 1] == ']') {
						sub_type.push(str[i + 1]);
						sub_type.push(str[i]);
						i++;
					}
				}
				else {
					sub_type.push(str[i]);
				}
			}
		}

		cout << v_type;
		while (!sub_type.empty()) {
			char c = sub_type.top();
			sub_type.pop();
			cout << c;
		}
		cout << " ";
		for (int i = 0; i < v_name.size(); i++) {
			cout << v_name[i];
		}
		cout << ";\n";
		if (out)
			break;
	}
}