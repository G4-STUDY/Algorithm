#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int Mx = 200000000;
int n;
int arr[1001];
pair<int, int> minusarr[1000001]; // 뭘뺏는지는 기록하자
int sum[1000001];                 // 더한값<x1,x2>
int midx = 0;
int sidx = 0;
// U의 원소는 200,000,000보다 작거나 같은 자연수이다.
// nC2 n*(n-1) /2
int ans = 0;
void combsum(int ex, bool two)
{
    for (int i = 0; i < n; i++)
    {
        if (two)
        {
            // 3번째 자연수까지 더하면 MX랑 같아지거나 작아지니까
            if (Mx > (long long)arr[ex] + (long long)arr[i])
            {
            }
            sum[sidx++] = arr[ex] + arr[i];
        }
        else
        {
            combsum(i, true);
        }
    }
}

void combminus(int ex, bool two)
{
    for (int i = 0; i < n; i++)
    {
        if (two)
        {
            minusarr[midx++] = {arr[ex] - arr[i], arr[i]};
        }
        else
        {
            combminus(i, true);
        }
    }
}
// x, y, z, k가 서로 같아도 된다. ㄱ-;
//  bool combcheck(int x1,int x2,int x3,int x4){
//      unordered_map<int,bool> m;
//      if(m[x1]){
//         return false;
//      }
//      m[x1]=true;
//      if(m[x2]){
//         return false;
//      }
//      m[x2]=true;
//      if(m[x3]){
//         return false;
//      }
//      m[x3]=true;
//      if(m[x4]){
//         return false;
//      }
//      return true;
//  }

/*
1000000 * log(1000000) 가능
*/
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    combminus(-1, false);
    combsum(-1, false);
    sort(sum, sum + sidx);
    sort(minusarr, minusarr + midx);
    int l;
    int r;
    int mid;
    // for(int i=0;i<sidx;i++){
    //     cout<<sum[i]<<' ';
    // }cout<<'\n';
    // for(int i=0;i<midx;i++){
    //     cout<<minusarr[i].first<<' ';
    // }cout<<'\n';
    for (int i = 0; i < sidx; i++)
    {
        int l = 0;
        int r = midx - 1;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (minusarr[mid].first >= sum[i])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (minusarr[l].first == sum[i])
        {
            // 똑같은거 썻는지 검사
            // cout<<minusarr[l].first<<" "<<sum[i].first<<'='<<minusarr[l].second.first<<'-'<<minusarr[l].second.second<<"+"<<sum[i].second.first<<"+"<<sum[i].second.second<<'\n';
            // if(combcheck(minusarr[l].second.first,minusarr[l].second.second,sum[i].second.first,sum[i].second.second))
            ans = max(ans, sum[i] + minusarr[l].second);
        }
    }
    cout << ans;
    return 0;
}
/*
a b c d e f

ab cd ef ac ad ae..

2개 더하기
찾을거 n
    더한거+그냥
    n^2 * n
n^2*n=

1 2 3 4 5 .....(n-1) n

n - 1, n - 2 n - 3 .... = 1+2 1+3 1+4 ...1+(n-1)

n^2 = n^2
n^2 log n 으로 찾기
될거같은데
같은거 고른경우는 어떻게 하지

*/