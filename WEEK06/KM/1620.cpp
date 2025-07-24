#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> sm;
unordered_map<int, string> im;

bool isnumber(string s) //숫자인지 문자인지 구별용
{
    for (char c : s)
    {
        if (c < '0' || '9' < c)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    string name;
    for (int i = 1; i <= n; i++)
    {
        cin >> name;
        sm[name] = i;
        im[i] = name;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> name;
        if (isnumber(name))
        {   //숫자면
            cout << im[stoi(name)] << '\n';
        }
        else
        {   //문자면
            cout << sm[name] << '\n';
        }
    }
    return 0;
}
