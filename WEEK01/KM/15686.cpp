#include <iostream>
#include <vector>

using namespace std;

int n,m;
int board[51][51];
vector<vector<int>> dist; //dist[치킨집][집]
vector<pair<int,int>> home; //집
vector<pair<int,int>> chicken; //치킨집
int arr[251]; //조합
int ans=1e9;

void calc(){
    int distance=0;
    for(int i=0;i<dist[0].size();i++)//각집에서서
    {
        int tmp=1e9;
        for(int j=0;j<m;j++)//m개만큼 선정된거거
        {
            tmp=min(tmp,dist[arr[j]][i]); //선정된 치킨집까지거리
        }
        distance+=tmp;
    }
    ans=min(ans,distance);
}

void comb(int cur,int size)//조합구하기기
{
    if(size==m){//계산산
        calc();
        return;
    }
    for(int i=cur;i<chicken.size();i++){
        arr[size]=i;
        comb(i+1,size+1);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>board[i][j];
            if(board[i][j]==1)
                home.push_back({i,j});
            if(board[i][j]==2)
                chicken.push_back({i,j});
        }
    }
    for(pair<int,int> c:chicken)
    {
        vector<int> tmp;    //치킨집에서 각집까지 거리
        for(pair<int,int> h:home){
            tmp.push_back(abs(h.first-c.first)+abs(h.second-c.second));
        }
        dist.push_back(tmp);
    }
    comb(0,0); //조합
    cout<<ans;
    return 0;
}

/*
0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
2 0 0 1 1
2 2 0 1 2

0 x 0 1 0
1 0 1 0 0
0 0 0 0 0
x 0 0 1 1
x x 0 1 x




*/