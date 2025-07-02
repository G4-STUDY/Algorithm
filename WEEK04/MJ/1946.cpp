#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define SeoRyu first
#define MyeonJeop second

int T, N;

pair<int, int> Participant[100001];
int result[21];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int u = 0; u < T; u++) {
        int cnt = 0;
        cin >> N;
        for (int v = 0; v < N; v++) {
            cin >> Participant[v].SeoRyu >> Participant[v].MyeonJeop;
        }
        sort(Participant, Participant + N);
        int compare_grade = Participant[0].MyeonJeop;
        for (int v = 0; v < N; v++) {
            if (Participant[v].MyeonJeop <= compare_grade) {
                compare_grade = Participant[v].MyeonJeop;
                cnt++;
            }
        }
        result[u] = cnt;
    }

    for (int u = 0; u < T; u++) {
        cout << result[u] << endl;
    }

    return 0;
}
