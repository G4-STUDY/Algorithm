#include <iostream>

using namespace std;

int p[1000001];

int find(int x)
{
    if (x == p[x])
        return x;
    return p[x] = find(p[x]);
}

void myunion(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (b < a)
        swap(a, b);
    p[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int idx=t;
    while (t--)
    {
        cout<<"Scenario "<<idx-t<<":\n";
        int n, k;
        cin >> n >> k;
        for(int i=1;i<=n;i++){
            p[i]=i;
        }
        while (k--)
        {
            int a, b;
            cin >> a >> b;
            //union시키기
            myunion(a, b);
        }
        int m;
        cin >> m;
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            u = find(u);
            v = find(v);
            //같은 집합이면
            if (u == v){
                cout<<"1\n";
            }
            else{
                cout<<"0\n";
            }
        }
        cout<<'\n';
    }
    return 0;
}