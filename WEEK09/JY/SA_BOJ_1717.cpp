// 1717 집합의 표현

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int graph[1000001];

int find(int a) {
    if (graph[a] < 0) return a;
    return graph[a] = find(graph[a]);
}

bool uni(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return false;
    graph[b] = a;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, f, a, b;

    cin >> n >> m;
    fill(graph, graph+n+1, -1);

    for (int i=0;i<m; i++) {
        cin >> f >> a >> b;
        if (f == 0) {
            // 합집합
            uni(a, b);
        }
        else if (f == 1){
            // 같은 그룹 확인
            if (find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}