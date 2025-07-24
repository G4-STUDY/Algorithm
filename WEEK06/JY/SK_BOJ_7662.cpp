// 7662 이중 우선순위 큐


#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, k, num;
    char op;

    cin >> t;
    while (t--) {
        cin >> k;

        map<int, int> exist; // 존재 여부를 저장하기 위함
        priority_queue<int> desc; // 내림차순 -> 최대 삭제
        priority_queue<int, vector<int>, greater<int> > asc; // 오름차순 -> 최소 삭제

        for (int i = 0; i < k; i++) {
            cin >> op >> num;
            if (op == 'I') {
                // 삽입
                exist[num]++;
                asc.push(num);
                desc.push(num);
            }
            else if (op == 'D') {
                if (num == 1) {
                    // 최대값 삭제
                    // desc의 최대값이 존재할 때 제거
                    while(!desc.empty()) {
                        if (exist[desc.top()] > 0) {
                            exist[desc.top()]--;
                            desc.pop();
                            break;
                        }
                        desc.pop();
                    }
                }
                else if (num == -1) {
                    // 최소값 삭제
                    // asc의 최소값이 존재할 때 제거
                    while(!asc.empty()) {
                        if (exist[asc.top()] > 0) {
                            exist[asc.top()]--;
                            asc.pop();
                            break;
                        }
                        asc.pop();
                    }
                }
            }
        }

        vector<int> v;

        // 현재 남아있는 원소만 벡터에 저장
        for (pair<int, int> p : exist) {
            if (exist[p.first] > 0) {
                v.push_back(p.first);
            }
        }

        if (v.empty()) {
            cout << "EMPTY" << "\n";
            continue;
        }

        sort(v.begin(), v.end());

        cout << v[v.size()-1]<< " " << v[0]<< "\n";
    }



    return 0;
}