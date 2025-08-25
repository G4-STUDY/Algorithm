#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;

int n;
int arr[100001];

int siso(int i,int lw,int rw){
    int result=0;
    int findweight=arr[i]*lw;
    int l=i+1;
    int r=n;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(findweight>arr[mid]*rw){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    int findl=l;
    l=i+1;
    r=n;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(arr[mid]*rw<=findweight){ 
            
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    result=r-findl;
    return result;
}

long long solution(vector<int> weights) {
   long long answer = 0;
    sort(weights.begin(),weights.end());
    n=weights.size();
    for(int i=0;i<n;i++){
        arr[i]=weights[i];
    }
    for(int i = 0; i < n-1; i++){
        answer+=siso(i,1,1);//같은경우
        answer+=siso(i,4,3);
        answer+=siso(i,4,2);
        answer+=siso(i,3,2);
        
    }
    return answer;
}

/*
n=100,000
n log(n) 안에 해결 ㄱㄱ
이분탐색으로 찾기
//4가지 경우
가벼운사람 무거운사람
==같은곳 앉거나
4         3
4         2
3         2


100 100 180 270 360
*/