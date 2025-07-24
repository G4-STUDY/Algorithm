#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans = 0;
int n, c;
int arr[31];
int l, r;
vector<int> leftarr;
vector<int> rightarr;

void lcomb(int cur, int idx) //왼쪽 조합
{
    if (idx == l)
    {
        leftarr.push_back(cur);
        return;
    }
    lcomb(cur, idx + 1); // 안넣기
    if (cur + arr[idx] <= c)
        lcomb(cur + arr[idx], idx + 1); // 넣기
}
void rcomb(int cur, int idx) //오른쪽 조합
{
    if (idx == r)
    {
        rightarr.push_back(cur);
        return;
    }
    rcomb(cur, idx + 1); // 안넣기
    if (cur + arr[idx] <= c)
        rcomb(cur + arr[idx], idx + 1); // 넣기
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n == 1)
    {
        ans += 1;   //안 넣는경우
        if (arr[0] <= c)
        { // (c만큼) 같은경우도 넣을수있음.. 99퍼 반례..
            ans += 1;
        }
    }
    else
    {
        l = n / 2;
        r = n;
        lcomb(0, 0);
        rcomb(0, l);
        sort(rightarr.begin(), rightarr.end());
        int mid;
        for (int left : leftarr)
        {
            l = 0;
            r = rightarr.size();

            while (l < r)
            { // upperbound구하기 그거보다 작은건 다 되는거니까
                mid = (l + r) / 2;
                if (rightarr[mid] > c - left)
                {
                    r = mid;
                }
                else
                { // 되는경우
                    l = mid + 1;
                }
            }
            if (l == 0)
                break;
            else
            {
                ans += l;
            }
        }
    }
    cout << ans;
    return 0;
}

/*
다 안넣는경우도 세야됌
10 0000 0000 넘어가면 안찾아도됌
n=30;
모든 경우의수는 2^30승
10 7374 1824
연산 10억번 시간초과
이분탐색?
모두 구하고 이분탐색? 모두구하는데 이미 10억번
반씩 나누면 15 15
2^15= 32000
32000*32000=2^30 의미없음
하나 구하고 하나는 이분탐색
32000*log(2^15)=2^15 *15 가능
2^15*log(2^15)=32000*15
절반으로 나누는게 더빠른가?
a :b  2^a+2^b+2^a*b= 2^a*(b+1)+2^b
b=n-a

2^a*(30-a+1)+2^(n-a)
2^(30-a)+2^a*(31-a)
a
12일때  256000+4000*19=339968
13일때  128000+8000*18=272000
14일때  64000+16000*17=336000
15      32000+32000*16=544000
16   16000+64000*15=
13일때 가장작은거같음
근데 어처피 n 범위는 1부터 30까진데;;
그냥 15로 하자..

예
000000000000000//아무것도 안넣은경우
111111111111111//다넣은경우]
비트마스킹?이었나
그걸로 표시해보자
99퍼 틀렸습니다
*/