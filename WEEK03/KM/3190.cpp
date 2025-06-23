#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n,k;
int board[101][101];
int dir[2]={0,1};
vector<pair<int,int>> v; //first 시간, 방향
pair<int,int> head;
pair<int,int> tail;
queue<pair<int,int>> q; //마지막꺼 pair<int,int> head; q.front() pair<int,int> tail;

void turn(int op){
    if(op==1){//오른쪽으로
        if(dir[0]==0){//y가 0일떄
            dir[0]=dir[1];//x->y * 1
            dir[1]=0;
        }
        else{   //x가 0일때
            dir[1]=-1*dir[0];//y->x * -1
            dir[0]=0;
        }
    }
    else{//왼쪽으로
        if(dir[0]==0){//y가 0일떄
            dir[0]=-1*dir[1];//x -> y * - 1
            dir[1]=0;
        }
        else{   //x가 0일때
            dir[1]=dir[0];//y -> x * 1
            dir[0]=0;
        }
    }
}

void print_board(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

int main()
{
    cin>>n>>k;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>y>>x;
        board[y-1][x-1]=1;
    }
    int l;
    cin>>l;
    for(int i=0;i<l;i++){
        int x,curve;char c;
        cin>>x>>c;
        if(c=='L')
        {
            curve=0;
        }
        else
        {
            curve=1;
        }
        v.push_back({x,curve});
    }
    head={0,0};
    tail={0,0};
    q.push({0,0});//뱀
    board[0][0]=2;
    int time=0;
    for(pair<int,int> p:v){
        int nt=p.first;
        int curve=p.second;
        while(!q.empty()&&time<nt){
            //print_board();
            time++;
            int ny=head.first+dir[0];
            int nx=head.second+dir[1];
            if(0<=nx&&nx<n&&0<=ny&&ny<n){//전진
                if(board[ny][nx]==2){//자기몸일때
                    cout<<time;
                    return 0;
                }
                else if(board[ny][nx]==1){//사과일떄
                    q.push({ny,nx});
                    head={ny,nx};
                    board[ny][nx]=2;
                }
                else{//빈칸일때
                    q.push({ny,nx});
                    head={ny,nx};
                    board[ny][nx]=2;
                    q.pop();
                    board[tail.first][tail.second]=0;
                    tail=q.front();

                }
            }
            else{//벽일때
                cout<<time;
                return 0;
            }
        }
        //cout<<time<<"\n";
        //print_board();
        //cout<<curve<<' ';
        turn(curve);
        //cout<<"dir"<<dir[0]<<' '<<dir[1]<<'\n';
    }
    while(!q.empty()){
            //print_board();
            time++;
            int ny=head.first+dir[0];
            int nx=head.second+dir[1];
            if(0<=nx&&nx<n&&0<=ny&&ny<n){//전진
                if(board[ny][nx]==2){//자기몸일때
                    cout<<time;
                    return 0;
                }
                else if(board[ny][nx]==1){//사과일떄
                    q.push({ny,nx});
                    head={ny,nx};
                    board[ny][nx]=2;
                }
                else{//빈칸일때
                    q.push({ny,nx});
                    head={ny,nx};
                    board[ny][nx]=2;
                    q.pop();
                    board[tail.first][tail.second]=0;
                    tail=q.front();

                }
            }
            else{//벽일때
                cout<<time;
                return 0;
            }
        }
    return 0;
}

/*
left로 꺾을때
    y  x
up = 0,1;
left = -1 0
down 0 -1
right 1 0
x -> y - 1
y -> x = 1
0 1
-1 0
0 -1
1 0
0 1

right로 꺾을때

up = 0,1;
right 1 0
down 0 -1
left = -1 0
x->y 1
y->x -1

*/