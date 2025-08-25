#include <string>
#include <vector>

using namespace std;

int lt[10001];
int rt[10001];
int l=0;
int r=0;

int solution(vector<int> topping) {
    int answer = 0;
    int cut=0;
    for(int i=0;i<topping.size();i++){//일단 왼쪽 0% 오른쪽100%
        int t=topping[i];
        if(rt[t]==0)r++;
        rt[t]++;        
    }
    for(int i=0;i<topping.size();i++){//
        int t=topping[i];
        if(lt[t]==0)l++;
        lt[t]++;
        rt[t]--;
        if(rt[t]==0)r--;
        if(l==r)
            answer++;
    }
    return answer;
}