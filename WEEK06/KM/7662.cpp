#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
int T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;//testcase
    while (T--)
    {
        priority_queue<int> pq;
        priority_queue<
            int,
            vector<int>,
            greater<int>>
            pq2;
        unordered_map<int, int> m; //
        int k, num = 0, dnum = 0;
        cin >> k;//쿼리수
        while (k--)
        {
            char c;
            int a;
            cin >> c;
            if (c == 'I')//넣기
            {
                cin >> a;
                pq.push(a);
                pq2.push(a);
                m[a]++;
                num++;
            }
            else
            {//빼기
                cin >> a;
                if (num - dnum == 0)//큐가 비어있으면
                    continue;
                dnum++;//뺀개수++
                if (a == 1)//최대값 큐에서 빼기
                {
                    while (m[pq.top()] == 0)//이미 다른큐에서 빠진게 아닐때까지
                    {
                        pq.pop();
                    }
                    m[pq.top()]--;
                    pq.pop();
                }
                else//최소값 큐에서 뺴기
                {
                    while (m[pq2.top()] == 0)//이미 다른큐에서 빠진게 아닐때까지
                    {
                        pq2.pop();
                    }
                    m[pq2.top()]--;
                    pq2.pop();
                }
            }
        }

        while (!pq.empty() && m[pq.top()] == 0)//pq.top() 찍어야되니까 이미 빠진거 다빼기
        {
            pq.pop();
        }
        while (!pq.empty() && m[pq2.top()] == 0)
        {
            pq2.pop();
        }
        if (num - dnum == 0)//개수 빼기 뺀거 개수 =0 이면 empty 
            cout << "EMPTY\n";
        else
            cout << pq.top() << ' ' << pq2.top() << '\n';
    }
    return 0;
}
/*
큐두개쓰고 맵으로 몇개인지 관리해서 이미 삭제한건 빼기

*/