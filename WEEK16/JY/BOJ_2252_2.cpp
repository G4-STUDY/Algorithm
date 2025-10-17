#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> cond[32001];
int cnt[32001];

queue<int> q;

int n, m;

int main() {

    int a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cond[a].push_back(b);
        cnt[b]++;
    }

    for (int i=1; i<=m; i++) {
        if (cnt[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        cout << idx << " ";

        for (int temp : cond[idx]) {
            cnt[temp]--;
            if (cnt[temp] == 0) q.push(temp);
        }

    }

    return 0;
}

/**
 * 1. indegree를 모두 조사하면서 0인걸 큐에 넣은다
 * 2. 큐에서 빼고 indegree 갱신
 *
 * 1. 자기가 가리키는 자식 번호를 저장하고 있음
 * 2. 이게 사이즈가 0이면 큐에 들어가
 * 3. 사이즈 저장하는 배열도 갖고
 * 3. 들어가면서 자식으로 포함되어 있으면 지워져
 *
 */