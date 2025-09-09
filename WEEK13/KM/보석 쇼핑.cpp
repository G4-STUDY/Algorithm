#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int n;
int num;
int s;
int e;
int len;
unordered_map<string,int> m;

vector<int> solution(vector<string> gems) {
    s=-1;
    e=-1;
    vector<int> answer;
    for(string gem:gems){
        m[gem]++;
    }
    len=100001;
    n=gems.size();
    num=m.size();
    m.clear();
    int l=0,r=0;
    int cnt=0;
    bool flag=true;
    while(flag){
        while(cnt<num){//다 찾을때까지 r늘리기
            if(r==n){
                flag=false;
                break;
            }
            if(m[gems[r]]==0){
                cnt++;
            }
            m[gems[r]]++;
            r++;
        }
        //cout<<r<<','<<cnt<<'!';
        while(cnt==num&&l<r){
            //cout<<l<<'?'<<m[gems[l]];
            if(m[gems[l]]==1){
                //cout<<':'<<l;
                cnt--;
                if(r-l+1<len){
                    len=r-l+1;
                    s=l;
                    e=r-1;
                }
            }
            m[gems[l]]--;
            l++;
        }
        cout<<'\n';
    }
    answer.push_back(s+1);
    answer.push_back(e+1);
    return answer;
}

/*
첫풀이 l=0 r=size()-1; 하고
r먼저 r-- 해서 뺄수있는데까지 빼고 l++해서 뺄수있는데까지 빼기
l먼저 ...
하고 둘이 비교하고 작은걸로
틀림
------------------------
l=0;r=0;
해놓고 r먼저 늘리고
l줄이고
반복
*/