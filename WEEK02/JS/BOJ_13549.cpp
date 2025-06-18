//백준13549 숨바꼭질 3
#include<bits/stdc++.h>
using namespace std;

int dis[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    
    fill(dis, dis + 100001, -1);
    dis[n] = 0;
    queue<int> q;
    q.push(n);
    //k에 도달하기 전까지
    while(dis[k] == -1){
        
        int cur = q.front(); q.pop();
        
        // x-1 or x+1 로 이동
        for(int nxt:{cur - 1, cur + 1}){
            if(nxt < 0 || nxt > 100000) continue;
            //이미 방문했다면 pass
            if(dis[nxt] != -1) continue;
            q.push(nxt);
            dis[nxt] = dis[cur] + 1;
        }
        // 2 * x 로 이동
        int nxt = 2 * cur;
        if(nxt > 100000) continue;
        if(dis[nxt] != -1) continue;
        q.push(nxt);
        //nxt 는 cur 과 같은 시간에 도달 
        dis[nxt] = dis[cur];


    }
    //nxt == k 이면 탈출 후 출력
    cout << dis[k];
    return 0;
}
