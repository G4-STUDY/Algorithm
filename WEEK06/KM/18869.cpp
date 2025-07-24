// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// int m,n;
// /*
// pair<int,int> pq로 바꿔서 뒤에 원래 인덱스 저장해놓자
// */
// priority_queue<pair<int,int>,
// vector<pair<int,int>>,
// greater<pair<int,int>>>pq;
// vector<int> arr[101];
// int numsize[101];
// bool visit[101];
// int ans;
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cin>>m>>n;
//     int pre,num,tmp;
//     ans=0;
//     pair<int,int> x;
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++)
//         {
//             cin>>tmp;
//             x.first=tmp;
//             x.second=j;
//             pq.push(x);
//         }
//         num=0;
//         pre=-1;
//         while(!pq.empty()){
//             x=pq.top();
//             if(x.first==pre){
//             }
//             else{
//                 num++;
//             }
//             pq.pop();
//             pre=x.first;
//             arr[i].resize(n);
//             arr[i][x.second]=num;
//         }
//         numsize[i]=num;
//     }
//     int spacenum;
//     bool flag,same;
//     for(int i=0;i<m;i++){
//         flag=false;
//         if(visit[i]) continue;
//         spacenum=1;
//         visit[i]=true;
//         same=false;
//         for(int j=0;j<m;j++){
//             if(visit[j]) continue;
//             if(numsize[i]!=numsize[j]) continue;
//             same=true;
//             for(int k=0;k<n;k++){
//                 if(arr[i][k]!=arr[j][k]){
//                     same=false;
//                     break;
//                 }
//             }
//             if(same){
//                 flag=true;
//                 visit[j]=true;
//                 spacenum++;
//             }
//         }
//         if(flag){
//             ans+=(spacenum*(spacenum-1))/2;//spacenum C 2
//         }
//     }
//     cout<<ans;
//     return 0;
// }
/*
싹다 1,2,3,4처럼 바꿔서
묶어서 비교하자
?? 왜 이분탐색이지
시간은 어케줄일까
num 값 저장해놨다가 num값 같은거끼리 비교해보자
우주 쌍? 조합을 처리해야되나?
*/

// map 활용
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int m, n;
priority_queue<pair<int, int>,
               vector<pair<int, int>>,
               greater<pair<int, int>>>
    pq;
vector<int> arr[101];
map<vector<int>, int> cnt;
int numsize[101];
bool visit[101];
int ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    int pre, num, tmp;
    ans = 0;
    pair<int, int> x;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            x.first = tmp;
            x.second = j;
            pq.push(x);
        }
        num = 0;
        pre = -1;
        while (!pq.empty())
        {
            x = pq.top();
            if (x.first == pre)
            {
            }
            else
            {
                num++;
            }
            pq.pop();
            pre = x.first;
            arr[i].resize(n);
            arr[i][x.second] = num;
        }
        numsize[i] = num;
        cnt[arr[i]]++;//같은 조합의 수
    }
    for (auto it : cnt)
    {
        ans += ((it.second) * (it.second - 1)) / 2; //N C 2
    }
    cout << ans;
    return 0;
}