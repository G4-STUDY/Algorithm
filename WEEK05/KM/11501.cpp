#include <iostream>

using namespace std;

int t,n,mx;
long long sum;
int arr[1000001];
int main()
{
    cin>>t;
    while(t--)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        cin>>n;
        mx=0;sum=0;
        for(int i=0;i<n;i++)    
        {   
            cin>>arr[i];
        }
        mx=arr[n-1];//임시최대값
        for(int i=n-2;i>=0;i--)    
        {   
            if(mx<=arr[i]){//arr[i]가 더크다면
                mx=arr[i];
            }
            else{//작다면 샀어야됌
                sum+=(mx-arr[i]);//차익
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}

/*
100만 ->시간복잡도 n으로..

2 1 2 1 2 3 

1 2 1 2 1 
뒤에서부터 탐색
*/