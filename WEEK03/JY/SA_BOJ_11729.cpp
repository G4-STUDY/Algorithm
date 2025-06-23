// 11729 하노이 탑 이동 순서

#include <iostream>
using namespace std;

void hanoi(int n, int start, int end) {
    // 1번 원판(맨 위의 원판)은 그냥 옮기면 됨
    if (n == 1) {
        cout << start << " " << end << "\n";
        return;
    }
    //n-1개의 원판을 시작점에서 경유지로 옮김
    hanoi(n - 1, start, 6-start-end);
    //n번째 원판은 목적지로 옮김
    cout << start << " " << end << "\n";
    //n-1개의 원판을 경유지에서 목적지로 옮김
    hanoi(n - 1, 6-start-end, end);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << (1<<n) -1 << "\n"; // 최소 이동 = 2^n - 1
    hanoi(n, 1, 3);

    return 0;
}