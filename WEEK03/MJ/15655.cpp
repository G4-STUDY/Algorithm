#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int N, M;
int arr[22];
int vis[22];
int numlist[22];
int num;

void nCr(int M, int cur, int cnt) {
	if (cnt == M) {
		for (int u = 0; u < M; u++) {
			cout << arr[u] << ' ';
		}
		cout << endl;
		return;
	}

	for (int u = cur; u < N; u++) {
		if (vis[u] == 0) {
			vis[u] = 1;
			arr[cnt] = numlist[u];
			nCr(M, u, cnt + 1);
			vis[u] = 0;
		}
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> numlist[i];
	}
	sort(numlist, numlist + N);
	nCr(M, 0, 0);
	return 0;
}
