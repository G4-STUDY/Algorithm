// 20922 겹치는 건 싫어

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int arr[200001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    map<int, int> m;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int low = 0;
    int high = 0;
    int ans = -1;

    // 투포인터
    // map에 나온 횟수 저장
    //  -> 더이상 포함하지 못하면 low를 땡김, 포함 가능하면 high 진행
    while (high < n) {
        if (m[arr[high]] < k) {
            m[arr[high]]++;
            high++;
        }
        else {
            m[arr[low]]--;
            low++;
        }
        ans = max(ans, high-low);
    }

    cout << ans << "\n";


    return 0;
}