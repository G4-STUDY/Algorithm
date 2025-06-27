#include<bits/stdc++.h>
using namespace std;

int N, M;
int Arr[10];
int vis[10] = { 0 };
void MakeArr(int depth){
    //Arr[M-1]까지 채운 상태면 출력
    if(depth == M){
        for(int i = 0; i < M; i++){
            cout << Arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++){
        if(vis[i] == 1) continue;
        Arr[depth] = i;
        vis[i] = 1;
        MakeArr(depth + 1);
        vis[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    MakeArr(0);

    return 0;
}