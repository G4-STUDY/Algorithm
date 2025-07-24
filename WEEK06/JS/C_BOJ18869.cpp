#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> univ_planet[100];
    vector<int> univ_rank[100];
    int M,N;
    int result = 0;
    cin >> M >> N;
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int planet_size;
            cin >> planet_size;
            univ_planet[i].push_back(planet_size);
        }
    }
    //각 행성에 대해 크기에 대한 rank 저장
    for(int i = 0; i < M; i++)
    {
        vector<int> sorted_planet;
        for(int i : univ_planet[i])
        {
            sorted_planet.push_back(i);
        }
        sort(sorted_planet.begin(), sorted_planet.end());
        for(int j = 0; j < N; j++)
        {
            int cur_size = univ_planet[i][j];
            int rank = lower_bound(sorted_planet.begin(), sorted_planet.end(), cur_size)
                       - sorted_planet.begin();
            univ_rank[i].push_back(rank);
        }
    }
    //rank 벡터 같은 행성쌍 찾기 
    for(int i = 0; i < M-1; i++)
    {
        for(int j = i + 1; j < M; j++)
        {
            bool is_equal = true;
            for(int k = 0; k < N; k++)
            {
                if(univ_rank[i][k] == univ_rank[j][k]) continue;
                else
                {
                    is_equal = false;
                    break;
                }
            
            }
            if(is_equal == true) result++;
        }
    }
    cout << result; 
    return 0;
}