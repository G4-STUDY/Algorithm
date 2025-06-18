//백준1697 숨바꼭질
#include<bits/stdc++.h>
using namespace std;

int N, K;
bool vis[100001];
int minute = 0;
//현재 위치 x에 대해 인덱스에 따라 다음 위치 반환
int return_nxt(int n,int cur){
    int nxt;

    if(n == 1) nxt = (cur - 1);
    else if(n == 2) nxt = (cur + 1);
    else nxt = (2 * cur);

    return nxt;
}

int main(){
    cin >> N >> K; //수빈좌표, 동생 좌표
    
    if( N == K){
        cout << 0;
        return 0;
    }
    vis[N] = true;

    queue<int> q;
    q.push(N);
    while(!q.empty()){
        int siz = q.size();
        for(int i =0; i < siz; i++){
            int cur = q.front(); q.pop();

            for(int n = 1; n <= 3; n++){
                int nxt = return_nxt(n, cur);
                if(nxt < 0 || nxt > 100000) continue;
                if(vis[nxt] == true) continue;
                
                //종료 조건
                if(nxt == K){
                    cout << minute + 1;
                    return 0;
                }
                q.push(nxt);
                vis[nxt] = true;
            }
        }
        minute++;
    }

}

/*
(설계)

-방문 배열 vis[100000]
-수빈 X -> 1초후 X-1 또는 X+1 또는 2*X (주변 좌표 3개)
-한번 방문한 곳 다시 방문 X (최단 시간)
-동생 N 처음 도달 시 시간 출력 

-주어지는 수빈과 동생의 좌표의 범위는 "시작점"의 범위임
-이후 수빈의 좌표는 100000을 넘어갈 수 있음
-범위를 정하지않으면 q에 무한정으로 다음 좌표 들어감
-다음 좌표의 가능한 범위는 어디까지?

*/