#include <iostream>

using namespace std;

int n, k;
int arr[200001];
int record[100001];//idx 값이 몇번 등장했는지
int ans = 0;

int main()
{
    cin >> n >> k;
    int l = 0;//수열 시작idx
    for (int i = 0; i < n; i++)
    { // i=r임
        cin >> arr[i];
        if (++record[arr[i]] > k)//겹치는게 k번 이상이면
        {
            ans = max(ans, i - l);
            while (l < i)//수열에서 빼기
            {
                record[arr[l]]--;
                l++;
                if (arr[l - 1] == arr[i]) // 방금뺀게 지금나온거면
                    break;
            }
        }
    }
    ans = max(ans, n - l); // 마지막 검사
    cout << ans;
    return 0;
}
/*

*/