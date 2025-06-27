#include <iostream>
#include <vector>
using namespace std;
int arr[9][9];
bool col[9][10]; //col[i][x] i행에서 x를 사용했는지 true
bool row[9][10]; //row[i][x] i열에서 x를 사용했는지 true
bool rec[9][10]; //row[i][x] i번 사각형에서 x를 사용했는지
vector <pair<int,int>> v;

void print(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
}

void sudoku(int idx){
    if(idx==v.size()){
        print();
        exit(0);//여러개인경우 종료
    }
    int r=v[idx].first;
    int c=v[idx].second;
    int recidx=3*(r/3)+(c/3);
    for(int i=1;i<=9;i++){
        if(!row[r][i]&&!col[c][i]&&!rec[recidx][i]){//행,열,사각형에 이거 아무도 안썻어?
            row[r][i]=true;
            col[c][i]=true;
            rec[recidx][i]=true;
            arr[r][c]=i;
            sudoku(idx+1);
            row[r][i]=false;
            col[c][i]=false;
            rec[recidx][i]=false;
        }
    }
}

int main(){
    int size=0;
    int recidx=0;
    int tmp=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>tmp;
            arr[i][j]=tmp;
            if(tmp==0){
                v.push_back({i,j});
                size=v.size();
            }
            else{
                recidx=3*(i/3)+(j/3);
                rec[recidx][tmp]=true;
                col[j][tmp]=true;
                row[i][tmp]=true;
            }
        }
    }
    sudoku(0);
    return 0;
}

/*
1 2 3 4 5 6 7 8 9
2 1  / 2  /  3 /
3///////////////
4    /    /    /
5 4  / 5  / 6  /
6///////////////
7    /    /    /
8 7  / 8  /  9 /
9///////////////
(9*i)+j;

3*(i/3)+(j/3)+1



*/