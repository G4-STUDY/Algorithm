/*네트워크 연결 */
#include <iostream>
#include <queue>
using namespace std;
vector<int> p(1001,-1);
priority_queue<pair<int,pair<int,int>>
                , vector<pair<int,pair<int,int>>>
                , greater<pair<int,pair<int,int>>>> pq;

int find_(int node){
    int parent = p[node];
    if(parent < 0) return node;
    return find_(parent);
}
bool union_(int node1, int node2){
    int r1 = find_(node1);
    int r2 = find_(node2);
    if(r1 == r2) return true; //그룹이 이미 같은 경우 return
    //그룹이 다른 경우 -> union
    if(p[r1] == p[r2]){
        p[r2] = r1; 
        p[r1]--;
    }
    else if(p[r1] < p[r2]) p[r2] = r1; // r1 그룹의 높이 더 높은 경우
    else p[r1] = r2;

    return false;

}
int main() {
    int n, m;
    cin >> n >> m; 
    for(int i=0; i<m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        pq.push({c,{a,b}});
    }
    

    int edge_num = 0;
    int result = 0;
    while(edge_num < n - 1){
        pair<int,pair<int,int>> cur_edge = pq.top(); pq.pop(); //비용 가장 낮은 간선
        int cost = cur_edge.first;
        int n1 = cur_edge.second.first;
        int n2 = cur_edge.second.second;
        if(union_(n1, n2)) continue; //이미 같은 간선이면 pass(추가x)
        //간선 최소신장트리에 포함
        result += cost;
        edge_num ++;
    }

    cout << result;
}

/*
    "모든 컴퓨터 연결" + "비용 최소화" -> 최소 신장 트리 
    최소 비용 출력 
*/