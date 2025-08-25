#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool visit[26];
int maxres[11];
vector<string> result[11];
int num;
vector<string> myorders;


void calc(){
    int cnt=0;
    string course;
    for(string order:myorders){
        bool flag=true;
        for(int i=0;i<26;i++){
            if(visit[i]){
                char alp='A'+i;
                string tmp;
                tmp+=alp;
                if(order.find(tmp)==string::npos){
                    flag=false;
                    break;
                }
            }
        }
        if(flag)cnt++;
    }
    if(cnt<2)return;
    for(int i=0;i<26;i++){
        if(visit[i])
        course+='A'+i;
    }
    if(maxres[num]<=cnt){
        if(maxres[num]<cnt){
            result[num].clear();   
            maxres[num]=cnt;
        }
        result[num].push_back(course);
    }
}

void comb(int cur,int idx){
    if(cur==num){//조합완료 계산 ㄱㄱ
        calc();    
        return;
    }
    for(int i=idx;i<26;i++){
        visit[i]=true;
        comb(cur+1,i+1);
        visit[i]=false;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    myorders=orders;
    for(int n:course){
        num=n;
        memset(visit,false,sizeof(visit));
        comb(0,0);
        for(string cos:result[num]){
            answer.push_back(cos);
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}


/*
1 2 3 4 5 6 7 8 9 10 

*/