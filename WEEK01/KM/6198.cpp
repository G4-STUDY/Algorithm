#include <iostream>
#include <stack>

using namespace std;

int n;
long long ans=0;
stack<int> s;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(s.empty()){
            s.push(x);
        }
        else{
            while(!s.empty()&&s.top()<=x) //나보다 작은거 다빼
            {
                s.pop();
            }
            ans+=s.size();// 스택에 있는것들은 나를 볼수있는것들
            s.push(x);//스택에 나넣기기
        }
    }
    cout<<ans;
    return 0;
}
/*
10 3 7 4 12 2
   1 1 2 0  1

 
5   1
1   
4   1
1   2
3   2
1   3
2   3
1   4
1   4
1   4

9 0 7 0 5 0 3 0 0

10 3 7 4 12 2
0  1 2 3 4  5


10 0
3 1

7 2

sum+=2-1-1;
*/