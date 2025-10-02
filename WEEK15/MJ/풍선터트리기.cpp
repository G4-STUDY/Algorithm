/*
1. 양 끝의 풍선은 그 숫자의 크기에 상관없이 무조건 최후의 2개에 포함됨. -> 따라서 무조건 최후에 남음.
2. 양 끝이 아닌 풍선은 무조건 최후의 3개에 포함되며, 이때 항상 가운데에 위치함.
    - 양쪽에 남은 풍선에 적힌 숫자는 가운데 풍선을 제외한 각 사이드에서 가장 작은 숫자의 풍선임.
    - 이때 가운데 풍선이 3개의 풍선중 가장 큰 숫자일 경우, 최후에 못 남고 터짐.
    - 그게 아니면 answer++

*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[1000000][2];

int solution(vector<int> a) {
    int answer = 0;
    
    int min_val = 0x7fffffff;
    arr[0][0] = min_val;
    arr[a.size()-1][1] = min_val;
    for (int u = 0; u < a.size() - 1; u++) {
        if (a[u] < min_val) min_val = a[u];
        arr[u+1][0] = min_val;
    }
    
    min_val = 0x7fffffff;
    for (int u = a.size() - 1; u > 0; u--) {
        if (a[u] < min_val) min_val = a[u];
        arr[u-1][1] = min_val;
    }
    
    for (int u = 0; u < a.size(); u++) {
        if (a[u] < arr[u][0] || a[u] < arr[u][1]) answer++;
    }
    
    return answer;
}
