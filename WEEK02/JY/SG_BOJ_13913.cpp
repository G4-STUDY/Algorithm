// 13913 숨바꼭질 4

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int vis[200001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    // 수빈이와 동생이 같은 위치에 있는 경우 종료
    if (n == k) {
        cout << "0" << "\n" << n;
        return 0;
    }

    fill(vis, vis+200001, -1);

    // 수빈이 위치에서 시작, BFS는 숨바꼭질(13549)과 동일
    queue<int> q;
    q.push(n);
    vis[n] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int next;
        for (int i=0; i<3; i++) {
            if (i==0) next = cur * 2;
            if (i==1) next = cur + 1;
            if (i==2) next = cur - 1;

            if (next < 0 || next > 200001) continue;

            if (vis[next] == -1) {
                q.push(next);
                vis[next] = vis[cur] + 1;
            }
        }
    }

    cout << vis[k] << "\n";

    //BFS이후 지나온 경로 역추적

    //동생의 위치에서 시작
    int idx = k;
    vector<int> way;
    way.push_back(k);

    //수빈이 위치에 도달할 때 까지 진행
    while (idx != n) {
        int temp;
        for (int i=0; i<3; i++) {
            if (i==0) {
                if (idx%2 != 0) continue; // 이 조건이 없으면 temp가 0이 된다 !!
                temp = idx/2;
            }
            else if (i==1) temp = idx - 1;
            else if (i==2) temp = idx + 1;

            if (temp < 0 || temp > 200001) continue;

            //나보다 1초 작은 경우 내가 지나온 길임
            if (vis[temp] == vis[idx]-1) {
                way.push_back(temp);
                idx = temp;
                break;
            }
        }
    }

    //뒤에서부터 넣었기 때문에 반대로 출력
    for (int i = way.size()-1 ; i >= 0; i--) {
        cout << way[i] << " ";
    }

    return 0;
}