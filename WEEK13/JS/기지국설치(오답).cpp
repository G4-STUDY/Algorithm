#include <iostream>
#include <vector>
using namespace std;

void buildStation(int cur, int w, int n, vector<int>& visit)
{
    int st, en;
    
    if(cur - w < 1) st = 1;
    else st = cur - w;
    
    if(cur + w > n) en = n;
    else en = cur + w;
    
    for(int i = st; i <= en; i++)
    {
        visit[i] = 1;
    }
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    vector<int> visit(n + 1, 0); // 1 ~ 
    //initial setting; 4g 기지국->5g 기지국, visit에 볼수있는 아파트 표시 
    for(int station : stnations)
    {
        buildStation(station, w, n, visit);
    }
    //greedy logic 
    int continuous_zero = 0;
    int i = 1;

    while(i <= n)
    {
        if(visit[i] == 1)
        {
            if(continuous_zero == 0)
            {
                i++;
                continue;
            }
            else  //continuous_zero > 0
            {
                buildStation(i - 1, w, n, visit);
                answer++; //이전 아파트 기지국 설치 
                continuous_zero = 0;
                i = i + w;
            }
        }
        else // visit[i] == 0
        {
            if(continuous_zero == w)
            {
                buildStation(i, w, n, visit);
                answer++; //현재 아파트 기지국 설치 
                continuous_zero = 0;
                i = i + w + 1;
            }
            else //continuous_zero < w 
            {
                continuous_zero++;
                i++;
            }
        }
    }
    

    return answer;
}