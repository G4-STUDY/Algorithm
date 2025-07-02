#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<ll> reversed_ll_data;
    int n;
    cin >> n;
    string input_data;
    for(int i=0;i<n;i++)
    {
        cin >> input_data;
        //string으로 입력받고 뒤집어서 long long 으로 변환
        reverse(input_data.begin(), input_data.end());
        ll converted = stoll(input_data);
        reversed_ll_data.push_back(converted);
    }
    //저장 벡터 정렬 
    sort(reversed_ll_data.begin(), reversed_ll_data.end());
    for(ll data : reversed_ll_data)
    {
        cout << data << '\n';
    }

    return 0;
}