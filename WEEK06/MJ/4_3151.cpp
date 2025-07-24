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
            temp_sum = - students[u] - students[v];
            if (binary_search(students + v + 1, students + N, temp_sum)) {
                cnt += upper_bound(students + v + 1, students + N, temp_sum)
                    - lower_bound(students + v + 1, students + N, temp_sum);
            }
        }
    }
    cout << cnt;
    return 0;
}
