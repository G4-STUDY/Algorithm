#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> min_r;
vector<int> min_l;

int solution(vector<int> a) {
    
    int arr_size = a.size();
    
    min_r = vector<int>(arr_size);
    min_l = vector<int>(arr_size);
    
    min_r[arr_size-1] = a[arr_size-1];
    min_l[0] = a[0];
    
    for(int i=1,j=arr_size-2; i<arr_size; i++, j--){
        
        min_l[i] = min(a[i], min_l[i-1]);
        min_r[j] = min(a[j], min_r[j+1]);
        
    }
    
    
    int answer = 2; // 양 끝은 무조건 터뜨릴 수 있음
    for(int i=1;i<arr_size-1;i++){
        if(min_l[i-1] < a[i] && min_r[i+1] < a[i]) continue;
        answer++;
    }
    
    return answer;
}

/*
최종 시점에만 판단하면 됨

다 사라졌다 치고
[-92 -2 -16]
이런 식으로 목표 숫자의 양옆 모두에 더 작은 수가 있으면 최후까지 못남음

부분합 알고리즘을 응용해서 왼쪽과 오른쪽에 부분최소값 배열을 생성

크기가 10인 배열의 인덱스가 4라면 
[배열의 0~3 부분최소값, 현재 인덱스의 배열 값, 배열의 5~9 부분최소값]
으로 비교

*/