//백준 16398 행성 연결 
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int p[1001];
int cost_ij[1001][1001];

int find(int x){
    if(p[x] < 0) return x;
    p[x] = find(p[x]);
    return p[x];
}

void uni(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    //u가 루트인 트리의 높이가 더높으면 
    if(p[u] < p[v])
    {
        //높이 낮은 트리의 루트의 부모를 높이 높은 트리의 루트
        //합쳐진 트리의 높이는 여전히 높은 트리의 높이
        p[v] = u;
    }
    else if(p[u] > p[v])
    {
        p[u] = v;
    }
    else
    {
        p[v] = u; // or p[u] = v 
        p[u]--; //높이 1 증가 
    }

    return;
}

bool isSameGroup(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return true;
    else return false;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<pair<int, pair<int, int>>> edges;
    
    int n; //정점 수
    memset(p, -1, sizeof(p));
    cin >> n;
    
    //모든 정점쌍에 대해 cost 입력 받기
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
        {
            cin >> cost_ij[i][j];
        }
    }
    //모든 간선 정보 벡터에 저장 
    for(int i = 1; i <= n - 1; i++){
        for(int j = i + 1; j <= n; j++)
        {
            int cost = cost_ij[i][j];
            edges.push_back({cost, {i, j}});
        }
    }
    int edge_num = edges.size(); //간선 수
    sort(edges.begin(), edges.end());
    //크로스칼 알고리즘 
    int idx = 0;
    int added_num = 0;
    long long total_cost = 0;
    for(int i = 0; i < edge_num; i++)
    {
        //1 최소 cost 간선 뽑기 
        int st = edges[idx].second.first;
        int en = edges[idx].second.second;
        int cost = edges[idx].first;
        idx++;
        //2.같은 그룹인지 확인, 다른 그룹이면 같은 그룹으로
        if(isSameGroup(st, en) == true) continue;
        uni(st, en);
        added_num++; 
        total_cost += cost;
        //3.최소신장트리에 추가한 간선 수 n-1 이면 종료(완성)
        if(added_num == n - 1) break;
        
    }
    cout << total_cost;
    return 0;
}

