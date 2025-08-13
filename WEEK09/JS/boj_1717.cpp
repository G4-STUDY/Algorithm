//백준 1717 집합의 표현 
#include<iostream>
#include<vector>
using namespace std;
vector<int> parent;
int find(int x);
void uni(int u, int v);
string test(int u, int v);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    parent.resize(n+1); // valid index:0 ~ n 
    fill(parent.begin(), parent.end(), -1);
    
    while(m--)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 0) uni(a, b);
        else cout << test(a, b) << '\n'; // op == 1
    }

    return 0;
}

int find(int x){
    if(parent[x] == -1) return x; 
    parent[x] = find(parent[x]);
    return parent[x];
}

void uni(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    else parent[v] = u;
}

string test(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return "YES";
    else return "NO";
    
    
}

