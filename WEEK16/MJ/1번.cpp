#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

queue <int> q_Sang; // 상반부 카드
queue <int> q_Hooo; // 후반부 카드

vector<int> solution(vector<int> cards, int n, vector<string> command){
    vector <int> result;
    int nn = n / 2;
    for (int u = 1; u <= nn; u++) q_Sang.push(cards[u-1]);
    for (int u = nn + 1; u <= n; u++) q_Hooo.push(cards[u-1]);

    for (int u = 0; u < command.size(); u++) {
        if (command[u] == "flip"){
            vector <int> temp;
            for (int v = 1; v <= nn; v++) {
                temp.push_back(q_Hooo.front());
                q_Hooo.pop();
            }
            for (int v = nn + 1; v <= n; v++) {
                temp.push_back(q_Sang.front());
                q_Sang.pop();
            }
    
            for (int v = 1; v <= nn; v++) q_Sang.push(temp[v-1]);
            for (int v = nn + 1; v <= n; v++) q_Hooo.push(temp[v-1]);       
        }
        else {
            vector <int> temp;
            for (int v = 1; v <= nn; v++) {
                temp.push_back(q_Sang.front());
                q_Sang.pop();
                temp.push_back(q_Hooo.front());
                q_Hooo.pop();
            }
            
            for (int v = 1; v <= nn; v++) q_Sang.push(temp[v-1]);
            for (int v = nn + 1; v <= n; v++) q_Hooo.push(temp[v-1]);                 
        }
    }
  
    // 상반부에 후반부 더해서 result 구하기
    while (!q_Sang.empty()) {
        result.push_back(q_Sang.front());
        q_Sang.pop();
    }
    while (!q_Hooo.empty()) {
        result.push_back(q_Hooo.front());
        q_Hooo.pop();
    }
    for (int u = 0; u < result.size(); u++) cout << result[u] << ' ';
    return result;
}
