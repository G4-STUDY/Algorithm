#include <iostream>

using namespace std;

int p[100001];
int n, m;
bool flag = true;
int answer = 0;
int find(int x)
{
    if (x == p[x])
        return x;
    return p[x] = find(p[x]);
}

void myunion(int a, int b)
{
    if (b < a)
        swap(a, b);
    p[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m; // n==g,m==p;
    for (int i = 0; i <= n; i++)
        p[i] = i;
    while (m--)
    {
        int x;
        cin >> x;
        if (flag)//공항운영중
        {
            x = find(x);//1~x 중에 비어있는 제일큰값
            if (x == 0)//0번이 비어있다 = 1~x까지 전부 차있다.
            {
                //공항폐쇄
                flag = false;
            }
            else
            {   //x는 채웠으니까 다음에 x가불리면 x-1에 넣어야하니까
                //union(x,x-1)
                int tmp=find(x-1);
                myunion(tmp,x);
                answer++;
            }
        }
    }
    cout<<answer;
    return 0;
}
/*
들어올때마다 x보다 작은값 돌면서 가능한곳 찾기
100000 * 100000 시간초과
---
x 보다 작은값중 비어있는값을 저장하고 있어야됌
union find로 x, x-1 해야되나 다차있으면 0이나오겠지


*/