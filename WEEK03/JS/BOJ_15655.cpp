#include<bits/stdc++.h>
using namespace std;

int N, M;
int Arr[10];
vector<int> nums;
void MakeArr(int depth, int st_idx){
    if(depth == M){
        for(int i = 0; i < M; i++){
            cout << Arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = st_idx; i < N; i++ ){
        Arr[depth] = nums[i];
        MakeArr(depth + 1, i + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int tmp;
    for(int i = 0; i < N; i++){
       cin >> tmp;
       nums.push_back(tmp);
    }
    sort(nums.begin(), nums.end());
    MakeArr(0, 0);
    
    return 0;

}