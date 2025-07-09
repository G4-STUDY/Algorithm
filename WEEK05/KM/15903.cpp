#include <iostream>
#include <queue>

using namespace std;

int n,m;
long long ans;
priority_queue<long long,
vector<long long>,
greater<long long>
>pq;

int main()
{
    cin>>n>>m;
    long long tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        pq.push(tmp);
    }
    for(int i=0;i<m;i++)
    {
        //가장작은수 두개 뽑아서 합치고 넣기
        tmp=pq.top();
        pq.pop();
        tmp+=pq.top();
        pq.pop();
        pq.push(tmp);
        pq.push(tmp);
    }
    ans=0;
    while (!pq.empty())
    {
        ans+=pq.top();
        pq.pop();
    }
    cout<<ans<<'\n';
    return 0;
}


/*
a b c d e f g
a+b a+b c d e f g = 2*a+2*b+c+d+e+f+g
가장 작은수 두개를 더해야한다


*/