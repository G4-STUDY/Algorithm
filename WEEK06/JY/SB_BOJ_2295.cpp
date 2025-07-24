// 2295 세 수의 합

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int u[1001];
int n;

vector<int> sum;

bool b_search(int val) {
    int low = 0;
    int high = sum.size()-1;

    while (low <= high) {
        int mid = (low+high)/2;

        if (sum[mid] == val) {
            return true;
        }

        if (sum[mid] < val) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> u[i];
    }
    sort(u, u+n);

    // 두 수를 골라 합한 배열(sum)을 만든 후 정렬
    for (int i=0; i<n-1; i++) {
        for (int j=i; j<n; j++) {
            sum.push_back(u[i]+u[j]);
        }
    }
    sort(sum.begin(), sum.end());

    // 두 수의 차이가 sum에 있는지 탐색하여 있는 경우 최대값 출력 후 종료
    for (int i=n-1; i>=1; i--) {
        for (int j=i-1; j>=0; j--) {
            if (b_search(u[i] - u[j])) {
                cout << u[i] << "\n";
                return 0;
            }
        }
    }
    return 0;
}

/**
 * u[a] + u[b] + u[c] = u[d];
 * 두 수의 가능한 모든 합을 저장한 배열 sum
 * sum[x] + u[c] = u[d]
 */