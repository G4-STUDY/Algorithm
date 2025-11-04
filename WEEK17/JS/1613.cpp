/*1613 역사*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k; 
    bool dist[401][401]; // dist[i][j] == true <=> i->j 경로 존재 
    //초기화 
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(i == j) dist[i][j] = true; //자기 자신으로는 항상 연결 
            dist[i][j] = false;
        }
    
    for(int i = 0; i < k; i++){
        int s1, s2;
        cin >> s1 >> s2;
        dist[s1][s2] = true; //방향 o
    }

    //dist배열 갱신 - 플로이드 
    for(int mid = 1; mid <= n; mid++)
        for(int st = 1; st <= n; st++)
            for(int en = 1; en <= n; en++){
                if(dist[st][mid] && dist[mid][en]) dist[st][en] = true;
            }
        
        
    //케이스 입력받고 결과 판단 후 출력 
    int s;
    cin >> s;
    vector<int> result;
    for(int i = 0; i < s; i++){
        int s1, s2;
        cin >> s1 >> s2;
        if(dist[s1][s2] == true) result.push_back(-1);
        else if(dist[s2][s1] == true) result.push_back(1);
        else result.push_back(0); //둘다 false인 경우 
    }
    for(int r : result) cout << r << '\n';

    return 0;
}

/*

전체 사건 중 일부 사건의 전후 관계 주어짐
사건 주어질 때 전후 관계 알 수 있는지 검증 
    전후 관계 알 수 있으면 
        앞의 사건 먼저 -> -1
        뒤의 사건 먼저 -> 1
        알 수 없으면 -> 0

ex)
사건 수 n (노드) , 전후 관계 수 k (간선)
1 2 주어지면 1 -> 2라는 의미
전후 관계 알고 싶은 두 사건의 수 s   
노드 번호 1~n 

연결 여부 + n<=1000 -> 플로이드 응용 

*/