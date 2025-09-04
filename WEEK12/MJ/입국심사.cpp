#include <string>
#include <vector>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long st = 1;
    long long mid = 0;
    long long en = 1000000000000000000;
    long long cnt = 0;
    while(true) {
        mid = (st + en) / 2;
        if (st > en) break;
        cnt = 0;
        for (int u = 0; u < times.size(); u++) cnt += (mid / times[u]);
        
        if (cnt >= n) en = mid - 1;
        else if (cnt < n) st = mid + 1;
        
    }
    answer = st;
    return answer;
}
