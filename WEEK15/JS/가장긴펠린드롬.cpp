#include <algorithm>
#include <string>

using namespace std;
int solution(string s)
{
    int max_len = 0;
    int n = s.size();
    //홀수 길이
    for(int mid = 0; mid < n; mid++)
    {
        int len = 1; //디폴트
        int left = mid;
        int right = n - mid - 1;
        int limit = min(left, right);
        
        for(int i = 1; i <= limit; i++)
        {
            if(s[mid - i] == s[mid + i])
            {
                len = len + 2;
            }
            else
            {
                break;
            }
        }
        max_len = max(max_len, len);
    }
    //짝수 길이
    for(int mid_left = 0; mid_left < n - 1; mid_left++)
    {
        int mid_right = mid_left + 1;
        if(s[mid_left] != s[mid_right]) continue;
        int len = 2;
        int left = mid_left;
        int right = n - mid_right - 1;
        int limit = min(left, right);
        for(int i = 1; i <= limit; i++)
        {
            if(s[mid_left - i] == s[mid_right + i])
            {
                len = len + 2;
            }
            else
            {
                break;
            }
        }
        max_len = max(max_len, len);
    }

    return max_len;
}