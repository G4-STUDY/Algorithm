//백준 7511 소셜 네트워킹 어플리케이션
#include<iostream>
#include<vector>
using namespace std;
vector<int> p(1000001);

int find(int x){
    if(p[x] == -1) return x;
    p[x] = find(p[x]);
    return p[x];
}

void uni(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return; 
    p[v] = u;
    return;
}

int test(int u,int v){
    if(find(u) == find(v)) return 1;
    else return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    int test_num = 1;
    cin >> t;
    int n, k, m, a, b, u, v;
    while(t--)
    {
        cout << "Scenario " << test_num << ":\n";
        test_num++;
        cin >> n >> k;
        for(int i = 0; i < n; i++) p[i] = -1;
        //친구 관계 반영 
        while(k--)
        {
            cin >> a >> b;
            uni(a, b);
        }
        //미리 구할 쌍
        cin >> m;

        while(m--)
        {
            cin >> u >> v;
            cout << test(u, v) << '\n';
        }
        cout << '\n';
    }
    
    return 0;
}