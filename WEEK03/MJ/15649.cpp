#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

int arr[10];
int vis[10];
void nPr(int N, int M, int cnt) {
	if (cnt > M) {
		for (int u = 1; u <= M; u++) {
			cout << arr[u] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int u = 1; u <= N; u++) {
		if (vis[u] != 1) {
			vis[u] = 1;
			arr[cnt] = u;
			nPr(N, M, cnt + 1);
			vis[u] = 0;
		}
	}
}


int main(void) {
	int N, M;
	cin >> N >> M;
	nPr(N, M, 1);
	return 0;
}
