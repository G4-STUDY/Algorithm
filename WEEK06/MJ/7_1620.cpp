#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int N, M;

unordered_map <string, string> pokemon_list1;
unordered_map <string, string> pokemon_list2;
string input;
string number;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> N >> M;
    for (int u = 1; u <= N; u++) {
        cin >> input;
        number = to_string(u);
        pokemon_list1[input] = number;
        pokemon_list2[number] = input;
    }
    for (int u = 0; u < M; u++) {
        cin >> input;
        cout << pokemon_list1[input] << pokemon_list2[input] <<'\n';
        
    }
    return 0;
}