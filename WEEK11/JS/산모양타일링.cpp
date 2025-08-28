#include <string>
#include <vector>
using namespace std;

int dp[100001][2]; // dp[n][0]:오른쪽끝 삼각형 타일 케이스, dp[n][1]: 마름모 케이스 
int solution(int n, vector<int> tops) {
    int answer = 0;
    //첫번째 단위 도형 
    if(tops[0] == 0){  
        dp[1][0] = 2;
        dp[1][1] = 1;
    }
    else{
        dp[1][0] = 3;
        dp[1][1] = 1;
    }
    
    
    for(int i = 2; i <= n; i++)
    {
        //현재 단위 도형 마름모인 경우  
        if(tops[i-1] == 0)
        {
            dp[i][0] = (dp[i-1][0]*2 + dp[i-1][1]*1)%10007; //i번째 오른쪽 끝 삼각형 타일
            dp[i][1] = (dp[i-1][0]*1 + dp[i-1][1]*1)%10007; //i번째 오른쪽 끝 마름모 타일
        }
        //현재 단위 도형 삼각형인 경우 (꼭지있는 경우)
        else
        {
            dp[i][0] = (dp[i-1][0]*3 + dp[i-1][1]*2)%10007; //i번째 오른쪽 끝 삼각형 타일 
            dp[i][1] = (dp[i-1][0]*1 + dp[i-1][1]*1)%10007; //i번째 오른쪽 끝 마름모 타일 
            
        }
    }
    answer = (dp[n][0] + dp[n][1])%10007;
    return answer;
}

/*
산모양 타일링

-dp로 풀자
n=1 마름모를 하나의 단위로 보자.
n=1 마름모는 꼭지가 있는 경우, 없는 경우로 분리된다.
현재 단위의 경우의 수를 셀때는 오른쪽이 마름모 타일로 찬 경우, 차지 않은 경우로 구분된다.


가령 꼭지 없는 n=2 의 마름모를 생각해보자
n=1 에 대해                      
오른쪽 empty 케이스 2개  
오른쪽 fill 케이스 1개      

n=2 에 대해 
오른쪽 empty 케이스 = 왼쪽 emty 케이스 * 오른쪽 empty + 왼쪽 fill 케이스 * 오른쪽 empty
오른쪽 fill 케이스 = 왼쪽 empty 케이스 * 오른쪽 fill 케이스 + 왼쪽 fill 케이스 *오른쪽 fill
*/