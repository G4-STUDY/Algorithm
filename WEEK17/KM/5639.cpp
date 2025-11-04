#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void print(int s,int e){
    if(s>=e)return;
    if(s==e-1){//단말노드면
        cout<<v[s]<<'\n';
        return;
    }
    int left=s+1;
    //왼쪽서브트리추출
    while(left<e){
        if(v[s]<v[left]){
            break;
        }
        left++;
    }
    //왼쪽서브트리 탐색
    print(s+1,left);
    //오른쪽 서브트리
    print(left,e);
    cout<<v[s]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x;
    while(cin>>x){
        v.push_back(x);
    }
    print(0,v.size());
    return 0;
}