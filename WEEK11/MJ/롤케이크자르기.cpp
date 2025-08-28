#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int topping_cnt = 0;
    unordered_map <int, int> m1;
    unordered_map <int, int> m2;
    for (int u = 0; u < topping.size(); u++) {
        m1[topping[u]]++;
    }

    for (int u = 0; u < topping.size(); u++) {
        m2[topping[u]]++;
        m1[topping[u]]--;
        if(m1[topping[u]] == 0) m1.erase(topping[u]);
        if (m1.size() == m2.size()) answer++;
    }
    return answer;
}
