#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <iostream>
using namespace std;





int visit[1000002];
int cnt = 0;


int main(void) {

	int F, Start, Goal, Up, Down;
	cin >> F >> Start >> Goal >> Up >> Down;
	queue<int> Q;
	int dx[2] = { Up,-Down };
	char debug[2] = { 'U', 'D' };

	visit[Start] = 1; // (0, 0)을 방문했다고 명시
	Q.push(Start); // 큐에 시작점인 (0, 0)을 삽입.
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if (cur == Goal) {
			cout << visit[cur] - 1;
			return 0;
		}
		for (int dir = 0; dir < 2; dir++) { // 상하좌우 칸을 살펴볼 것이다.
			int nx = cur + dx[dir];
			if (nx < 1 || nx > F) continue; // 범위 밖일 경우 넘어감
			if (visit[nx]) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
			visit[nx] = visit[cur] + 1; // (nx, ny)를 방문했다고 명시
			Q.push(nx);
			for (int i = 1; i <= F; i++) {
				//cout << visit[i] << " ";
			}
			//cout << "\n";
		}
	}
	cout << "use the stairs";
}
