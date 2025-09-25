#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> arr;

int mx=0;
int idx=0;

long long calc(int time){
    long long cnt=arr.size();
    //long long cnt=3 하....
    for(int i=0;i<arr.size();i++){
        cnt+=time/arr[i];
    }
    return cnt;
}

int solution(int n, vector<int> cores) {
    arr=cores;
    int answer = 0;
    if(n<=cores.size()){
        return n;
    }
    int l=0,r=500000001;
    while(l<r){
        int mid=(l+r)/2;
        
        //몇개들어갔는지계산 ㄱㄱ
        long long cnt=calc(mid);
        //lowerbound
        if(cnt<n){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    long long num=calc(l);
    //만약 num이 딱맞으면 그냥 l%arr[i]==0 이 제일큰값
    if(n==num){
        for(int i=0;i<arr.size();i++){
            if(l%arr[i]==0)answer=i;
        }
        return answer+1;
    }
    //num이 더크면 어떻게해 3개 시작해야되는데 2개만하면되면?
    int start=0;//l초에 시작가능한 스레드수
    for(int i=0;i<arr.size();i++){
        if(l%arr[i]==0)start++;
    }
    int find=n-(num-start);//find개만 돌릴거야
    for(int i=0;i<arr.size();i++){
        if(l%arr[i]==0)
        {
            find--;
            if(find==0){
                answer=i;
                break;
            }
        }
    }
    return answer+1;
}