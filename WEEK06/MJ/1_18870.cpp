#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int N;

int arr_sort[1000003];
int arr_temp[1000003];
vector <int> arr_result;
int input;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int u = 0; u < N; u++) {
        cin >> input;
        arr_sort[u] = input;
        arr_temp[u] = input;
    }
    sort(arr_sort, arr_sort + N);
    
    //------------------------------------------------------------------------------------------------
    // arr_sort에서 중복 제거해서 arr_result에 넣기
    for (int u = 0; u < N; u++) {
        if (arr_sort[u] == arr_sort[u + 1]) continue;
        else {
            arr_result.push_back(arr_sort[u]);
        }
    }
    //------------------------------------------------------------------------------------------------

    //------------------------------------------------------------------------------------------------
    // arr_temp에 입력받은 순서대로 저장돼있으므로, 그 순서대로 꺼내서 압축된 죄표 출력
    for (int u = 0; u < N; u++) {
        cout << lower_bound(arr_result.begin(), arr_result.end(), arr_temp[u]) - arr_result.begin() << ' ';
    }
    //------------------------------------------------------------------------------------------------
    return 0;
}
