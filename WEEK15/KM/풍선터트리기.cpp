#include <string>
#include <vector>

using namespace std;

int mleft[1000001];
int mright[1000001];

int solution(vector<int> a) {
    int answer = 2;
    int mn=1e9;
    for(int i=0;i<a.size();i++){//자기보다 왼쪽가장 작은값
        mn=min(mn,a[i]);
        mleft[i]=mn;
    }
    mn=1e9;
    for(int i=a.size()-1;i>=0;i--){//자기보다 오른쪽가장 작은값
        mn=min(mn,a[i]);
        mright[i]=mn;
    }
    //처음꺼는 무조건 성공하네
    //중간
    for(int i=1;i<a.size()-1;i++){
        int l=i-1,r=i+1;
        if(mleft[l]<a[i]&&mright[r]<a[i])continue;
        answer++;
    }
    //마지막꺼도 무조건 성공하네
    return answer;
}

/*
n 100만
n log n 
모든수는 전부 다르다

자기기준 왼쪽에서 남는건 가장작은게 남겠지?
자기기준 오른쪽에서도 남는건 가장 작은게 남겠지?
둘다 자기보다 작으면 못부숨

*/