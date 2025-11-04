#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int arr[10003];

int Find(int x) {
    if (arr[x] == 0) return x;
    return arr[x] = Find(arr[x]);
}

bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return false;
    arr[x] = y;
    return true;
}

int V, E;
int A, B, C, result;
priority_queue <pair <int, pair<int, int>>, vector<pair <int, pair<int, int>>>, greater <pair <int, pair<int, int>>>> q;

int main() {
    cin >> V >> E;
    for (int u = 0; u < E; u++) {
        cin >> A >> B >> C;
        q.push({C, {A, B}});
    }
    for (int u = 0; u < E; u++) {
        A = q.top().Y.X;
        B = q.top().Y.Y;
        C = q.top().X;
        q.pop();
        if (Union(A, B)) result += C;
    }
    
    cout << result;
    
    return 0;
}
