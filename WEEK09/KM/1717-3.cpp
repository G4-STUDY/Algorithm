#include <iostream>

using namespace std;

int n,m;
int p[1000001]; //집합! 제일작은게 대표!

int find(int x){//집합 대표찾기
    if(x==p[x]) return x;
    return p[x]=find(p[x]);//찾으면서 갱신하기!
}

void myunion(int a,int b){//union!
    //대표끼리 union해야댐
    a=find(a);
    b=find(b);
    //이미 같은집합
    if(a==b) return;
    //둘중 작은수가 a로
    if(b<a)
    swap(a,b);
    //union
    p[b]=a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    //집합초기화
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    while(m--){
        //query, a, b
        int q,a,b;
        cin>>q>>a>>b;
        if(q==0){
            //union
            myunion(a,b);
        }
        else{
            //대표찾기
            a=find(a);
            //대표찾기
            b=find(b);
            //같은집합이면
            if(a==b)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}