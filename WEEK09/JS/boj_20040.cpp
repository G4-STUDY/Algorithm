//백준 20040 사이클 게임
#include<iostream>
#include<vector>
using namespace std;

vector<int> p;

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
}

bool isSameGroup(int u, int v){
    if(find(u) == find(v)) return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int turn_finished = 0;
    int cur_turn = 1;
    int n, m;
    cin >> n >> m;
    p.resize(n);
    fill(p.begin(), p.end(), -1);

    int u, v;
    while(m--)
    {
        cin >> u >> v;
        if(turn_finished != 0) continue;
        if(isSameGroup(u, v) == true) turn_finished = cur_turn;
        else uni(u, v);
        

        cur_turn++;
    }

    cout << turn_finished;
}

