//백준 2240 자두나무 
#include<iostream>
using namespace std;

int positionChange(int cur_pos)
{
    if(cur_pos == 1) return 2;
    else return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int result = 0; //받은 자두 수 
    int cur_pos = 1; //현재 사람 위치 (1 or 2) 
    int falling_pos; //현재 떨어지는 나무 위치 
    int T; //떨어지는 시간 1<=T<=1000
    int W; //최대 이동 횟수 1<=W<=30 

    cin >> T >> W;

    while(T--)
    {
        cin >> falling_pos;
        
    }

    cout << result;

    return 0;
}

/*
1에 있는데 2에서 떨어짐 -> 이동하는게 나을까 안하는게 나을까 
이동안하면 2초,3초에 안움직이고 2개받을 수 있음
이동하면 1초에 받지만 2초 3초에는 못받음
*/