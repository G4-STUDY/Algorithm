#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end());

    int temp = -40000;
    for (int u = 0; u < routes.size(); u++) {
        if (temp >= routes[u][0]) {
            if (temp > routes[u][1]) temp = routes[u][1];
            else continue;
        }
        else {
            temp = routes[u][1];
            answer++;
        }
    }
    return answer;
}
