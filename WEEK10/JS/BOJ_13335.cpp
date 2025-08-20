#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //대기 트럭
    queue<pair<int, int>> waitings;
    //현재 다리위 트럭
    queue<pair<int, int>> bridges;
    int n, w, L;
    cin >> n >> w >> L; //트럭수, 다리 길이, 최대 하중
    for(int i = 0; i < n; i++)
    {
        int wei;
        cin >> wei;
        waitings.push({wei, 0}); //{트럭무게, 이동한 다리 칸 수}
    }
    int sec = 0;
    int cur_wei = 0; // 현재 하중 
   
    while(!waitings.empty() || !bridges.empty())
    {
        sec++;
        //1.현재 다리에 있는 트럭 한칸 이동(앞에있는 트럭부터)
        int on_bridge_num = bridges.size(); //현재 다리 위 트럭 수 
        for(int i = 0; i < on_bridge_num; i++)
        {
            pair<int, int> cur_truck = bridges.front();
            bridges.pop();
            int cur_truck_wei = cur_truck.first;
            int move_dist = cur_truck.second + 1; //한칸 앞으로 이동
            cur_wei -= cur_truck_wei;
            if(move_dist <= w)
            {
                 bridges.push({cur_truck_wei, move_dist}); //아직 다리 다안지났으면 큐에 다시 넣기 
                 cur_wei += cur_truck_wei;
            //다리 모두 지난 트럭(move_dist > w)은 다시 큐에 포함 x 
            }
        }
        //2.가장앞에서 대기중인 트럭 올라올 수 있는 지 확인 
        if(waitings.empty()) continue;
        pair<int, int> first_waiting = waitings.front();
        if(cur_wei + first_waiting.first <= L)
        {
            //올라올 수 있다면 waitings 큐에서 빼고 bridges 큐에 넣기 
            waitings.pop();
            bridges.push({first_waiting.first, 1});
            cur_wei += first_waiting.first; //현재 하중 갱신 
        }

        
    }

    cout << sec;
    return 0;
}

