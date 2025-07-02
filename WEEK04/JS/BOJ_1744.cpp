//백준 1744 수묶기
#include<bits/stdc++.h>
using namespace std;
//내림차순 비교함수 
bool cmp(int a, int b)
{
    return a > b;
}
vector<int> negative_and_zero; //음수, 0 저장 
vector<int> positive; //1 제외한 양수 저장 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int max_sum = 0;
    int N;
    cin >> N;
    int num;
    for(int i = 0; i < N;i++)
    {
        cin >> num;
        if(num <= 0) negative_and_zero.push_back(num);
        else if(num == 1) max_sum +=1; //1은 무조건 안묶고 더하기
        else positive.push_back(num);
    }
    sort(negative_and_zero.begin(), negative_and_zero.end(),cmp);// 
    sort(positive.begin(), positive.end());

    int cnt = 0; //현재 묶인 원소 수 
    int tmp = 1; //묶음의 누적곱
    //2 3 4 5 or 2 3 4 
    while(!positive.empty())
    {
        int cur = positive.back(); positive.pop_back();
        cnt++;
        tmp = tmp * cur; //6
        //두개 묶은 경우 곱해서 합에 더하기 
        if(cnt ==2)
        {
            max_sum += tmp; //20 + 6
            cnt = 0;
            tmp = 1;
            continue;
        }
        //마지막 하나의 원소일때 
        if(positive.empty()) 
        {
            max_sum += tmp;
            cnt = 0;
            tmp = 1;
            break;
        }
        //-1   4 
    }
    //-2 or 0,-1,-2,-3 or -1,-2,-3,-4 
    while(!negative_and_zero.empty())
    {
        int cur = negative_and_zero.back(); negative_and_zero.pop_back();
        cnt++;
        tmp = tmp*cur;
        //두개 묶은 경우 곱해서 합에 더하기
        if(cnt ==2)
        {
            max_sum+=tmp;
            cnt = 0;
            tmp = 1;
            continue;
        }
        //마지막 하나의 원소일때 
        if(negative_and_zero.empty()) 
        {
            max_sum += tmp;
            cnt = 0;
            tmp = 1;
            break;
        }
        
    }
    cout << max_sum;
    return 0;
}
 



