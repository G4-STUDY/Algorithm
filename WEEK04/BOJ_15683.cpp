// 1-4방향 ,2-2방향 ,3-4방향 ,4-4방향 ,5-1방향
//상-0 하-1 좌-2 우-3
//좌표,cctv종류 받아 board를 처리하는 함수
//현재 사각지대 넓이 반환하는 함수
#include<bits/stdc++.h>
using namespace std;
int N,M;
int result=100000;
int n=0; //cctv의 수
//3d 벡터 ->cctv번호/방향 종류/방향
vector<vector<vector<int>>> dir_inf = {
    
    {{0},{1},{2},{3}},//1번 방향
    {{0,1},{2,3}},//2번 방향
    {{0,3},{1,3},{1,2},{0,2}},//3번 방향
    {{0,2,3},{0,1,3},{1,2,3},{0,1,2}},//4번 방향
    {{0,1,2,3}}
};
//방향 벡터-상하좌우 순서
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

char board[8][8];
char cur_board[8][8];
//cctv의 상태(번호,좌표)
pair<int,pair<int,int>> cctv[8];    //ex)1 1 1 5 5 1 1 1 ->4 4 4 1 1 4 4 4
int cctv_dir[8]; //cctv_dir[n-1]까지 채울것

//현재 cctv의 정보 cur_board에 반영
void cctv_search(){
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) cur_board[i][j]=board[i][j];
    //감시 영역 표시
    for(int i=0;i<n;i++)
    {
        pair<int,int> cur =cctv[i].second;
        //cctv 종류와 조합 방향에 따라 감시 영역 표시
        for(int dir:dir_inf[cctv[i].first][cctv_dir[i]])
        {
            int nx=cur.first;
            int ny=cur.second;
            while(true)
            {
                nx=nx+dx[dir];
                ny=ny+dy[dir];
                if(nx<0||ny<0||nx>=N||ny>=M) break;
                if(cur_board[nx][ny]=='6') break;
                //다른 cctv면 아무조치안하고 진행
                if(cur_board[nx][ny]=='0') cur_board[nx][ny]='#';
            }
        }


    }
   
    
}
int cal_black(){
    int black=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            if(cur_board[i][j]=='0') black++;
        }
    return black;
}
//cctv_dir[k]을 채우는 백트래킹 함수
void back_tracking(int k){
    if(k==n)
    {
        cctv_search();
        result=min(result,cal_black());
        return;
    }
    //else (k<n)
    int dir;
    if(cctv[k].first==0) dir=4;
    else if(cctv[k].first==1) dir=2;
    else if(cctv[k].first==2) dir=4;
    else if(cctv[k].first==3) dir=4;
    else dir=1;

    for(int i=0;i<dir;i++)
    {
        cctv_dir[k]=i;
        back_tracking(k+1);
    }

} 




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    
    //board상태 입력받기
     
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            cin>>board[i][j];
            if(board[i][j]=='0'||board[i][j]=='6') continue;
            //cctv 발견
            cctv[n].first=board[i][j]-'0'-1;
            cctv[n].second={i,j};
            n++; //cctv개수이자 인덱스->cctv[n-1]까지 유효
        }
    
    back_tracking(0);
    cout<<result;
    return 0;
}
