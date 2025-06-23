// 16987 계란으로 계란치기

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int power[9]; // 내구도
int weight[9]; // 무게
int ans = -1;

void func(int egg) {
    // 종료 - 맨 오른쪽 계란까지 다 사용했음
    if (egg == n) {
        int cnt = 0;
        // 내구도가 0 이하는 깨진 것으로 cnt 증가
        for (int i=0; i<n; i++) {
            if (power[i] <= 0) cnt++;
        }
        // 최대값 갱신
        ans = max(ans, cnt);
        return;
    }

    // 내가 집은 계란이 이미 깨졌음 -> 다음 계란 선택
    if (power[egg] <= 0) {
        func(egg+1);
        return;
    }

    bool attack = false; // 깨지지 않은 계란이 없으면 공격 불가
    for (int i=0; i<n; i++) {
        // 자기 자신이거나 이미 깨졌으면 pass
        if (i == egg || power[i] <= 0) continue;

        // 계란 깨기
        power[egg] -= weight[i];
        power[i] -= weight[egg];
        attack = true;
        func(egg+1);
        // 백트래킹
        power[egg] += weight[i];
        power[i] += weight[egg];
    }
    // 깨지지 않은 계란이 없어서 공격 불가 -> pass
    if (!attack) {
        func(egg+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(power, power+9, 0);
    fill(weight, weight+9, 0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> power[i] >> weight[i];
    }

    func(0);

    cout << ans << "\n";

    return 0;
}