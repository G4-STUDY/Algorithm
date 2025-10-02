#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer=1;
    //가운데만 다른거 
    for(int i=0 ;i<s.size();i++){
        int l=i-1,r=i+1;
        while(0<=l&&r<s.size()){
            if(s[l]!=s[r])break;
            answer=max(answer,r-l+1);
            l--;
            r++;
        }
    }
    //가운데 두개가 같은거도 봐야지
    for(int i=0 ;i<s.size()-1;i++){
        if(s[i]!=s[i+1])continue;
        int l=i,r=i+1;
        while(0<=l&&r<s.size()){
            if(s[l]!=s[r])break;
            answer=max(answer,r-l+1);
            l--;
            r++;
        }
    }
    return answer;
}

/*
n=2500,
하나씩 해서 왼,오 확인 n^2 되긴함



*/