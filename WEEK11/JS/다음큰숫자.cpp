#include <string>
#include <vector>

using namespace std;

//1의 숫자 반환 함수
int findOneNumber(int n) {
    int one_number = 0;
    while(n > 1)
    {
        int mod = n % 2; //0 0 1
        int div = n / 2; //6 3 1
        if(mod == 1) one_number++;
        n = div;
    }
    
    return one_number + 1;
}


int solution(int n) {
    int answer = 0;
    int one_number = findOneNumber(n);
    while(true)
    {   
        //1씩 증가시키며 1의 수 확인
        int nxt = n + 1;
        if(one_number == findOneNumber(nxt))
        {
            answer = nxt;
            break;
        }
        n = nxt;
    }
    return answer;
}