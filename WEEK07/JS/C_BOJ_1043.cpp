#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M; //사람 1~N ,파티 1~M
    int number; //최초로 진실아는 사람 수
    vector<int> first_know_pepole;
    cin >> number;
    for(int i = 0; i < number; i++)
    {
        int know_people;
        cin >> know_people;
        first_know_pepole.push_back(know_people);
    }
    //그래프 만들기 
    vector<int> adj[51];
    vector<int> parties[51];
    for(int i = 1; i <= M; i++)
    {
        int number; //현재 파티 파티원 수 ( >= 1)
        cin >> number;
        int prev_member;
        cin >> prev_member;
        parties[i].push_back(prev_member);
        for(int j = 0; j < number - 1; j++)
        {
            int cur_member;
            cin >> cur_member;
            parties[i].push_back(cur_member);
            adj[prev_member].push_back(cur_member);
            adj[cur_member].push_back(prev_member);
            prev_member = cur_member;
        }
    }
    //진실아는 사람 확인, know_people 벡터에 저장 
    int vis[51] = { 0, };
    vector<int> know_people;
    for(int i : first_know_pepole)
    {
        
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        know_people.push_back(i);
        while(!q.empty())
        {
            int cur = q.front(); q.pop();
            for(int nxt : adj[cur])
            {
                if(vis[nxt] == 1) continue;
                q.push(nxt);
                vis[nxt] = 1;
                know_people.push_back(nxt);

            }
        }
    }
    //전체 파티 중 가능한 파티 세기
    sort(know_people.begin(), know_people.end());
    int result = 0;
    for(int i = 1; i <= M; i++)
    {
        bool flag = true;
        for(int member : parties[i])
        {
            if(binary_search(know_people.begin(), know_people.end(), member))
            {
                flag = false;
                break;
            }
        }
        if(flag == true) result++;
    }

    cout << result;
    return 0;

}
