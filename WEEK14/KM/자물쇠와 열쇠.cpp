#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool board[60][60];//최대값 2m+n-2 +2(양옆빈칸)
bool mkey[21][21];
int n,m;
bool flag;
//   num   st  en
//9    1   1   9
//x    2   2   8
//x    3   3   7
//x    4   4   5  
void turnright(int st,int en){
    if(st>=en)return;
    int top[21];
    for(int i=st;i<=en;i++){
        top[i]=mkey[st][i];
    }
    //왼쪽->위
    for(int i=en;i>=st;i--){
        mkey[st][i]=mkey[en+st-i][st];
    }
    //아래->왼쪽
    for(int i=st;i<=en;i++){
        mkey[i][st]=mkey[en][i];
    }
    //오른쪽->아래
    for(int i=st;i<=en;i++){
        mkey[en][i]=mkey[en+st-i][en];
    }
    //위->오른쪽 tmp이용
    for(int i=en;i>=st;i--){
        mkey[i][en]=top[i];
    }
    //안쪽 돌리기
    turnright(st+1,en-1);
}

void unlock(int x,int y){
    //key넣을보드 초기화
    bool testboard[60][60];
    for(int i=0;i<2*m+n;i++){
        for(int j=0;j<2*m+n;j++){
            testboard[i][j]=false;
        }
    }
    //키넣기
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            testboard[x+i-1][y+j-1]=mkey[i][j];
        }
    }
    //보드확인
    for(int i=m;i<m+n;i++){
        for(int j=m;j<m+n;j++){
            if(board[i][j]){
                if(testboard[i][j])return;
            }
            else{
                if(!testboard[i][j])return;
            }
            
        }
    }
    flag=true;
    // cout<<"!!\n";
    // for(int i=0;i<2*m+n;i++){
    //     for(int j=0;j<2*m+n;j++){
    //         cout<<testboard[i][j];
    //     }
    //     cout<<'\n';
    // }
    // cout<<"??\n";
    // for(int i=0;i<2*m+n;i++){
    //     for(int j=0;j<2*m+n;j++){
    //         cout<<board[i][j];
    //     }
    //     cout<<'\n';
    // }
    // cout<<"==\n";
    // for(int i=0;i<2*m+n;i++){
    //     for(int j=0;j<2*m+n;j++){
    //         cout<<(board[i][j]||testboard[i][j]);
    //     }
    //     cout<<'\n';
    // }
    return;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    flag=false;
    m=key.size();
    n=lock.size();
    int idx=0;
    //key옮기기
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            mkey[i][j]=key[i-1][j-1];
        }
    }
    
    //board에 자물쇠 넣기
    idx=0;
    for(int i=m;i<m+n;i++){
        for(int j=m;j<m+n;j++){
            board[i][j]=lock[i-m][j-m];
        }
    }
    
    //1부터 m+n-1까지 왼쪽위 모서리에 열쇠 꼽아보기
    for(int i=1;i<m+n;i++){
        for(int j=1;j<m+n;j++){
            for(int k=0;k<4;k++){
                //풀어보기
                unlock(i,j);
                //돌려보기
                turnright(1,m);
                if(flag){//찾았으면 그냥 리턴해..
                    return flag;
                }
            }
        }
    
    }
    return answer;
}
/*
열쇠는 회전과 이동이 가능하며

M=5 N=3;

2m+n-2
10+3-2 =11
1 2 3 4 5 6 7 8 9 1011 12
M M M M M M M M M M M =11
M M M M M
M M M M M
M M M M M
M M M M M N M
        N N N 
        M N M
문제참 그지같네
*/