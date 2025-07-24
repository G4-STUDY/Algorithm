// 18869 메타버스2

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

int m,n;
int temp[10001];
int uni[101][100001];

int compare(int ar1[], int ar2[]) {
    for (int i=0; i<n; i++) {
        if (ar1[i] != ar2[i]) return 0;
    }

    return 1;
}

void compress(vector<int> v, int arr[]) {
    sort(v.begin(), v.end());

    for (int i=0; i<n; i++) {
        int low = 0;
        int high = v.size()-1;

        while (low<=high) {
            int mid = (low+high)/2;

            if (v[mid] == arr[i]) {
                arr[i] = mid;
                break;
            }

            if (v[mid] < arr[i]) {
                low = mid +1;
            }
            else {
                high = mid -1;
            }
        }
    }

}

int main() {
    cin >> m >> n;

    // 입력 받아서 좌표 압축
    for (int i=0; i<m; i++) {
        set<int> s;
        for (int j=0; j<n; j++) {
            cin >> uni[i][j];
            s.insert(uni[i][j]);
        }
        vector<int> v(s.begin(), s.end());
        sort(v.begin(), v.end());
        compress(v, uni[i]);
    }

    // 두 배열이 동일한지 검사
    int ans = 0;
    for (int i=0; i<m-1; i++) {
        for (int j=i+1; j<m; j++) {
            ans += compare(uni[i], uni[j]);
        }
    }

    cout << ans << "\n";

    return 0;
}