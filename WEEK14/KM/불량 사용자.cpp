#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> edge[8];
bool visit[8];
map<vector<int>,bool> m;
int bsize;
int usize;

void comb(int cur){
    if(cur==bsize)
    {
        vector<int> v;
        for(int i=0;i<usize;i++)
        {
            if(visit[i])v.push_back(i);
        }
        m[v]=true;
        return;
    }
    for(int next:edge[cur]){
        if(visit[next])continue;
        visit[next]=true;
        comb(cur+1);
        visit[next]=false;
    }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    bsize=banned_id.size();
    usize=user_id.size();
    for(int i=0;i<banned_id.size();i++){ //8
        string bid=banned_id[i];
        for(int j=0;j<user_id.size();j++){ //8
            string uid=user_id[j];
            if(bid.size()!=uid.size())continue;
            bool flag=true;
            for(int k=0;k<uid.size();k++){ //8
                 if(bid[k]=='*'||bid[k]==uid[k])continue;
                 flag=false;
                 break;
            }
            if(flag){//bid가 uid가 될수있으면
                edge[i].push_back(j);
            }
        }
    }
    //조합
    comb(0);
    answer=m.size();
    return answer;
}
/*
ban_id조합찾기
8 8 8
*/