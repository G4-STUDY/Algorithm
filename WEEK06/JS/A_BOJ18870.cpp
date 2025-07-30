//백준 18870 좌표압축 (약1000ms) 
#include<iostream>
#include<set>
#include<vector>
using namespace std;

 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<int> datas_set;
    vector<int> datas_vector;
    vector<int> sorted_unique_datas_vector;
    int inputs_number;
    cin >> inputs_number;
    while(inputs_number--)
    {
        int input_data;
        cin>>input_data;
        datas_vector.push_back(input_data);
        datas_set.insert(input_data);
    }
    for(int data : datas_set)
    {
        sorted_unique_datas_vector.push_back(data);
    }
    
    for(int i = 0; i < datas_vector.size(); i++)
    {
        
        int target = datas_vector[i];
        if(target == sorted_unique_datas_vector[0])
        {
            cout << 0 << ' ';
            continue;
        }
        //이분 탐색
        int lo = 0;
        int hi = sorted_unique_datas_vector.size() - 1;
        
        while(lo + 1 < hi)
        {
            int mid = (lo + hi) / 2;
            //결정 조건 : (sorted_unique_datas_vector[mid] < target) -> 배열 상태: [T...TTTFFFF...F]
            if(sorted_unique_datas_vector[mid] < target)
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }
        int lower_number = lo + 1;
        cout << lower_number << ' ';
    }
    return 0;
}


