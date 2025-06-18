#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <iostream>
using namespace std;



int MAX = 100000;

int visit[200002];
int cnt = 0;


int main(void) {

	int Subin, Dongsang;
	cin >> Subin >> Dongsang;
	queue<int> Q;

	visit[Subin] = 1; // (0, 0)을 방문했다고 명시
	Q.push(Subin); // 큐에 시작점인 (0, 0)을 삽입.
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if (cur == Dongsang) {
			cout << visit[cur] - 1;
			return 0;
		}
		for (int dir = 0; dir < 3; dir++) { // 상하좌우 칸을 살펴볼 것이다.
			int nx;
			switch (dir) {
				case 0:
					nx = cur * 2;
					break;
				case 1:
					nx = cur + 1;
					break;
				case 2:
					nx = cur - 1;
					break;
			}
			if (nx < 0 || nx > MAX) continue; // 범위 밖일 경우 넘어감
			if (visit[nx]) continue;
			visit[nx] = visit[cur] + 1;
			Q.push(nx);
			for (int i = 1; i <= 20; i++) {
			//cout << visit[i] << " ";
			}
			//cout << "\n";
		}
	}
}
