#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int> v;
queue <int> input;
int G, P, g;
int cnt;

int Find(int x) {
    if (v[x] < 0) return x;
    return v[x] = Find(v[x]);
}

bool Union(int i, int j) {
    i = Find(i);
    j = Find(j);
    if (i == j) return false;
    v[j] = i;
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> G >> P;
    for (int u = 0; u <= G; u++) v.push_back(-1);
    for (int u = 0; u < P; u++) {
        cin >> g;
        input.push(g);
    }
    for (int u = 0; u < P; u++) {
        g = input.front();
        input.pop();
        while (g > 0) {
            if (v[g] >= 0) {
                g--;
                continue;
            }
            Union(0, g);
            cnt++;
            break;
        }
        if (g == 0) {
            cout << cnt;
            return 0;
        }
    }
    cout << cnt;
    return 0;
}
