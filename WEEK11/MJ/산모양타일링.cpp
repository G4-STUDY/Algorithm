#include <string>
#include <vector>
#include <iostream>


using namespace std;

int arr[1000000];
int solution(int n, vector<int> tops) {
    arr[0] = 3 + tops[0];
    if (n > 1) {
        if (tops[1] == 0) arr[1] = 3*arr[0] - 1;
        else arr[1] = 4*arr[0] - 1;
    }
    for (int u = 2; u < n; u++) {
        if (tops[u] == 1) arr[u] = (4*arr[u-1] - arr[u-2]) % 10007;
        else arr[u] = (3*arr[u-1] - arr[u-2]) % 10007;
    }
    int answer = 0;
    answer = arr[n - 1];
    if (answer < 0) answer += 10007;
    return answer;
}
