#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> q;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {   
        q.push(i);
    }
    while(!q.empty())
    {
        int x=q.front();//제일위에있는거
        q.pop();
        if(!q.empty())//큐가 안비어있다면
        {
            q.push(q.front());//두번째있던거 뒤로 넣기
            q.pop();//두번째꺼 빼기기
        }
        else
        {
            cout<<x;//큐가 비어있으면 마지막거
        }
    }
    return 0;
}