// 3151 합이 0

#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

int n, input;
vector<int> positive;
vector<int> negative;
vector<int> zero;
vector<int> posum;
vector<int> nesum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int zero_cnt = 0;
    int k = 0;
    for (int i=0; i<n; i++) {
        cin >> input;
        if (input == 0) {
            zero_cnt++;
            negative.push_back(input);
        }
        else if (input > 0) {
            positive.push_back(input);
        }
        else {
            negative.push_back(input);
        }
    }

    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end());
    // for (int temp:positive) {
    //     cout << temp << " ";
    // }
    // cout << "\n";
    //
    // for (int temp:negative) {
    //     cout << temp << " ";
    // }
    // cout << "\n";

    if (positive.empty()) {
        if (zero_cnt>=3) {
            k = zero_cnt * (zero_cnt-1) * (zero_cnt-2) / 6;
        }
        cout << k << "\n";
        return 0;
    }

    for (int i=0; i<positive.size()-1; i++) {
        for (int j=i+1; j<positive.size(); j++) {
            posum.push_back(positive[i]+positive[j]);
        }
    }

    for (int i=0; i<negative.size()-1; i++) {
        for (int j=i+1; j<negative.size(); j++) {
            nesum.push_back(negative[i]+negative[j]);
        }
    }

    // for (int temp:posum) {
    //     cout << temp << " ";
    // }
    // cout << "\n";
    //
    // for (int temp:nesum) {
    //     cout << temp << " ";
    // }
    // cout << "\n";

    int ans = 0;
    for (int i=0; i<posum.size(); i++) {
        int temp = upper_bound(negative.begin(), negative.end(), posum[i]*-1) - lower_bound(negative.begin(), negative.end(), posum[i]*-1);
        //cout << temp << " ";
        ans += temp;
    }
    //cout << "\n";
    for (int i=0; i<nesum.size(); i++) {
        int temp = upper_bound(positive.begin(), positive.end(), nesum[i]*-1) - lower_bound(positive.begin(), positive.end(), nesum[i]*-1);
        //cout << temp << " ";
        ans += temp;
    }

    if (zero_cnt>=3) {
            k = zero_cnt * (zero_cnt-1) * (zero_cnt-2) / 6;
    }
    cout << ans + k << "\n";

    return 0;
}