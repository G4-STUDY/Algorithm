#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool nbit[21];
bool ans[21];
bool changeflag=false;
int one;
int mxidx;
void n_to_bit(int n){
    for(int i=0;i<20;i++){
        if(n&1){one++;mxidx=max(mxidx,i);}
        nbit[i]=n&1;
        n=n>>1;
    }
}
int bit_to_n(){
    int sum=0;
    for(int i=0;i<20;i++){
        if(ans[i])
        sum+=pow(2,i);
    }
    return sum;
}

void print(){
    for(int i=mxidx;i>=0;i--){
        cout<<ans[i];
    }
    cout<<'\n';
}

int solution(int n) {
    mxidx=-1;
    int answer = 0;
    one=0;
    int minusone=0;
    n_to_bit(n);
    bool flag=false;
    int idx;
    for(idx=0;idx<=mxidx;idx++){
        if(nbit[idx]==1){
            flag=true;
        }
        if(nbit[idx]==0){
            if(flag){
                changeflag=true;
                break;
            }
        }
    }
    //거꾸로 뒤에서부터 찾으셈
    //flag=1앞에0
    if(changeflag){
        //cout<<idx<<"!\n";
        for(int i=mxidx;i>idx;i--){
            if(nbit[i])minusone++;
            ans[i]=nbit[i];
        }
        ans[idx-1]=0;
        ans[idx]=1;
        minusone++;
        idx=0;
        while(one-minusone>0){
            ans[idx++]=1;
            minusone++;
        }
    }
    else{
        mxidx+=1;
        ans[mxidx]=1;
        one-=1;
        idx=0;
        for(int i=0;i<mxidx;i++){
            ans[i]=0;
        }
        while(one--){
            ans[idx++]=1;
        }
    }
    //print();
    answer=bit_to_n();
    return answer;
}
/*

 1101
 1110
10011
0보다 뒤에있는 1이 있으면 해결가능
^^이게 여러개면
!!!제일 뒤에껄로 해야지
그럼 1앞에 0이 있으면으로 바꾸자
없으면 
한자리 올리고 맨뒤서부터 1채우기
110000
*/

/*
다른사람 풀이
#include <string>
#include <vector>

using namespace std;

int tobin(int num) {
    int cnt=0;
    while(num>0) {
        if(num%2==1) cnt++;
        num/=2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;

    int cnt=tobin(n);

    while(true) {
        if(cnt==tobin(++n)) {
            return n;
        }
    }
}





*/