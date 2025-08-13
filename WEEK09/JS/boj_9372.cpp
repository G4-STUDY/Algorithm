//백준 9372 상근이의 여행 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    int n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        while(m--)
        {
            int a, b;
            cin >> a >> b;
        }
        cout << n - 1 << '\n';
    }
    return 0;
}
/*
연결 그래프
모든 정점 방문 -> 신장 트리
모든 신장트리는 걍 간선개수 n-1 

*/