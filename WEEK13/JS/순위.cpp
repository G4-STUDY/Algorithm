#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int v[101][101] = { 0 }; //v[i][j] == 1이면, i에서 j로 가는 경로 존재
    for(int i = 1; i <= n; i++)
    {
        v[i][i] = 1;
    }
    
    for(vector result : results)
    {
        int st = result[0];
        int en = result[1];
        v[st][en] = 1;
    }
    //플로이드 
    for(int mid = 1; mid <= n; mid++)
        for(int st = 1; st <= n; st++)
            for(int en = 1; en <= n; en++)
            {
               if(v[st][mid] == 1 && v[mid][en] == 1)
               {
                   v[st][en] = 1;
               }
            }
    
    for(int i = 1; i <= n; i++)
    {
        //1.내가 갈 수 있는 노드 수 
        int can_visit = -1;  //자기 자신 항상 포함 -> 제외
        for(int j = 1; j <= n; j++)
        {
            if(v[i][j] == 1) can_visit++;
        }
         //2.나를 방문할 수 있는 노드 수
        int can_be_visited = -1; 
        for(int j = 1; j <= n; j++)
        {
            if(v[j][i] == 1) can_be_visited++;
        }
            
        if(can_visit + can_be_visited == n - 1) answer++; //자신 제외한 모든 노드에 대해 방문or 방문당하면 포함
    }
    
    return answer;
}