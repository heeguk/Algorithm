#include <iostream>
#include <string>
using namespace std;

char c[23][130];

void number(int n, int s, int start, int end) {
	if (n == 2 || n == 3 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9 || n == 0) {
		for (int i = start + 1; i < start + 1 + s; i++) {
			c[0][i] = '-';
		}
	}
	if (n == 2 || n == 3 || n == 5 || n == 6 || n == 4 || n == 8 || n == 9) {
		for (int i = start + 1; i < start + 1 + s; i++) {
			c[s + 1][i] = '-';
		}
	}
	if (n == 2 || n == 3 || n == 5 || n == 6 || n == 8 || n == 9 || n == 0) {
		for (int i = start + 1; i < start + 1 + s; i++) {
			c[2 * s + 3 - 1][i] = '-';
		}
	}
	if (n == 1 || n == 3 || n == 4 || n == 7 || n == 8 || n == 9 || n == 0) {
		for (int i = 1; i < 1 + s; i++) {
			c[i][end - 1] = '|';
		}
		for (int i = s + 2; i < 2 * s + 2; i++) {
			c[i][end - 1] = '|';
		}
	}
	if (n == 2) {
		for (int i = 1; i < 1 + s; i++) {
			c[i][end - 1] = '|';
		}
	}
	if (n == 5 || n == 6) {
		for (int i = s + 2; i < 2 * s + 2; i++) {
			c[i][end - 1] = '|';
		}
	}
	if (n == 6 || n == 8 || n == 0) {
		for (int i = 1; i < 1 + s; i++) {
			c[i][start] = '|';
		}
		for (int i = s + 2; i < 2 * s + 2; i++) {
			c[i][start] = '|';
		}
	}
	if (n == 2) {
		for (int i = s + 2; i < 2 * s + 2; i++) {
			c[i][start] = '|';
		}
	}

	if (n == 4 || n == 5|| n == 9) {
		for (int i = 1; i < 1 + s; i++) {
			c[i][start] = '|';
		}
	}

	
}

int main() {
	for (int i = 0; i < 23; i++) {
		for (int j = 0; j < 130; j++) {
			c[i][j] = ' ';
		}
	}
	int s;
	string str;
	cin >> s >> str;
	int start, end;
	for (int i = 0; i < str.size(); i++) {
		start = (s + 2) * i + i;
		end = (s + 2) * (i + 1) + i;
		number(str[i] - '0', s, start, end);
	}
	for (int i = 0; i < 2 * s + 3; i++) {
		for (int j = 0; j < (s + 2) * str.size() + str.size() - 1; j++) {
			printf("%c", c[i][j]);
		}
		printf("\n");
	}
}