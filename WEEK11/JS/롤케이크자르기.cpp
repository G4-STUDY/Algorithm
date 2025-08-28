#include <string>
#include <vector>
#include <unordered_set>
#include <map>
using namespace std;
unordered_set<int> chulsoo_set;
unordered_set<int> sister_set;
map<int,int> sister_map;
int solution(vector<int> topping) {
    int answer = 0;
    //여동생 set, map 채우기 
    for(int i : topping)
    {
        sister_set.insert(i);
        if(sister_map.find(i) != sister_map.end())
        {
            sister_map[i] += 1;
        }
        else
        {
            sister_map[i] = 1;
        }
    }
    
    for(int i : topping)
    {
        //여동생 현재 토핑 빼서 철수에 넣고 종류 수 비교
        sister_map[i] -= 1;
        if(sister_map[i] == 0)
        {
            sister_set.erase(sister_set.find(i));
        }
        chulsoo_set.insert(i);
        if(chulsoo_set.size() == sister_set.size()) answer++;
    }
    
    return answer;
}