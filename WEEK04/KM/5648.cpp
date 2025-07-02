#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//10^12
//1,000,000,000,000 longlong으로
int n;
long long arr[100001];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        arr[i]=stoull(s);
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<'\n';
    }
    return 0;
}