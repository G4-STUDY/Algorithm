#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N;
int input;
int same_universe_cnt;
string multiverse_original[103];
string multiverse_compact[103];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> M >> N;
    for (int v = 0; v < M; v++) {
        int temp = 0;
        vector <int> array_sort;
        vector <int> array_result;
        for (int u = 0; u < N; u++) {
            cin >> input;
            array_sort.push_back(input);
            array_result.push_back(input);
        }
        sort(array_sort.begin(), array_sort.end());

        string compact;
        for (int u = 0; u < N; u++) {
            temp = lower_bound(array_sort.begin(), array_sort.end(),  array_result[u]) - array_sort.begin();
            compact += to_string(temp);
        }
        if (binary_search(multiverse_compact, multiverse_compact + v, compact)) {
            same_universe_cnt += upper_bound(multiverse_compact, multiverse_compact + v, compact) - lower_bound(multiverse_compact, multiverse_compact + v, compact);
        }
        multiverse_compact[v] = compact;
        sort(multiverse_compact, multiverse_compact + v + 1);
    }

    cout << same_universe_cnt;
    return 0;
}
