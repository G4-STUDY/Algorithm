#include <iostream>
#include <vector>
using namespace std;

int t, w;
vector<pair<bool, int>> arr;
int dp[2][31][1001];
//    나무 k  분기점
//    해당분기점일때 해당 나무 밑일때 k번 이하로 바꿨을때의 최대값
int main()
{
    cin >> t >> w;
    int x;
    bool namu = 0;
    int cnt = 0;
    arr.push_back({false, 0}); // 처음시작
    for (int i = 0; i < t; i++)
    {
        cin >> x;
        if (namu ==(bool)(x - 1))
        {
            cnt++;
        }
        else
        {
            arr.push_back({namu, cnt});
            cnt = 1;
            namu = !namu;
        }
    }
    arr.push_back({namu, cnt});
    for (int idx = 1; idx < arr.size(); idx++)
    {   //처음은 1번나무 밑에있으니까
        bool cur = arr[idx].first;
        int size = arr[idx].second;
        if(cur==0)
            dp[0][0][idx]=dp[0][0][idx-1]+size;
        else
            dp[0][0][idx]=dp[0][0][idx-1];
            // cout<<"dp["<<0<<"]["<<0<<"]["<<idx<<"]="<<dp[0][0][idx]<<'\n';
    }
    for (int k = 1; k <= w; k++)
    {
        for (int idx = 1; idx < arr.size(); idx++)
        {
            bool cur = arr[idx].first;
            int size = arr[idx].second;
            dp[cur][k][idx]=max(dp[!cur][k-1][idx-1],dp[cur][k][idx-1])+size;
            dp[!cur][k][idx]=max(dp[cur][k-1][idx-1],dp[!cur][k][idx-1]);
            // cout<<"dp["<<cur<<"]["<<k<<"]["<<idx<<"]="<<dp[cur][k][idx]<<'\n';
            // cout<<"dp["<<!cur<<"]["<<k<<"]["<<idx<<"]="<<dp[!cur][k][idx]<<'\n';
        }
    }
    cout<<max(dp[0][w][arr.size()-1],dp[1][w][arr.size()-1]);
    return 0;
}

/*
    2 1 1 2 2 1 1//그냥 배열
    1 2   2   2 //연속된거 개수배열
    //시간마다 바꿀이유는 절대 X 먹을수있으면 먹어야지
    //분기점마다 바꿀지말지 생각해보자
    1:4         //1전체 개수
    2:3         //2전체 개수
[나무인지 자두인지][몇번바꿨는지][몇번째분기점인지];

*/