#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<string> statement = 
//{"AB","BC","CA"}
//{"DA","AB","BC","CD","CE","ED"}
//{"AB","BC","CA","CB"}
{"XA","AB","BY","XC","CY","YX"}
;
string answer;

vector<int> edge[26];
bool flag;
int cost[26];
int tmp[26];

int main()
{
    for(string state:statement){
        int a=state[0]-'A';
        int b=state[1]-'A';
        edge[a].push_back(b);
        cost[b]++;
        queue<int> q;
        for(int i=0;i<26;i++){
            tmp[i]=cost[i];
            if(tmp[i]==0)q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int cur=q.front();q.pop();
            cnt++;
            for(int next:edge[cur]){
                if(tmp[next]==1){
                    tmp[next]--;
                    q.push(next);
                }
            }
        }
        if(cnt!=26){
            reverse(state.begin(),state.end());
            answer=state;
            break;
        }
    }

    cout<<answer;
    return 0;
}

/*
C->A->B
C->B : BC도 진실이 뒤집으면 진실인데?
CA,AB,BC(거짓)

A->B->C
AB,BC,CA(거짓)

B->C->A
BC,CA,AB(거짓)

문제1:처음 나온게 거짓이 거짓이다
ㄴ싸이클탐지
ㄴㄴ단방향:위상정렬로 처리

{"XA","AB","BY","XC","CY","YX"}

X->A->B->Y
->C
*/