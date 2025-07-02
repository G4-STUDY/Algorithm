#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define X first
#define Y second
int N;

pair <int, string> Arr[20002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Arr[i].Y;
		Arr[i].X = Arr[i].Y.length();
	}

	sort(Arr, Arr + N);


	for (int i = 0; i <= N; i++) {
        if (Arr[i].Y == Arr[i+1].Y) continue;
		cout << Arr[i].Y << '\n';
	}
}
