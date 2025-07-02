#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int N;

string s;
int arr[11];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
    for (int i = 0; i < s.length(); i++){
        arr[i] = s[i] - 48;
    }
    
    sort(arr, arr + s.length());

	for (int i = s.length() - 1; i >= 0; i--) {
		cout << arr[i];
	}
}
