// 14501 퇴사

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[25];
    // 지역변수는 초기화 하지 않으면 쓰레기값이 들어감 - 전역변수는 0
    fill(arr, arr+25, 0);
    int t[25];
    int p[25];
    for (int i=1; i<=n; i++) {
        cin >> t[i] >> p[i];
        //cout << i << " " << t[i] << " " << p[i] << "\n";
    }

    // 뒤에서부터 채운다
    for (int i=n; i>0; i--) {
        // i일에 시작해서 n일 이내 끝낼 수 없는 경우 선택 안함
        if (i + t[i] - 1 > n) {
            arr[i] = arr[i+1];
        }
        // 끝낼 수 있으면 선택하지 않거나 선택한 값 중에 큰 값
        else {
            arr[i] = max(arr[i+1], arr[i+t[i]] + p[i]);
        }
        //cout << n << " " << arr[i] << "\n";
    }
    cout << arr[1] << "\n";

    return 0;
}