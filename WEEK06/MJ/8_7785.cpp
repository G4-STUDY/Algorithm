#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int N;

unordered_set <string> people_list;
vector <string> result;
string people_name;
string enter_or_leave;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> N;
    for (int u = 0; u < N; u++) {
        cin >> people_name >> enter_or_leave;
        if (enter_or_leave == "enter") {
            people_list.insert(people_name);
        }
        else {
            people_list.erase(people_name);
        }
    }
    for (auto e : people_list) result.push_back(e);
    sort (result.begin(), result.end());
    while(!result.empty()) {
        cout << result.back() << '\n';
        result.pop_back();
    }
    return 0;
}