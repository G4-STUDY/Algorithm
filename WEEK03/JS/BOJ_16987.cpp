//백준 16987 계란으로 계란치기
#include<bits/stdc++.h>
using namespace std;

int N;
int cur_broken = 0;
int mx_broken = 0;
struct Egg{
    int life;
    int wei;
};
//계란상태 전역 벡터로 저장
vector<Egg> v;

void backtrack(int n){

    if(n==N){
        mx_broken = max(mx_broken, cur_broken);
        return;
    }
    
    //들어올린 계란이 깨진 계란->상태 변경하지 않고 다음 level
    if(v[n].life <= 0) backtrack(n+1);
    else{
        //들어올렸는데 칠수있는 계란 없는 경우 최댓값 갱신 후 바로 return
        if(cur_broken == N - 1){
        backtrack(n+1);
        return;
        }
        //들어올린 계란이 안깨진 계란->칠수있는 계란 탐색, 치고 다음 level
        for(int i = 0; i < N; i++){
            if(i == n || v[i].life <= 0) continue;
                Egg cur_egg = v[n];
                Egg nxt_egg = v[i]; //상태 저장
                int tmp = 0; //현재 레벨에서 깨진 계란수 
                v[n].life = v[n].life - v[i].wei;
                if(v[n].life <= 0) tmp++;
                v[i].life = v[i].life - v[n].wei;
                if(v[i].life <= 0) tmp++;
                cur_broken += tmp;
                backtrack(n+1);
                //치기 전 상태로 복구
                v[n] = cur_egg;
                v[i] = nxt_egg;
                cur_broken -= tmp;
            
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //입력 
    cin >> N;
    Egg egg;
    for(int i = 0; i < N; i++){
        cin >> egg.life >> egg.wei;
        v.push_back(egg);
    }
    backtrack(0);
    cout << mx_broken;
    return 0;
}

