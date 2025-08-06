#include<iostream>
#include<vector>
using namespace std;
const int INF = 0x7fffffff;

struct edge{
    int st;
    int en;
    int cost;
};

int n, m, w;
int s, e ,t;

bool bellman(int st, const vector<edge>& edges){
    bool negative_cycle = false;
    vector<int> cost(n + 1); //인덱스 1부터
    fill(cost.begin(), cost.end(), INF);
    cost[st] = 0;

    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = 0; j < edges.size(); j++)
        {
            int edge_st = edges[j].st;
            int edge_en = edges[j].en;
            int edge_cost = edges[j].cost;
            if(cost[edge_st] == INF) continue;
            int temp_cost = cost[edge_st] + edge_cost;
            if(temp_cost < cost[edge_en])
            {
                cost[edge_en] = temp_cost;
            }
        }
    }

    for(int j = 0; j < edges.size(); j++)
    {
        int edge_st = edges[j].st;
        int edge_en = edges[j].en;
        int edge_cost = edges[j].cost;
        if(cost[edge_st] == INF) continue;
        int temp_cost = cost[edge_st] + edge_cost;
        if(temp_cost < cost[edge_en])
        {
           negative_cycle = true;
           break;
        }
    }   
    return negative_cycle;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        
        vector<edge> edges;
        cin >> n >> m >> w;
        //도로-무방향 
        for(int i = 0; i < m; i++)
        {
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        //웜홀-방향
        for(int i = 0; i < w; i++)
        {
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
        }
        //벨만 포드 1 ~ n 까지 
        bool can_return = false; 
        for(int i = 1; i <= n; i++)
        {
            if(bellman(i,edges) == true)
            {
                can_return = true;
                break;
            }
        }
        if(can_return == true) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        
    }
    return 0;
}
