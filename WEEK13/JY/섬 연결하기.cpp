#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

int p[101];

int find(int a){
    if(p[a] == -1) return a;
    return p[a] = find(p[a]);
}

int my_uni(int a, int b){
    int x = find(a);
    int y = find(b);

    if(x == y) return -1;

    p[y] = x;
    return 1;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    fill(p, p+n+1, -1);

    priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
    map<int, int> m;

    for(vector<int> cost : costs){
        vector<int> v;
        v.push_back(cost[2]);
        v.push_back(cost[0]);
        v.push_back(cost[1]);

        pq.push(v);
    }

    int cnt = 0;
    while(true){
        if(cnt == n - 1) break;

        vector<int> cur = pq.top();
        pq.pop();

        int cost = cur[0];
        int a = cur[1];
        int b = cur[2];

        if(find(a) == find(b)) continue;

        my_uni(a, b);
        answer += cost;
        cnt++;
        //cout << a << " " << b << " " << cnt << "\n";
    }

    return answer;
}

/*
모든 노드를 연결 -> 최소 신장 트리

- 간선의 개수가 n-1이 될때까지 반복

1. 간선 기준 오름차순 정렬
2. 두 노드가 같은 그룹에 있는가? 있으면 pass / 아니면 추가
3. 간선 개수가 n-1일때까지 반복

*/