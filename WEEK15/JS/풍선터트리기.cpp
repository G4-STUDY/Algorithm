#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    //1.특정 인덱스 기준 왼쪽 최솟값 갱신 -> left_min[i] : 인덱스 i 이전 배열값 중 최솟값
    int left_min = 1000000001;
    vector<int> left_min_vector(a.size());
    for(int i = 0 ; i < a.size(); i++)
    {
        left_min_vector[i] = left_min;
        left_min = min(left_min, a[i]);
    }
    //2.특정 인덱스 기준 오른쪽 최솟값 갱신 -> right_min[i] : 인덱스 i 이후 배열값 중 최댓값
    int right_min = 1000000001;
    vector<int> right_min_vector(a.size());
    for(int i = a.size() - 1; i >= 0; i--)
    {
        right_min_vector[i] = right_min;
        right_min = min(right_min, a[i]);
    }
    //3. 가능한 풍선 판단
    for(int i = 0; i < a.size(); i++)
    {
        if(left_min_vector[i] > a[i] || right_min_vector[i] > a[i]) answer++;
    }
    return answer;
}

/*
인덱스를 순회하며 왼쪽 범위에서 최솟값, 오른쪽 범위에서 최솟값 구한 뒤
두 최솟값 중 현재 인덱스의 값보다 큰 값이 적어도 하나 존재하면 최후까지 남을 수 있는 풍선임.
두 최솟값 모두 자기 현재 인덱스의 값보다 작으면 최우까지 남을 수 없음.
*/