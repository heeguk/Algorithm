#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	
	cin >> n;
	int num = 0;
	for (int i = 0; i < n; i++) {
		char op[20];
		int operand;
		scanf("%s", op);
		if (op[2] != 'l' && op[0] != 'e')	scanf("%d", &operand);
		
		if (op[2] == 'd') {
			num = num | (1 << operand);
		}
		else if (op[0] == 'c') {
			int result = num & (1 << operand);
			if (result == 0)
				printf("0\n");
			else
				printf("1\n");
		}
		else if (op[0] == 'r') {
			num = num & ~(1 << operand);
		}
		else if (op[0] == 't'){
			num = num ^ (1 << operand);
		}
		else if (op[2] == 'l') {
			num = (1 << 21) - 2;

		}
		else if (op[0] == 'e') {
			num = 0;
		}
	}
}