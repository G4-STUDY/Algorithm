#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    map<int, int> left, right;

    for(int type: topping){
        right[type]++;
    }

    for(int type: topping){
        left[type]++;
        right[type]--;

        if(right[type] == 0) right.erase(type);

        if(left.size() == right.size()) answer++;
    }


    return answer;
}