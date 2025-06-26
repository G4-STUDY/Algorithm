#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

int arr[30];
int vis[30][30];
long long num = 0;
void PutQueen(int N, int cnt) {
	if (cnt > N) {
		num++;
		return;
	}
	for (int u = 1; u <= N; u++) {
		if (vis[cnt][u] == 0) {
			for (int v = cnt; v <= N + cnt; v++) {
				if (v <= N) vis[v][u] += 1;
				if ((u + v - cnt) <= N) vis[v][u + v - cnt] += 1;
				if ((u - v + cnt) >= 1) vis[v][u - v + cnt] += 1;
			}
			arr[cnt] = u;
			PutQueen(N, cnt + 1);
			for (int v = cnt; v <= N + cnt; v++) {
				if (v <= N) vis[v][u] -= 1;
				if ((u + v - cnt) <= N) vis[v][u + v - cnt] -= 1;
				if ((u - v + cnt) >= 1) vis[v][u - v + cnt] -= 1;
			}
		}
	}
	return;
}


int main(void) {
	int N;
	cin >> N;
	PutQueen(N, 1);
	cout << num;
	return 0;
}
