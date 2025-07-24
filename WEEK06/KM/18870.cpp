#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n;
int arr[1000001];
int myarr[1000001];
unordered_map<int, bool> m; //이미 나왔던 값 체크용
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int len = 0;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr[i] = x;
        if (m[x])//이미 나온값이면
            continue;
        m[x] = true;
        myarr[len] = x; //값저장용
        len++;
    }
    sort(myarr, myarr + len);//이분탐색용 정렬
    int l = 0;
    int r = len - 1;
    int mid;
    for (int i = 0; i < n; i++)
    {
        x = arr[i];
        l = 0;
        r = len - 1;
        while (l < r)//lowerbound
        {
            mid = (l + r) / 2;
            if (x <= myarr[mid])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << l << ' ';
    }

    return 0;
}
//이럴거면 그냥 정렬해놓고 map에다 넣고 해도 되지않았나