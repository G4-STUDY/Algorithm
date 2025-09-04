#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int binarySearch(int st, int en, int target,const vector<int>& weights );
    
long long solution(vector<int> weights) {
    long long answer = 0;
    
    sort(weights.begin(), weights.end());
    for(int i = 0; i < weights.size() - 1; i++) 
    {
        int cur_weight = weights[i];
        auto upper_it;
        auto lower_it;
            
        if(cur_weight % 3 == 0)
        {
            
            int target = (cur_weight / 3) * 4;
            upper_it = upper_bound(weights.begin() + i + 1, weights.end(), target);
            lower_it = lower_bound(weights.begin() + i + 1, weights.end(), target);
            answer += upper_it - lower_it;
        }
        
        if(cur_weight % 2 == 0)
        {
            int target = (cur_weight / 2) * 3;
            upper_it = upper_bound(weights.begin() + i + 1, weights.end(), target);
            lower_it = lower_bound(weights.begin() + i + 1, weights.end(), target);
            answer += upper_it - lower_it;
        }
        
       
        upper_it = upper_bound(weights.begin() + i + 1, weights.end(), cur_weight);
        lower_it = lower_bound(weights.begin() + i + 1, weights.end(), cur_weight);
        answer += upper_it - lower_it;
        
        
        
        upper_it = upper_bound(weights.begin() + i + 1, weights.end(), cur_weight * 2);
        lower_it = lower_bound(weights.begin() + i + 1, weights.end(), cur_weight * 2);
        answer += upper_it - lower_it;
        
        
    }
  
    return answer;
}
 


    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
