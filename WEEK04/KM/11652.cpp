#include <iostream>
#include <map>
using namespace std;
// 주어지는수의 범위 -2^62~2^62 long long 
int n;
long long mx;
int mxcnt;
map<long long,int> m;
int main()
{
    mxcnt=0;
    cin>>n;
    long long x;
    int cnt;
    for(int i=0;i<n;i++){
        cin>>x;
        cnt=++m[x];
        if(mxcnt<=cnt){
            if(mxcnt==cnt){
                if(x<mx){
                    mx=x;
                }
            }
            else{
                mx=x;
                mxcnt=cnt;
            }
        }
    }
    cout<<mx;
    return 0;
}