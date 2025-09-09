#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

vector<int> edge[53];
int dist[53];
int n;

void bfs(){
    for(int i=1;i<=n;i++){
        dist[i]=-1;
    }
    queue<int> q;
    dist[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int cur=q.front();q.pop();
        cout<<cur<<':';
        for(int next:edge[cur])
        {
            if(dist[next]!=-1)continue;
            dist[next]=dist[cur]+1;
            q.push(next);
            cout<<next<<',';
        }
        cout<<"\n";
    }
}

bool canedge(string a,string b){
    int cnt=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])cnt++;
    }
    if(cnt==1)return true;
    return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    /*
        edge정리
    */
    n=words.size()+2;
    int tidx=-1;
    for(int i=0;i<words.size();i++)
    {
        if(target==words[i])
            tidx=i+2;
    }
    if(tidx==-1)return 0;
    if(canedge(begin,target)){
        return 1;
    }
    for(int i=0;i<words.size();i++)//시작지점 정리
    {
        if(canedge(begin,words[i]))
        {
            cout<<begin<<','<<words[i]<<'\n';
            edge[1].push_back(i+2);
            edge[i+2].push_back(1);
        }
    }
    for(int i=0;i<words.size();i++)
    {
        for(int j=0;j<words.size();j++){
            if(i==j) continue;
            if(canedge(words[i],words[j]))
            {
                edge[i+2].push_back(j+2);
                edge[j+2].push_back(i+2);
            }
        }
    }
    bfs();
    answer=dist[tidx];
    return answer;
}
/*
그래프처럼 생각하면 되겟네
단어 1개차이면 간선만들고 탐색하면서 dist갱신
*/



//옛날코드
// #include <string>
// #include <vector>
// #include <string.h>
// using namespace std;
// int check[50];
// int answer;
// void dfs(string word,string target,int check[],vector<string> words,int cnt){
//     int cant=0;
//     for(int j=0;j<word.size();j++){
//         if(target[j]!=word[j])
//             cant++;
//         }
//     if(cant==1){
//         if(answer>cnt+1){
//             answer=cnt+1;
//         }
//         return;
//     }
//     for(int i=0;i<words.size();i++){
//         if(check[i]==0){
//             int can=0;
//             for(int j=0;j<word.size();j++){
//                 if(words[i][j]!=word[j])
//                     can++;
//             }
//             if(can==1){
//                 check[i]=1;
//                 dfs(words[i],target,check,words,cnt+1);
//                 check[i]=0;
//             }
//         }
//     }
//     return;
// }

// int solution(string begin, string target, vector<string> words) {
//     answer=51;
//     memset(check,0,sizeof(check));
//     int no=0;
//     for(int i=0;i<words.size();i++){
//         if(words[i]==target){
//             no=1;
//         }
//     }
//     if(no==0){
//         return 0;
//     }
//     dfs(begin,target,check,words,0);
//     return answer;
// }