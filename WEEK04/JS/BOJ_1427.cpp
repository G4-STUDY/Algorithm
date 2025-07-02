#include<bits/stdc++.h>
using namespace std;
//내림차순 비교함수 
bool cmp(int a, int b){
    //a가 b 앞에 나와야할 때만 true 반환
    //우선 순위 같으면 false 반환 (a == b)
    return a > b;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr;
    string input_data;
    cin >> input_data;
    //각 자리수를 정수로 변환해 arr 벡터에 저장 
    for(char c : input_data){
        arr.push_back((c - '0'));
    }

    sort(arr.begin(), arr.end(),cmp);
    //출력
    for(int i : arr){
        cout << i; 
    }
    return 0;
}
