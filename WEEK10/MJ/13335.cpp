#include <iostream>
#include <queue>
using namespace std;

queue <int> q_bridge;
queue <int> q_trucks;
int n, w, L, a;

int load_sum;
int t;
int truck_cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w >> L;
    for (int u = 0; u < n; u++) {
        cin >> a;
        q_trucks.push(a);
    }
    for (int u = 0; u < w; u++) {
        q_bridge.push(0);
    }

    while (true) {
        if (q_bridge.front() != 0) {
            load_sum -= q_bridge.front();
            truck_cnt++;
        }
        q_bridge.pop();
        t++;
        if (truck_cnt == n) break;
        if (q_trucks.empty()) continue;
        int load_front_truck = q_trucks.front();
        if (load_sum + load_front_truck <= L) {
            q_bridge.push(load_front_truck);
            q_trucks.pop();
            load_sum += load_front_truck;
        }
        else {
            q_bridge.push(0);
        }
    }
    cout << t;
    return 0;
}

