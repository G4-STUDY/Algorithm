#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> arr;


int dist(int n){
    int res=0;
    int cnt=0;
    for(int i=0;i<arr.size();i++){
        //cout<<arr[i]-n<<' ';
        if(arr[i]-n>0){
            res=max(cnt,res);
            cnt=0;
        }
        else{
            cnt++;
        }
    }
    res=max(cnt,res);
    return res+1;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    arr=stones;
    int l=0;
    int r=0;
    for(int x:stones){
        r=max(r,x);
    }
    r+1;
    //upperbound
    while(l<r){
        int mid=(l+r)/2;
        int result=dist(mid);
        //cout<<'!'<<mid<<'?'<<result<<'\n';
        //k만족하는지 검사
        if(result<=k){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    answer=r;
    return answer;
}

/*
이분탐색 무조건인데..
log(2억)*20만해야됌
되겠네
28*20만 수준이니까 ㅇㅇ..

*/