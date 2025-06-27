//백준 9663 N Queen
#include<bits/stdc++.h>
#define ROW first
#define COL second
using namespace std;
int N;
int result = 0;
vector<pair<int,int>> cur_queen; //현재 놓여있는 퀸 

void backtrack(int row){
    if(row == N){
        result++;
        return;
    }
    
    for(int col = 0; col < N; col++){
        bool can_contain = true;
        for(auto cur : cur_queen){
            //열방향 확인
            if(cur.COL == col) {
                can_contain = false;
                break;
            }
            //대각선 방향 확인
            if(row + col == cur.ROW + cur.COL || row - col == cur.ROW - cur.COL ){
                can_contain = false;
                break;
            } 
        }
        if(can_contain == false) continue;
        cur_queen.push_back({row, col});
        backtrack(row + 1);
        cur_queen.pop_back();
    }
}





int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    backtrack(0);
    cout << result;

    return 0;
}