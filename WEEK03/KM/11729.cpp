#include <iostream>
#include <vector>
using namespace std;

int cnt=0;
vector<pair<int,int>> arr;
void hanoi(int s,int m,int e,int n){
    cnt++;
    if(n==1){
        arr.push_back({s,e});
        return;
    }
    else{
        hanoi(s,e,m,n-1);
        arr.push_back({s,e});
        hanoi(m,s,e,n-1);
    }
}

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin>>n;
    hanoi(1,2,3,n);
    cout<<cnt<<'\n';
    for(pair<int,int> cur:arr){
        cout<<cur.first<<' '<<cur.second<<'\n';
    }
    return 0;
}


/*
1	s:a e:c 
a c 한번

2   s:a e:c
a b
a c
b c 3번

3  s:a e:c //=sol(s:a e:b,n-1) +1 +sol(s:b e:c,n-1);

a c
a b
c b
a c
b a
b c
a c //7번 sol(n-1)+1(a to c)+sol(n-1)

a b
a c
b c
a b
c a
c b
a b
a c
*/