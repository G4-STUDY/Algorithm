#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int n = A.size();
    priority_queue<int> maxheap_A;
    priority_queue<int> maxheap_B;
    priority_queue<int, vector<int>, greater<int>> minheap_B;
    
    for(int a : A) maxheap_A.push(a);
    for(int b : B)
    {
        maxheap_B.push(b);
        minheap_B.push(b);
    }
    
    for(int i = 0; i < n; i++)
    {
        int top_A = maxheap_A.top(); maxheap_A.pop();
        int top_B = maxheap_B.top();
        if(top_B > top_A)
        {
            maxheap_B.pop();
            answer++;
        }
        else
        {
            minheap_B.pop();
        }
    }
    
    return answer;
}

/*
N명 N명 -> 모두 무작위로 자연수
각 사원은 경기 한번
각 경기당 각 팀의 한명씩 숫자 공개, 큰쪽이 승리, 승리하면 1점
A팀은 출전 순서 B팀에 공개 -> B팀은 승점 가장 높이는 방법으로 순서 정함.이때 B의 승점?
그냥 A도 정렬해버리면 되는거 아닌가 
아님 -> B의 가장 큰 점수가 A의 가장 큰 점수 못이기면 순서를 뒤에 하는게 이득일 수도 있음
PQ에 각각 넣어서 TOP끼리 비교 -> 만약 B의 TOP이 A의 TOP 보다 크면 둘다 POP/작으면 가장 작은 원소 POP.
B에 대한 PQ를 두개..??
A[5,1,3,7] -> 7,5,3,1 
B[2,2,6,8] ->8,6,2,2 / 2,2,6,8
5,3,1
6,2,2/2,2,6,8
3,1
2,2/2,2,6,8
1
2,2/2,6,8




*/
