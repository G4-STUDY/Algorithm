#include <string>
#include <vector>

using namespace std;

int board[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int init=1;
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=columns;j++){
            board[i][j]=init++;
        }
    }
    for(vector<int> querie:queries){
        int mnum=1e9;
        int sr=querie[0];
        int sc=querie[1];
        int er=querie[2];
        int ec=querie[3];
        //회전 ㄱㄱ
        int tmp=board[sr][ec];//오른쪽모서리값
        for(int i=ec;i>sc;i--){//윗변
            board[sr][i]=board[sr][i-1];
            mnum=min(mnum,board[sr][i]);
        }
        for(int i=sr;i<er;i++)//왼변
        {
            board[i][sc]=board[i+1][sc];
            mnum=min(mnum,board[i][sc]);
        }
        for(int i=sc;i<ec;i++)//밑변
        {
            board[er][i]=board[er][i+1];
            mnum=min(mnum,board[er][i]);
        }
        for(int i=er;i>sr;i--)//오른변
        {
            board[i][ec]=board[i-1][ec];
            mnum=min(mnum,board[i][ec]);
        }
        board[sr+1][ec]=tmp;
        mnum=min(mnum,tmp);
        answer.push_back(mnum);
    }
    return answer;
}

/*
회전 10000번 한번회전 최대 100*100
1억
그냥 구현
-------------
그냥 일차원배열로 선언하고 했으면 코드가더
간결해질거같음
*/