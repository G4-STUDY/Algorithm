#include<iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
vector<string> statement;
unordered_map<char,int> mp;
queue<string> q;

bool check(int idx) {
    for(int i=0;i<statement.size(); i++){ // 100000
        if(i==idx) continue;
        if(mp.find(statement[i][0])==mp.end()){
            mp.insert({statement[i][0],0});
        }

        if(mp.find(statement[i][1])==mp.end()){
            mp.insert({statement[i][0],1});
        } else {
            mp[statement[i][1]]++;
        }
    }

    for(string stat : statement){ 
        if(mp[stat[0]] == 0) q.push(stat);
    }

    bool flag = false;

    while(!q.empty()){
        if(!flag) {
            while(!q.empty()) q.pop();
            return false;
        }

        string qfront = q.front();
        q.pop();

        mp[qfront[1]]--;

        flag = false;

        for(string stat : statement){
            if(mp[stat[0]] == 0){
                flag = true;
                q.push(stat);
            }
        } 
    }
    return true;
}

string solution(vector<string> e_statement)
{
    statement = e_statement;
    for(int i=0;i<e_statement.size(); i++){ // 100000
        if(!check(i)) return e_statement[i];
    }
    
    return "";
    
    
}

int main() {
    printf("Hello world!\n");
    return 0;
}