#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int arr[1003];

int Find (int x) {
    if (arr[x] == 0) return x;
    return arr[x] = Find(arr[x]);
}

bool Union (int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return false;
    arr[x] = y;
    return true;
}

int N, M;
int a, b, c;
int result;
priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

int main() {
    cin >> N >> M;
    for (int u; u < M; u++){
        cin >> a >> b >> c;
        q.push({c, {a, b}});
    }
    for (int u; u < M; u++){
        a = q.top().Y.X;
        b = q.top().Y.Y;
        c = q.top().X;
        q.pop();

        if (Union(a, b)) result += c;
    }
    
    cout << result;
    return 0;
}
