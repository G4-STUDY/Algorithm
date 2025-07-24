#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

int k, l;
unordered_map<string, bool> m;
string arr[500001];
stack<string> s;//먼저들어온순서대로 나가야되는데 뒤에서부터 넣을거야
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k >> l;
    for (int i = 0; i < l; i++)
    {
        cin >> arr[i];
    }
    for (int i = l - 1; i >= 0; i--)
    {//뒤에서부터 체크
        if (m[arr[i]])//이미 체크했으면 패스
            continue;
        m[arr[i]] = true;
        s.push(arr[i]);//스택에 넣기
    }
    while (!s.empty() && k--)
    {
        string stuid = s.top();
        s.pop();//스택에서 뽑기
        cout << stuid << '\n';
    }
    return 0;
}