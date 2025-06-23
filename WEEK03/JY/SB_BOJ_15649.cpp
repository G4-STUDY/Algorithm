// 15649 N과 M(1)
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int vis[9];
vector<int> ans;

void func() {
    if (ans.size() == m) {
        for (int i=0; i<m; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    // 순열은 순서 상관이 있기 때문에 1부터 n까지 반복
    for (int i=1; i<=n; i++) {
        // 이미 사용했으면 패스
        if (vis[i] == 1) continue;

        // 정답에 사용하지 않은 숫자를 넣는다
        ans.push_back(i);
        // 방문 표시
        vis[i] = 1;
        // 재귀 호출
        func();
        // 백트래킹
        ans.pop_back();
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func();

    return 0;
}