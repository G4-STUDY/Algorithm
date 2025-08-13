//백준 1197 최소 스패닝 트리
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int p[10001]; //인덱스 1부터

int find(int x);
void uni(int u, int v); 
bool isSameGroup(int u, int v);



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long result = 0;
    int v, e;
    cin >> v >> e;
    for(int i = 1; i <= v; i++) p[i] = -1; //각 정점의 부모
    vector<pair<int, pair<int,int>>> edges; //{cost,{st,en}}
    int a, b, c;
    while(e--)
    {
        cin >> a >> b >> c;
        edges.push_back({c,{a,b}});
    }

    sort(edges.begin(), edges.end());
    int idx = 0;
    int add_num = 0; //추가시킨 간선 수
    while(true)
    {
        int st = edges[idx].second.first;
        int en = edges[idx].second.second;
        int cost = edges[idx].first;
        idx++;
        if(isSameGroup(st, en) == true) continue;
        uni(st, en); //같은 그룹으로
        add_num++; //추가시킨 간선 수
        result += cost; //가중치 누적
        
        if(add_num == v - 1) break; //추가시킨 간선 수 == v-1 이면 종료(완성)
    }

    cout << result;
    return 0;
}

int find(int x){
    if(p[x] == -1) return x;
    p[x] = find(p[x]);
    return p[x];
}

void uni(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    else p[v] = u;
    return;
}

bool isSameGroup(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return true;
    else return false;
}