//LIS(최장 길이 부분 수열 )
#include<iostream>
#include<vector>
using namespace std;
int main(){

    int n, input; 
    cin >> n;
    vector<int> v(n);
    vector<int> result;
    for(int i=0; i<n; i++){
        cin >> input;
        v[i] = input;
    }
    result.push_back(v[0]);
    int len = 1;
    
    for(int i=1; i<n; i++){
       int cur = v[i];
       if(cur >= result[len-1]){
            result.push_back(cur);
            len++;
       }
       else{
        auto it = lower_bound(result.begin(), result.begin() + (len-1), cur);
        result[it - result.begin()] = cur;
       }

    }
    cout << n - len;
    return 0;
}