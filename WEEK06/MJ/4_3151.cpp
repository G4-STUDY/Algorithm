#include <iostream>
#include <algorithm>
using namespace std;

int N;
int students[10003];
int temp_sum;
long long cnt;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int u = 0; u < N; u++) {
        cin >> students[u];
    }
    sort(students, students + N);
    for (int u = 0; u < N; u++) {
        for (int v = u + 1; v < N; v++) {
            temp_sum = - students[u] - students[v]; // 2명의 학생 코딩 실력을 합해둔 변수(음수)
            if (binary_search(students + v + 1, students + N, temp_sum)) { // temp_sum + (3번 학생 코딩실력) = 0 이어야 함
                cnt += upper_bound(students + v + 1, students + N, temp_sum)
                    - lower_bound(students + v + 1, students + N, temp_sum); // 같은 코딩실력을 가진 학생이 여러 명일 경우, 그 수만큼 cnt에 더함
            }
        }
    }
    cout << cnt;
    return 0;
}
