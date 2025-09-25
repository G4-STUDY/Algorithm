#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int size=B.size();
    int l=0;
    for(int x:A){
        while(l<size&&B[l]<=x){
            l++;
        }
        if(l==size)break;
        answer++;
        l++;
    }
    return answer;
}
/*
그냥 정렬하고 하나씩 이기면 되는거 아닌가..?
둘다 정렬하고 A하나씩 돌면서 이길수있는 제일 작은값으로 이기기
        x
        1 3 5 7
        
        2 2 6 8
        l
x한번씩 돌면서 idx=l부터 이길수있는지 검사
*/