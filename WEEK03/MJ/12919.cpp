#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int S_size, T_size;
string S_str;
string T_str;

int result = 0;

void A_B(int cnt) {
	if (result == 1) return;
	if (S_str == T_str) {
		result = 1;
		return;
	}
	if (cnt == S_size) return;

	if (T_str.back() == 'A') {
		T_str.pop_back();
		A_B(cnt - 1);
		T_str.push_back('A');
	}
	reverse(T_str.begin(), T_str.end());
	if (T_str.back() == 'B') {
		T_str.pop_back();
		A_B(cnt - 1);
		T_str.push_back('B');
	}
	reverse(T_str.begin(), T_str.end());
}

int main(void) {

	cin >> S_str >> T_str;
	S_size = S_str.size();
	T_size = T_str.size();

	A_B(T_size);
	cout << result;
	return 0;
}
