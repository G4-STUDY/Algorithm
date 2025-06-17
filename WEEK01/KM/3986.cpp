#include <iostream>
#include <stack>
#include <map>
using namespace std;

int n;
string str[101];
stack<int> s;
map<char,int> m;
int ans=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    m['A']=1;   //전처리? 안하는게 더좋음;;
    m['B']=0;   //전처리?
    cin>>n;
    for(int i=0;i<n;i++)    //입력받고고
        cin>>str[i];
    for(int i=0;i<n;i++){
        int len=str[i].length();
        if(len%2==1) continue;
        while(!s.empty())s.pop();
        //cout<<str[i]<<"-";
        for(int idx=0;idx<len;idx++)    //글자하나하나검사
        {
            int cur=m[str[i][idx]]; //전처리(글자하나)
            /*
            if(s.empty()){  //비어있으면 그냥 넣어
                s.push(cur);
            }
            else{
                if(s.top()==cur)    //스택탑에 같은게 들어있으면
                {
                    s.pop();    //빼줘
                }
                else
                {
                    s.push(cur);    //넣어어
                }
            }
            */
           if (!s.empty() &&
                s.top() == cur) {
                s.pop();
            }
            else {
                s.push(cur);
            }
            //cout<<s.size()<<" ";
        }
        if(s.empty()) { //스택이 비어있으면 정답
            //cout<<"Yes\n";
            ans++;
        }
        //else cout<<"No\n";
    }
    cout<<ans;
    return 0;
}