//백준 22862 가장 긴 짝수 연속한 부분 수열(large)
#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> sequence;
    for(int i = 0; i < N; i++)
    {
        int number;
        cin >> number;
        sequence.push_back(number);
    }
    int st = 0; int en = 0;
    int pre_st = 0;
    int current_odds = 0;
    int max_length = 0;
    if(sequence[st] % 2 != 0) current_odds++;
    for(st; st < N; st++)
    {
        if(sequence[pre_st] % 2 != 0 && sequence[st] % 2 == 0) current_odds--;
        else if(sequence[pre_st] % 2 == 0 && sequence[st] % 2 != 0) current_odds++;
        
        while((en < N) && (current_odds <= K))
        {
            en++;
            if(sequence[en] % 2 != 0) current_odds++;

        }
        //조건 (current_odds > K )에 의해 빠져나온 경우
        if(sequence[en] % 2 != 0){
            en--;  
            current_odds--;
        } 
        int current_length = (en - st + 1) - K;
        max_length = max(max_length, current_length);
        pre_st = st;
    }
    cout << max_length;
    return 0;
}