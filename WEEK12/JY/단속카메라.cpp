#include <string>
#include <vector>
#include <queue>


using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

int solution(vector<vector<int>> routes) {
    int answer = 0;

    for(vector<int> route : routes){
        pq.push({route[0], route[1]});
    }

    int cam = pq.top().first;
    pq.pop();

    while(!pq.empty()){
        pair<int, int> cur = pq.top();
        pq.pop();

        if(cur.first <= cam) continue;

        answer+=1;
        cam = cur.second;
    }

    return answer;
}