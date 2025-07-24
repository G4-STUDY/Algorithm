#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test_data_number;
    cin >>test_data_number; //2
    
    while(test_data_number--)
    {
        priority_queue<int> max_queue; //최대 힙
        priority_queue<int,vector<int>,greater<int>> min_queue; //최소 힙
        map<int, int> validation_map;
        int command_number;
        cin >> command_number; //7, 9
        while(command_number--)
        {
            char command_kind;
            int data;
            cin >> command_kind >> data;
            
            if(command_kind == 'I')
            {
                min_queue.push(data);
                max_queue.push(data);
                if(validation_map.find(data) == validation_map.end())
                {
                    validation_map[data] = 1;
                }
                else
                {
                    validation_map[data]++;
                }

               
            }
            else  // kind == 'D'
            {
                if(validation_map.empty()) continue;
                
                if(data == 1)
                {
                    
                    while(validation_map.find(max_queue.top()) == validation_map.end()) // max_queue에서 유효한 값 나올 때까지 pop
                    {
                        max_queue.pop();
                    }
                    int max_data = max_queue.top();
                    max_queue.pop();
                    if(validation_map[max_data] == 1) //제거한 원소가 마지막 원소였다면 map에서 제거
                    {
                        validation_map.erase(max_data);
                    }
                    else 
                    {
                        validation_map[max_data]--; //2개 이상이였다면 count만 1 감소 
                    }
                    
                }
                else //data == -1
                {
                    while(validation_map.find(min_queue.top()) == validation_map.end()) // min_queue에서 유효한 값 나올 때까지 pop
                    {
                        min_queue.pop();
                    }
                    int min_data = min_queue.top();
                    min_queue.pop();
                    if(validation_map[min_data] == 1) //제거한 원소가 마지막 원소였다면 map에서 제거
                    {
                        validation_map.erase(min_data);
                    }
                    else 
                    {
                        validation_map[min_data]--; //2개 이상이였다면 count만 1 감소
                    }
                }
            }
            

        }

        vector<int> result_ordering_vector;
        for(auto data : validation_map)
        {
            result_ordering_vector.push_back(data.first);
        }
        sort(result_ordering_vector.begin(), result_ordering_vector.end());
        
        //출력 
        if(result_ordering_vector.empty())
        {
            cout << "EMPTY" << '\n';
        }
        else
        {
            cout << result_ordering_vector[result_ordering_vector.size() - 1] << ' ' << result_ordering_vector[0] << '\n';
        }

    }

    return 0;
}