#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int vis[100003];

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(B.begin(), B.end());
    int temp = 0;
    int sz = A.size();
    for (int u = 0; u <A.size(); u++) {
        temp = lower_bound(B.begin(), B.end(), A[u]) - B.begin();
        while (vis[temp]) {
            temp++;
        }
        //cout << temp << ' ';
        vis[temp] = 1;
        if (temp >= sz) break;
        answer++;
    }
    return answer;
}
