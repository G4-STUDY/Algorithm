#include <stack>
#include <iostream>
using namespace std;


int main(void) {
	stack<int> s;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string command;
		cin >> command;
		int input;
		if (command == "push") {
			cin >> input;
			s.push(input);
			continue;
		}
		if (command == "pop") {
			if (s.empty()) {
				cout << -1 << "\n";
				continue;
			}
			else {
				cout << s.top() << "\n";
			}
			s.pop();
			continue;
		}
		if (command == "size") {
			cout << s.size() << "\n";
			continue;
		}
		if (command == "empty") {
			cout << s.empty() << "\n";
			continue;
		}
		if (command == "top") {
			if (s.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << s.top() << "\n";
			}
			continue;
		}
	}
}
