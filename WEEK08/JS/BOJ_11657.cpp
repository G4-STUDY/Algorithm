//타임머신
//38% 출력 초과
//52% 오답 
#include<iostream>
#include<vector>
#define ll long long
using namespace std;
const int INF = 0x7fffffff;
int n, m;
//간선 데이터 
struct edge{
    int st;
    int en;
    int cost;
};

void checkAllEdfe(){
    
}

vector<edge> edges; //간선 저장 벡터 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<edge> edges;

    cin >> n >> m;
    int a, b, c;
    //간선 입력 
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    int edge_number = edges.size();
    //initial setting
    vector<ll> cost(n + 1); //인덱스 1부터
    fill(cost.begin(), cost.end(), INF);
    cost[1] = 0; 
    //n-1 번 반복 
    for(int i = 1; i <= n - 1; i++)
    {
        //간선 순회 
        for(int j = 0; j < edge_number; j++)
        {
            if(cost[edges[j].st] == INF) continue;
            ll temp_cost = cost[edges[j].st] + edges[j].cost; //cost[en] 후보 = cost[st] + (st->en 비용)
            if(temp_cost < cost[edges[j].en])
            {
                cost[edges[j].en] = temp_cost;
            }
        }
    }
    //음의 간선 사이클 확인
    bool negative_cycle = false;
     
    for(int j = 0; j < edge_number; j++)
    {
        if(edges[j].st == INF) continue;
        ll temp_cost = cost[edges[j].st] + edges[j].cost; //cost[en] 후보 = cost[st] + (st->en 비용)
        if(temp_cost < cost[edges[j].en])
        {
            //한번더 순회시, 업데이트되면 음의 간선 사이클 존재
            negative_cycle = true;
            break;
        }
    }
    //출력
    if(negative_cycle == true) cout << -1;
    else
    {
        for(int i = 2; i <= n; i++)
        {
            if(cost[i] == INF) cout << -1<<'\n';
            else cout << cost[i] << '\n';
        }
    }

    return 0;
}

