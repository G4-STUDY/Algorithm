#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int p[100001];

int find(int x);
void uni(int u, int v);
bool isSameGroup(int u, int v);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; //정점, 간선
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges; //{cost,{st,en}}
    int a, b, c;
    for(int i = 0; i < m; i++)
    {    
        cin >> a >> b >> c;
        edges.push_back({c,{a, b}});
    }

    
    //하나의 최소신장트리 생성
    //크루스칼 알고리즘 
    sort(edges.begin(), edges.end());
    
    int idx = 0; //cost 오름차순 정렬된 edges 순회 시 현재 인덱스
    int added_number = 0; //최소신장트리에 추가된 간선 수
    long long total_cost = 0; //최소신장트리의 총 cost
    int max_cost; //마지막 추가된 간선의 cost (최대 cost)
    for(int i = 0; i < m; i++)
    {
        //1.현재 최소 비용 간선 선택
        int st = edges[idx].second.first;
        int en = edges[idx].second.second;
        int cost = edges[idx].first;
        
        idx++;
        //2.st en 이 같은 그룹인지 확인
        if(isSameGroup(st, en) == true) continue;
        
        //3.다른 그룹이면 같은 그룹으로 만들기
        uni(st, en);
        added_number++;
        total_cost += cost;
        //4.최소신장트리에 간선 추가 시 전체 간선 수가 n-1이면 종료(생성 완료)
        if(added_number == n - 1)
        {
            max_cost = cost;
            break;
        }
        
    }
    //최대 cost의 간선 끊어서 마을 분리
    cout << total_cost - max_cost;
    return 0;
}

int find(int x){
    if(p[x] == 0) return x;
    //경로 압축
    p[x] = find(p[x]); 
    return p[x];
}

void uni(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return; //이미 같은 그룹이면  return
    //다른 그룹이면 같은 그룹으로 (한 트리의 루트를 다른 트리의 루트의 자식으로)
    p[v] = u;
    return;
}

bool isSameGroup(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return true;
    else return false;
}