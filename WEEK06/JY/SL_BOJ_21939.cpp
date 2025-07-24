// 21939 문제 추천 시스템 Version 1

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

map<int, int> exist; // 존재 여부를 저장하기 위함 (문제번호, 난이도)
priority_queue<pair<int, int> > big; // 내림차순 -> 최대 삭제 (난이도, 문제번호)
// 오름차순 -> 최소 삭제
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > small;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, p, l, m, num;
    string op;

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> p >> l;
        exist[p] = l;
        big.push(make_pair( l, p));
        small.push(make_pair(l, p));
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op.compare("add") == 0) {
            // 추가
            cin >> p >> l;
            exist[p] = l;
            big.push(make_pair( l, p));
            small.push(make_pair(l, p));
        }
        else if (op.compare("recommend") == 0) {
            cin >> num;
            if (num == 1) {
                // 어려운거 추천
                // 가장 어려운 문제의 난이도가 맵에 올바르게 저장되어 있으면 추천
                // 뒤늦게 똑같은 문제 번호로 다른 난이도가 들어오면 문제 생길 수 있음
                while (!big.empty()) {
                    if (exist[big.top().second] == big.top().first) {
                        cout << big.top().second << "\n";
                        break;
                    }
                    big.pop();
                }
            }
            else if (num == -1){
                while (!small.empty()) {
                    if (exist[small.top().second] == small.top().first) {
                        cout << small.top().second << "\n";
                        break;
                    }
                    small.pop();
                }
            }
        }
        // 푼거 맵에서 지움
        else if (op.compare("solved") == 0) {
            cin >> num;
            exist.erase(num);
        }
    }

    return 0;
}