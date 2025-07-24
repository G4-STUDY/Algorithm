#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<string,int> a, pair<string,int> b)
{
    return a.second > b.second;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<string, int> waiting_map;
    int K, L;
    cin >> K >> L;
    int rank = 1;
    for(int i = 0; i < L; i++)
    {
        string student_number;
        cin >> student_number;
        //현재 대기열에 없으면(버튼 최초 클릭), 대기열 맨 뒤로
        if(waiting_map.find(student_number) == waiting_map.end())
        {
            waiting_map[student_number] = rank++;
        }
        else
        {
            waiting_map.erase(student_number);
            waiting_map[student_number] = rank++;
        }
    }
    vector<pair<string, int>> ordering_vector; 
    
    for(auto p : waiting_map) ordering_vector.push_back({p.first, p.second});
    
    sort(ordering_vector.begin(), ordering_vector.end(), cmp);
    
    
    while(ordering_vector.size() > 0 && K--)
    {
        
        cout << ordering_vector[ordering_vector.size() - 1].first << '\n';
        ordering_vector.pop_back();
    }
    return 0;
}   