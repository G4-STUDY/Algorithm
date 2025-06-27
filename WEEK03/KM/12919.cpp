#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int si[50];//A=0 B=1
int ti[50];
int cnt;
bool flag=false;
/*

*/
void calc(int idx){//가지치기 할방법은 없는건가..?
    if(idx==cnt){
        bool can=true;
        for(int i=0;i<cnt;i++){
            if(ti[i]!=si[i])can=false;
        }
        if(can)flag=true;
        return;
    }
    if(ti[0]==1){//처음이 B면 뒤집어졌을수있어
       reverse(ti,ti+idx); 
       calc(idx-1);
       reverse(ti,ti+idx);
    }
    if(ti[idx-1]==0){//끝이 A면 그냥 추가된걸수도 잇어
        calc(idx-1);
    }
}

int main()
{
    string s,t;
    cin>>s;
    cin>>t;
    cnt=s.size();
    for(int i=0;i<=cnt;i++){
        if(s[i]=='B')si[i]=1;
    }
    for(int i=0;i<t.size();i++){
        if(t[i]=='B')ti[i]=1;
    }
    calc(t.size());
    if(flag)cout<<1;
    else cout<<0;
    return 0;
}