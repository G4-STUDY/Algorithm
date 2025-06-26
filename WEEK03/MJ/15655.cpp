#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int arr[10];
int print_arr[10];
int vis[10];
void nCr(int N, int M, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M-1; i++) {
			if (print_arr[i] > print_arr[i + 1]) return;
		}
		for (int i = 0; i < M; i++) {
			cout << print_arr[i] << ' ';
		}
		cout << '\n';
	}

	for (int u = 0; u < N; u++) {
		if (vis[u] == 0) {
			vis[u] = 1;
			print_arr[cnt] = arr[u];
			nCr(N, M, cnt + 1);
			vis[u] = 0;
		}
	}
}

int main(void) {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	nCr(N, M, 0);

	return 0;
}
