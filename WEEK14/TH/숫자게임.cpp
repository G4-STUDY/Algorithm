#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    
    priority_queue<int,vector<int>,greater<>> pqa;
    priority_queue<int,vector<int>,greater<>> pqb;
    
    for(int i : A) pqa.push(i);
    for(int i : B) pqb.push(i);
    
    int answer = 0;
    
    // 
    
    while(!pqb.empty() && !pqa.empty()){
        
        int cur_a = pqa.top();
        int cur_b = pqb.top();
        
        if(cur_a < cur_b) { // a
            answer++;
            pqa.pop();
            pqb.pop();
            continue;
        }
        
        pqb.pop();
    }
    
    
    return answer;
}