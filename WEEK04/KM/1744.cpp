#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 0 1 2 3 4 5 6
// 24 15 39
// 30 12 42
// 무조건 큰순서대로 묶기
// 0 1 2 =3
// 0 (1,2)=2
// 1,0은 절대 묶지마
/*
-일땐 
-끼리 묶어
-값이 홀수개다.
    ㄴ0 이있으면 묶어서 0만들기

1000*1000=1000000 100만
*50= 5000만 int범위 안
*/
int n;
vector<int> pv;//양수담을벡터
vector<int> mv;//마이너스 담을 벡터
int zerocnt;//0은 따로관리
int onecnt;//1도 따로관리
int ans=0;

int main(){
    cin>>n;
    int x;
    zerocnt=0;
    onecnt=0;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x>1){
            pv.push_back(x);
        }
        else if(x==1){
            onecnt++;
        }
        else if(x<0){
            mv.push_back(x);
        }
        else{
            zerocnt++;
        }
    }
    sort(pv.begin(),pv.end(),greater<int>());
    sort(mv.begin(),mv.end());
    int pvsum=0;
    int mvsum=0;
    int idx=0;
    while(idx<pv.size()){
        if(idx+1<pv.size()){
            pvsum+=pv[idx]*pv[idx+1];
        }
        else{
            pvsum+=pv[idx];
        }
        idx+=2;
    }
    idx=0;
    while(idx<mv.size()){
        if(idx+1<mv.size()){
            mvsum+=mv[idx]*mv[idx+1];
        }
        else{
            if(zerocnt==0){
                mvsum+=mv[idx];
            }
        }
        idx+=2;
    }
    
    //cout<<pvsum<<","<<mvsum<<","<<onecnt<<'\n';
    cout<<pvsum+mvsum+onecnt;
    return 0;
}