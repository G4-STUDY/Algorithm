//백준 5014 스타트링크 
#include<bits/stdc++.h>
using namespace std;

int result = 0;  
int F, S, G, U, D; //최고층, 현재층, 목적지, up단위, down단위
bool vis[1000002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cur, nxt_up, nxt_down;
    cin >> F >> S >> G >> U >> D;

    //시작층이 목표층인 경우 예외 처리
    if(S == G){
        cout << 0;
        return 0;
    }
    
    queue<int> q;
    q.push(S);
    vis[S] = true;

    while(!q.empty()){
        int siz = q.size(); // 1 or 2
        //현재 레벨에 대해 주변 탐색
        for(int i = 0; i < siz; i++){
            cur = q.front(); q.pop();
            //UP
            nxt_up = cur + U;
            //DOWN
            nxt_down = cur - D;
            //목표층 도달 -> return
            if((nxt_up) == G || (nxt_down) == G){
                cout << result + 1;
                return 0;
            }
            //UP에 대해 탐색 가능 여부 판단
            if((nxt_up <= F) && (vis[nxt_up] == false)){
                q.push(nxt_up);
                vis[nxt_up] = true;
            }
            //DOWN에 대해 탐색 가능 여부 판단
            if((nxt_down >= 1) && (vis[nxt_down] == false)){
                q.push(nxt_down);
                vis[nxt_down] = true;
            }
        }
        result++;
        
    }
    //큐가 빌 때까지 G층 도달못하면 출력
    cout << "use the stairs";
    return 0;
}



/*
(test case1)
건물높이 10층
현재 위치 1층 (최하층 1층, S <= 1)
목적지 10층

UP 2층
DOWN 1층 
=> UP 3번 = 7층, DOWN 1번 = 6층, UP 2번 = 10층  총 6번

적어도 몇번 = 최단 거리 = BFS 

현재 위치에 대한 다음 이동 층 탐색 (UP, DOWN)
->F 보다 작거나 같아야 함
->1 보다 크거나 같아야 함
->이전에 방문한 층이 아니여야함
->처음으로 G층일때 종료

=>이동가능한 칸 없을 때 문자열 출력
*/