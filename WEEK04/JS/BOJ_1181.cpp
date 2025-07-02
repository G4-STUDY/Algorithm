#include<bits/stdc++.h>
using namespace std;
bool cmp(string a, string b){
    if(a.size() != b.size()){
        return a.size() < b.size();
    }
    else{
        return a < b;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    set<string> tmp_set;
    vector<string> strings;
    int N;
    cin >> N;
    string input_string;
    //set에 입력 받기 
    while(N--){
        cin >> input_string;
        tmp_set.insert(input_string);
    }
    //set에서 꺼내서 벡터에 저장 후 벡터 정렬
    for(string s : tmp_set){
        strings.push_back(s);
    }
    sort(strings.begin(), strings.end(), cmp);
    //출력
    for(string s:strings){
        cout << s << '\n';
    }
}