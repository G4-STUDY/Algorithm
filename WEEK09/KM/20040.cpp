#include <iostream>

using namespace std;

int p[500001];
int n, m;
bool flag = true;
int answer=0;

int find(int x)
{
    if (x == p[x])
        return x;
    return p[x] = find(p[x]);
}

void myunion(int a, int b)
{
    if (b < a)
        swap(a, b);
    p[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        p[i] = i;
    int idx=m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a = find(a);
        b = find(b);
        if (flag)//게임진행중인지
        {
            if (a == b)
            {   
                //같은집합이면 게임종료
                flag = false;
                //정답갱신
                answer=idx-m;
            }
            else
            {
                myunion(a,b);
            }
        }
    }
    cout<<answer;
    return 0;
}