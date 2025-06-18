#include<bits/stdc++.h>
using namespace std;
#define MX 1000001
int dis[MX]; 
int F, S, G, U, D;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> F >> S >> G >> U >> D; //최고층, 현재층, 목적지, up단위, down단위
    for(int i =1; i < MX; i++){
        dis[i] = -1;
    }

    dis[S] = 0;
    queue<int> Q;
    Q.push(S);
    
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int nxt : {cur + U, cur - D}){
            //범위 벗어난 층 pass
            if(nxt < 1 || nxt > F) continue;
            //이미 방문된 층 pass
            if(dis[nxt] != -1 ) continue;
            dis[nxt] = dis[cur] + 1;
            Q.push(nxt);
        }

    //while문 내에서 nxt = S 가되면 탈출
    
    }

    if(dis[G] != -1){
        cout << dis[G];
    }
    else{
        cout << "use the stairs";
    }
    
    return 0;
}