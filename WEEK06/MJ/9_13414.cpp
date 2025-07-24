#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int K, L;
unordered_map <string, int> click_list;
string input;
vector <pair<int, string>> result;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> K >> L;
    for (int u = 1; u <= L; u++) {
        cin >> input;
        click_list[input] = u;
    }
    
    for (auto e : click_list) {
        result.push_back({e.second, e.first});
    }
    
    sort(result.begin(), result.end());
    for (int u = 0; u < K; u++) {
        if (u == result.size()) return 0;
        cout << result[u].second << '\n';
    }
    return 0;
}