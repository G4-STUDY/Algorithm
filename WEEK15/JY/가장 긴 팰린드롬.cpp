#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int solution(string s)
{
    int answer=1;

    for(int i=0; i< s.length(); i++){
        cout << s[i] << "  ";
        int len1 = 0;
        bool flag = false;
        for(int j=1; j<=i; j++){
            if(flag) continue;
            if(s[i-j] != s[i+j]){
                if(j==1) len1 = 0;
                len1 = (j-1) * 2 + 1;
                flag = true;
            }
        }
        if(!flag) len1 = i*2+1;
        answer = max(answer, len1);
        
        int len2 = 0;
        flag = false;
        for(int j=1; j<=i+1; j++){
            if(flag) continue;
            if(s[i-j+1] != s[i+j]){
                if(j==1) len2 = 0;
                len2 = (j-1) * 2;
                flag = true;
            }
        }
        if(!flag) len2 = (i+1)*2;
        //if(i == 0) len2 = 0;
        answer = max(answer, len2);
        cout << len1 << " " << len2 << "\n";
    }

    return answer;
}

/**
babacde

1. 하나를 기준으로 잡고 양쪽을 계속 확인한다
- 엔제곱 가능할 것 같긴한데 이게 최선인가;;
- 6250000

0 1 2 3 4 5 6
a b c d c b a

기준점이 없어 대칭일 수 있네 


penguin

*/
