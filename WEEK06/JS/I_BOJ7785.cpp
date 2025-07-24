#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, string> logs;
    
    int n; 
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string name, log;
        cin >> name >> log; 
        logs[name] = log;
    }
    vector<string> temp_vector;
    for(auto log : logs)
    {
        if(log.second == "enter") temp_vector.push_back(log.first);
    }
    int temp_vector_size = temp_vector.size();
    for(int i = temp_vector_size - 1; i >= 0; i--) cout << temp_vector[i] << '\n';
    return 0;

}