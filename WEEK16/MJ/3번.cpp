#include <algorithm>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector <int> adj[30];

int vis[30];
int val[30];

stack <int> s;

string solution(vector<string> statement){
    string result;
    for (int u = 0; u < statement.size(); u++) {
        adj[statement[u][0]-65].push_back(statement[u][1]-65);
    }


    // int vis[30] = {0};
    // vis[0] = 1;
    // s.push(0);
    // while(!s.empty()) {
    //     int cur = s.top();
    //     s.pop();
    //     for (auto nxt : adj[cur]){
    //         if (vis[nxt] == 1) {
                
    //         }
    //     }
    // }
    
    return result;
}

int main(){
    vector <string> a = {"AB", "BC", "CA"};
    solution(a);
    for (int u = 0; u < 30; u++) cout << val[u] << ' ';
    return 0;
}
