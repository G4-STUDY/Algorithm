#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
int arr[10001];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    long long ans = 0; // 답은 10000C3이라 int범위 밖
    int l, r, mid, tmp, low;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            tmp = arr[i] + arr[j];
            l = j + 1;
            r = n; // n-1이 아니라 n으로 해야댐;;
            while (l < r)//lowerbound
            {
                mid = (l + r) / 2;
                if (tmp + arr[mid] < 0)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
            if (l == n)
                continue;
            if (tmp + arr[l] == 0)//합이 0이되면
            {
                low = l;
                tmp = arr[l];
                r = n;
                while (l < r)//upperbound
                {
                    mid = (l + r) / 2;
                    if (arr[mid] <= tmp)
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid;
                    }
                }
                ans += l - low;
            }
        }
    }
    cout << ans;
    return 0;
}

/*
n=10000
n^2 이하로?
n^2*log(n)도 되나
15퍼에서 틀림
*/