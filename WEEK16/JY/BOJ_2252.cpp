#include <iostream>
#include <vector>

using namespace std;

vector<int> cond[32001];

vector<int> ans;
int vis[320001];

int n, m;

void func() {
    if (ans.size() == n) {
        //종료
        for (int temp : ans) {
            cout << temp << " ";
        }
        cout << "\n";
        return;
    }
    for (int i=1; i<=n; i++) {
        if (vis[i] == 1) continue;

        bool flag = true;
        for (int j=0; j<cond[i].size(); j++) {
            if (vis[cond[i][j]] == 0) flag = false;
        }

        if (!flag) continue;

        ans.push_back(i);
        vis[i] = 1;
        func();
        ans.pop_back();
        vis[i] = 0;
    }
}

int main() {

    int a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cond[b].push_back(a);
    }

    func();

    return 0;
}

/**
 * 1. dfs로 조합을 만들면서
 * 2. 내 앞에 있어야 하는 애들의 vis가 1이니? 그럼 계속 진행
 * 아니면 ㄴㄴ
 *
 *
 */