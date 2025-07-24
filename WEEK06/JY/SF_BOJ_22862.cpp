// 22862 가장 긴 짝수 연속한 부분 수열(large)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, num;

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> num;
        arr.push_back(num%2);
    }

    int low = 0;
    int high = 0;
    int cnt = 0;
    int ans = -1;

    // 투포인터
    // 이미 k 만큼 홀수를 다 바꿔서 더이상 못바꾸는 경우 low 땡김
    // 진행가능하면 high 진행
    while (high < n) {
        // 진행 못함
        if (arr[high] == 1 && cnt >= k) {
            if (arr[low] == 1) {
                cnt--;
            }
            low++;
        }
        else {
            if (arr[high] == 1) {
                cnt++;
            }
            high++;
        }
        // 홀수가 나온 cnt만큼 크기를 줄임
        ans = max(ans, high - low - cnt);
    }

    cout << ans << "\n";

    return 0;
}