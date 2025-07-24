#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int N, K;
int num_array[1000003];
int input;

int Two_Pointer() {
    int max = 0;
    int str = 0;
    int end = 0;
    int length = 0;
    int hol_cnt = 0;
    hol_cnt += num_array[end];
    while (end != N - 1) {
        if (hol_cnt + num_array[end + 1] > K) {
            hol_cnt -= num_array[str];
            str++;
        }
        else {
            end++;
            hol_cnt += num_array[end];
        }
        length = end - str + 1 - hol_cnt;
        if (length > max) max = length;
    }
    return max;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int u = 0; u < N; u++) {
        cin >> input;
        num_array[u] = input % 2;
    }

    if (N == 1) {
        cout << 1;
        return 0;
    }

    cout << Two_Pointer();

    return 0;
}
