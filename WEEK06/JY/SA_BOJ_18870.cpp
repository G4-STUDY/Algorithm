// 18870 좌표 압축

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int ori[1000001]; // 원본 배열
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> ori[i];
    }

    set<int> s (ori, ori+n); // 중복제거 후
    vector<int> v(s.begin(), s.end()); // 벡터에 저장

    sort(v.begin(), v.end());

    // 이분탐색 진행 - 찾으면 인덱스 반환(자기보다 작은 값의 개수)
    for (int i=0; i<n; i++) {
        int low = 0;
        int high = v.size()-1;

        while (low <= high) {
            int mid = (low+high)/2;

            if (v[mid] == ori[i]) {
                cout << mid << " ";
                break;
            }
            if (v[mid] < ori[i]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }

    return 0;
}