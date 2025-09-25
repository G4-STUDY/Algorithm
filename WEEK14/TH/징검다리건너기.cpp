#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 200000
int get_max_k(vector<int> stones, int sub){
    int max_k = 0;
    int cur_k = 0;
    
    for(int i : stones){
        
        if(i-sub <= 0) cur_k++;
        else cur_k = 0;
        
        if(cur_k > max_k) max_k = cur_k;
        
    }
    
    return max_k;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int start = 0;
    int end = 200000000;
    
    while (start <= end){
        int middle = (start+end)/2;
        
        if(get_max_k(stones,middle) < k){ // 다리 건널 수 있으면
            start = middle + 1;
            continue;
        } 
        end = middle -1;
        answer = middle;
        
    }
    
    
    return answer;
}