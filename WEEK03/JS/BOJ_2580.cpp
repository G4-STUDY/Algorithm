#include <bits/stdc++.h>
using namespace std;
int board[9][9];
int result[9][9];
bool done = false; //백트래킹함수 return 시 상태 변경 방지 
vector<pair<int, int>> toFill; // 채울 칸 좌표
int num; //채울 칸 수 
void backtrack(int depth);
//가로 탐색
bool CheckRow(int r, int n)
{
    bool ispos = true;
    for (int i = 0; i < 9; i++)
    {
        // 채우려고 하는값 num이 가로에 있으면 false
        if (board[r][i] == n)
            ispos = false;
    }
    return ispos;
}
//세로 탐색
bool CheckCol(int c, int n)
{
    bool ispos = true;
    for (int i = 0; i < 9; i++)
    {
        // 채우려고 하는값 num이 세로에 있으면 false
        if (board[i][c] == n)
            ispos = false;
    }
    return ispos;
}
//박스 탐색
bool CheckBox(int r, int c, int n)
{
    bool ispos = true;

    for (int i = (r / 3) * 3; i < (r / 3) * 3 + 3; i++)
    {
        for (int j = (c / 3) * 3; j < (c / 3) * 3 + 3; j++)
        {
            if(board[i][j] == n) ispos = false;
        }
    }

    return ispos;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0) toFill.push_back({i, j});
        }
    }
    num = toFill.size(); // 채울 칸 개수
    backtrack(0);

    //출력
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j]<<' ';
        }
        cout << '\n';
    }
    return 0;
}

void backtrack(int depth){
    //다채웠으면 결과 벡터에 복사후 rerturn 
    if(depth == num ){
        done = true;
        return;
    } 

    int r = toFill[depth].first;
    int c = toFill[depth].second;
    // 1~9까지 채울 수 있는 지 확인
    for(int n = 1; n <= 9; n++ )
    {
        if(CheckRow(r,n) && CheckCol(c,n) && CheckBox(r,c,n))
        {
            //채울 수 있으면 채우고 다음 level 
            board[r][c] = n;
            backtrack(depth+1);
            //상태 복귀 
            if(done == true) continue;
            board[r][c] = 0;
        }
        else continue;
        
    }
}