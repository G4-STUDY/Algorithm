//백준 3151 합이 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findCaseNumber(int target,int st, int en,vector<int>& v);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int result = 0;
    int N;
    vector<int> students_ability;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int ability;
        cin >> ability;
        students_ability.push_back(ability);
    }
    sort(students_ability.begin(), students_ability.end());
    
    for(int i = 0; i <= N - 3; i++)
    {
        int first_ability = students_ability[i];
        int st = i + 1;
        int en = N - 1;
        result += findCaseNumber((-1)*first_ability, st, en, students_ability);
    }

    cout << result;
    return 0;

}

int findCaseNumber(int target, int st, int en,vector<int>& v)
{
    int valid_case = 0;
    int current_st_value;
    int current_sum;
    while(st + 1 <= en)
    {
        current_sum = v[st] + v[en];
        if(current_sum < target)
        {
            st++;
        }
        else if(current_sum > target)
        {
            en--;
        }
        else //current_sum == target
        {
            valid_case++;
            //중복 처리 
        }

    }

    return valid_case;
}
