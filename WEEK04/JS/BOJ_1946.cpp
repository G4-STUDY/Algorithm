//백준1946 신입사원 
#include<bits/stdc++.h>
using namespace std;
//pair<int, int> 배열에 대해 first 기준 오름차순 정렬 
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) // T <= 20
    {   
        int can_hire = 0;
        int N; 
        cin >> N;
        vector<pair<int, int>> ranks;
        for(int i = 0; i < N; i++) //
        {
            pair<int, int> rank;
            cin >> rank.first >> rank.second;
            ranks.push_back(rank);
        }
        //first 기준 정렬 
        sort(ranks.begin(), ranks.end());
       
        /*
        //만족 여부 확인->첫번째 요소는 무조건 선발 가능->인덱스 1부터 시작 완전탐색-> O(N^2) ->시간초과
        for(int i = 1; i < N; i++){
            for(int j = 0 ; j < i ; j++ )
            {
                //자신 앞에 secnod가 더 작은 요소 하나라도 있으면 cant_hire 증가 
                if(ranks[i].second > ranks[j].second)
                {
                    cant_hire++;
                    break;
                }
            }
        }
        */

        //O(N) 최적화 
        int prev_min_rank2 = N+1; //자신보다 서류 rank 작은 사람들의 면접 rank 최솟값  
        for(int i =0; i < N; i++)
        {
            //앞사람(서류순위 높은 사람) 중 나보다 면접순위 낮은 사람있으면 고용 가능 
            //앞사람 전체가 아니라 앞사람중 가장 면접 점수 높은사람(rank1 작은 사람)과 비교
            if(prev_min_rank2 > ranks[i].second )
            {
                can_hire++;
                prev_min_rank2 = ranks[i].second;
            }
        }
       
        
        cout << can_hire << '\n';
        
    }
    return 0;
}
/*
N^2 X => NlogN O

3 2 t
1 4 t
4 1 t
2 3 t
5 5 f  
rank1 기준 정렬           
1 4                       
2 3                        
3 2                        
4 1                       
5 5 f                     

7
3 6  f (1 4) (2 5)
7 3  f (4 2) (6 1)
4 2  t
1 4  t
5 7  f (3 6) (2 5) (4 2) (1 4)
2 5  f (1 4)
6 1  t
rank1 기준 정렬 
1 4
2 5 f
3 6 f
4 2
5 7 f
6 1
7 3 f

*/