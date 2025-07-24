// 1620 나는야 포켓몬 마스터 이다솜

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    string name;
    cin>>n>>m;

    map<int, string> one; // 번호가 key
    map<string, int> two; // 이름이 key

    for (int i=1; i<=n; i++) {
        cin>>name;
        one.insert(make_pair(i, name));
        two.insert(make_pair(name, i));
    }

    for (int i=0; i<m; i++) {
        cin >> name;
        // 숫자가 들어온 경우 숫자로 찾음
        if (name.at(0) - '0' > 0 && name.at(0) - '0' < 10) {
            cout << one[stoi(name)] << "\n";
        }
        // 이름이 들어온 경우 이름으로 찾음
        else {
            cout << two[name] << "\n";
        }
    }

    return 0;
}