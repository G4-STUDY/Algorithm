//백준13549 숨바꼭질 3
#include<bits/stdc++.h>
#define DIST first
#define PRE second
using namespace std;

vector<pair<int,int>> dis_pre(100001); //first = dist, second = PRE

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> result;
    int n, k;
    cin >> n >> k;
    
    for(int i = 0; i < 100001 ; i++){
        dis_pre[i].DIST = -1;
        dis_pre[i].PRE = -1;
    }

    dis_pre[n].DIST = 0;
    queue<int> q;
    q.push(n);
    //k에 도달하기 전까지
    while(dis_pre[k].DIST == -1){
        
        int cur = q.front(); q.pop(); //n
        
        // x-1 or x+1 로 이동
        for(int nxt:{cur - 1, cur + 1, 2 * cur}){
            if(nxt < 0 || nxt > 100000) continue;
            //이미 방문했다면 pass
            if(dis_pre[nxt].DIST != -1) continue;
            q.push(nxt);
            dis_pre[nxt].DIST = dis_pre[cur].DIST + 1;
            dis_pre[nxt].PRE = cur;
        }

    }
    //nxt == k 이면 탈출 후 출력
    cout << dis_pre[k].DIST <<'\n';
    
    //PRE 정보로 k까지 경로 result에 저장
    int idx = k;
    result.push_back(idx);
    while(idx != n){
        result.push_back(dis_pre[idx].PRE);
        idx = dis_pre[idx].PRE;
    }
    
    int siz = result.size();
    //result 뒤에서부터 출력
   for(int i = siz -1; i >= 0; i--){
        cout << result[i] <<' ';
    }
    
    return 0;
}