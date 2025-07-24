#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int result = 0;
    int N; 
    vector<int> ability_vector;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int ability;
        cin >> ability;
        ability_vector.push_back(ability);
    }
    sort(ability_vector.begin(), ability_vector.end());

    for(int i = 0; i < N - 1; i++)
    {
        int first_ability = ability_vector[i];
        
        for(int j = i + 1; j < N; j++)
        {
            int second_ability = ability_vector[j];
            int current_ability_sum =first_ability + second_ability;
            int number_valid_third_abilty  = upper_bound(ability_vector.begin() + j + 1, ability_vector.end(), (-1)*current_ability_sum) -
                                             lower_bound(ability_vector.begin() + j + 1, ability_vector.end(), (-1)*current_ability_sum);
            result += number_valid_third_abilty;
            
        }

    }

    cout << result;
    return 0; 
}

