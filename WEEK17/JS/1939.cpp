//중량제한 
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
vector<pair<int,int>> adj[10001]; // {무게,노드}
set<int> weights;
vector<int> v;
int N; //노드의 수
int M; //간선의 수 
int start, dest; 
bool Check(int weight);
int main(){
     
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int A, B, C;
        cin >> A >> B >> C;
        adj[A].push_back({C,B}); 
        adj[B].push_back({C,A});

        weights.insert(C);
    }
    for(auto w : weights){
        v.push_back(w);
    }
    sort(v.begin(), v.end());
    
    cin >> start >> dest;
    
    
    int st = 0; int en = v.size() - 1;
    //예외
    if(Check(v[en]) == true){
        cout << v[en];
        return 0;
    }

    while(st + 1  < en){
        int mid = (st+en) / 2;
        if(Check(v[mid]) == true) st = mid;
        else en = mid;

    }
    cout << v[st];
    return 0;
}

bool Check(int weight) {
    vector<bool> vis(N+1,false);
    queue<int> q;
    q.push(start);
    vis[start] = true;
    bool is_possible = false;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(pair<int,int> nxt : adj[cur]){
            int nxt_node = nxt.second;
            int limit = nxt.first;
            if(vis[nxt_node] == true) continue;
            if(limit < weight) continue;
            if(nxt_node == dest){
                is_possible = true;
                break;
            }
            q.push(nxt_node);
            vis[nxt_node] = true;
            
        }
         if(is_possible == true) break;
    }
    return is_possible;
}