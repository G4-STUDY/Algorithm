// 7. 15686 치킨배달

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > chicken;
vector<pair<int, int> > house;
vector<pair<int, int> > selected;

int ans = INT_MAX;

int getSum(int m) {
    int houseX, houseY, x, y;
    int dis, sum = 0;

    for (int i=0; i<house.size(); i++) {
        houseX = house.at(i).first;
        houseY = house.at(i).second;

        dis = INT_MAX;
        for (int j=0; j<m; j++) {
            x = selected.at(j).first;
            y = selected.at(j).second;

            dis = min(dis, abs(houseX-x) + abs(houseY-y));
        }
        sum += dis;
    }

    return sum;
}

void find(int idx, int m) {
    if (selected.size() == m) {
        ans = min(ans, getSum(m));
        return;
    }

    for (int i=idx; i<chicken.size(); i++) {
        selected.push_back(chicken.at(i));
        find(i+1, m);
        selected.pop_back();
    }

}

int main() {
    int n,m, input;
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        for (int j = 1; j<=n; j++) {
            cin >> input;
            if (input == 1) {
                house.push_back({i,j});
            }
            else if (input == 2) {
                chicken.push_back({i,j});
            }
        }
    }

    find(0, m);

    cout << ans << "\n";

    return 0;
}

