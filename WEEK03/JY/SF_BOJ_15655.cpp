// 15655 N과 M (6)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
int vis[9];
vector<int> ans;

void func(int start) {
    // 개수만큼 다 찾았으면 종료
    if (ans.size() == m) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    // 조합은 순서 상관 없기 때문이 자기자신 이후부터 n까지 반복
    for (int i = start; i < n; i++) {
        // 이미 방문했으면 PASS
        if (vis[i] == 1) continue;

        ans.push_back(arr[i]);
        vis[i] = 1;
        func(i+1);
        //백트래킹
        ans.pop_back();
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(arr, arr+9, 0);
    fill(vis, vis+9, 0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 오름차순 정렬
    sort(arr, arr+n);

    func(0);

    return 0;
}