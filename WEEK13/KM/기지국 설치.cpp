#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> arr;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int dist=2*w+1;
    //전처리
    for(int station:stations)
    {
        arr.push_back(station-w);
    }
    
    //시작지점 1에 설치할지 판단하기
    int idx=1;
    //if(arr[0]<idx)idx=arr[0]; 해서 안됐음 시작점이 1인경우도 정답증가시켰었음..
    if(arr[0]<=idx)idx=arr[0];
    else{
        answer++;
    }
    
    //배열탐색
    for(int cur:arr)
    {
        if(idx+dist>=cur){//이미 있는걸로 커버가되면
            idx=cur;
        }
        else{//안되면
            answer+=(cur-idx-dist)/dist;
            if(((cur-idx)%dist)==0);
            else answer++;
            idx=cur;
        }
    }
    //n까지 다채웠으면 return
    if(idx+dist>n) return answer;
    
    //n까지 매우기
    answer+=(n+1-idx-dist)/dist;
    if(((n+1-idx)%dist)==0);
    else answer++;
    
    return answer;
}

/*
그냥 비어있으면 채우면 되는거아닌가 
전파는 오른쪽으로 쏜다고 생각하고 설치하자
*/