#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, bool> m;
int n;
vector<string> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    string name, op;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> op;
        if (op == "enter") //출근
        {
            m[name] = true;
        }
        else                //퇴근
        {
            m.erase(name);
        }
    }
    for (auto it : m)
    {
        ans.push_back(it.first);//map에 있는 이름 넣기
    }
    //정렬
    sort(ans.begin(), ans.end(), greater<string>());
    for (string s : ans)
    {
        cout << s << '\n';
    }
    return 0;
}