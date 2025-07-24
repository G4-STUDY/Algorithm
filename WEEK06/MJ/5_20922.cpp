#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int N, K;
int num_array[200003];
map <int, int> num_map;

int Two_Pointer() {
    int max = 0;
    int start = 0;
    int end = 0;
    int length = 0;
    num_map[num_array[end]]++;
    while (end != N) {
    // end 포인터가 지나가면서 원소의 등장 횟수를 map에 저장함
    // start 포인터는 원소의 등장 횟수를 map에서 감소시킴
    // start 부터 end 까지에서만 원소의 등장 횟수를 확인함
    // 이때 end - start + 1 의 최대값을 구함
        length = end - start + 1;
        if (num_map[num_array[end]] <= K && length > max) {
            max = length;
        }
        if (num_map[num_array[end]] > K) {
            num_map[num_array[start]]--;
            start++;
        }
        else {
            end++;
            num_map[num_array[end]]++;
        }
    }
    if (max == 0) return N;
    return max;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for (int u = 0; u < N; u++) cin >> num_array[u];

    cout << Two_Pointer();

    return 0;
}
