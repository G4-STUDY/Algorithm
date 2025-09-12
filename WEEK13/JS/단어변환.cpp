#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
bool isAdj(string s1, string s2)
{
    int word_size = s1.size();
    int num = 0;
    bool flag = false;
    
    for(int i = 0; i < word_size; i++)
    {
        if(s1[i] != s2[i] ) num++;
    }
    
    if(num == 1) flag = true;
    
    return flag;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int word_size = words[0].size();
    //1. 그래프 생성
    vector<int> adj[53]; //그래프 
    words.push_back(begin);
    int num = words.size();
    for(int i = 0; i < num - 1; i++)
    {
        for(int j = i + 1; j < num; j++)
        {
            if(isAdj(words[i], words[j]))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    //2. begin 노드 시작점으로 bfs 
    int begin_idx = words.size() - 1;
    int vis[53] = { 0 };
    queue<int> q;
    q.push(begin_idx);
    vis[begin_idx] = 1;
    int dist = 0;
    bool flag = false;
    while(!q.empty())
    {
        int qsize = q.size();
        for(int i = 0; i < qsize; i++)
        {
            int cur_idx = q.front(); q.pop();
            string cur_str = words[cur_idx];
            for(int nxt_idx : adj[cur_idx])
            {
                if(vis[nxt_idx] == 1) continue;
                string nxt_str = words[nxt_idx];
                if(nxt_str == target)
                {
                    flag = true;
                    break;
                } 
                q.push(nxt_idx);
                vis[nxt_idx] = 1;
                std::cout << words[nxt_idx] << ',';
            }
            if(flag == true) break;
        }
        dist++;
        if(flag == true) break;
    }
    
    if(flag == false) answer = 0;
    else answer = dist;
    
    return answer;
}