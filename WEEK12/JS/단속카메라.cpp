#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> routes) {
    int cctv_num = 0;
    int min_end = -30001;
    
    priority_queue< pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>>> pq;
    
    for(vector<int> route : routes)
    {
        pq.push({route[0], route[1]});
    }
    
    
    
    while(!pq.empty())
    {
        pair<int, int> cur = pq.top(); pq.pop();
        int cur_st = cur.first; int cur_end = cur.second;
        if(min_end < cur_st)
        {
            //cctv 추가, min_end 갱신
            cctv_num++;
            min_end = cur_end;
        }
        else
        {
            if(min_end > cur_end)
            {
                //cctv 추가 x, min_end 만 갱신
                min_end = cur_end;
            }
        }
    }
    
    return cctv_num;
}