#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int len = stones.size();
    int continuous = 0;
    bool prev_is_zero = false;
    bool flag = true;
    
    while(flag == true)
    {
        prev_is_zero = false;
        continuous = 0;
        
        for(int i = 0; i < len; i++)
        {
            if(stones[i] == 0)
            {
                
                if(prev_is_zero = true)
                {
                    continuous++;
                    if(continuous == k)
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {
                    continuous = 1;
                    prev_is_zero = true;
                }
            }
            else
            {
                stones[i]--;
                prev_is_zero = false;
                continuous = 0;
            }
        }
        if(flag == true) answer++;
        
    }
    return answer;
}
