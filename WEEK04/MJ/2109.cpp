#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define Pay first
#define Day second

pair<int, int> LectureList[10002];
int Scheduled[10002];

int N;
long MaxPay;
int MaxDay;
int main(void) {
    cin >> N;
    for (int u = 0; u < N; u++) {
        cin >> LectureList[u].Pay >> LectureList[u].Day;
    }
    sort(LectureList, LectureList + N);

    for (int u = N - 1; u >= 0; u--) {
        for (int v = LectureList[u].Day; v > 0; v--) {
            if (Scheduled[v] == 0) {
                Scheduled[v] = 1;
                MaxPay += LectureList[u].Pay;
                break;
            }
        }
    }
    cout << MaxPay;

    return 0;
}
