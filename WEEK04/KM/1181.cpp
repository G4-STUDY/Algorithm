#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n;

string v[20001];
map<string,bool> m;

bool comp(string a,string b){
    for(int i=0;i<a.length();i++){
       if(a[i]!=b[i]){
        return a[i]<b[i];
       } 
    }
    return true;
}

bool lencomp(string a,string b){
    if(a.length()==b.length()){
        return comp(a,b);
    }
    return a.length()<b.length();
}

int main(){
    int dup=0;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(m[s]){
            dup++;
        }
        else{
            v[i-dup]=s;
            m[s]=true;
        }
    }
    n-=dup;
    sort(v,v+n,lencomp);
    for(int i=0;i<n;i++){
        cout<<v[i]<<"\n";
    }
    return 0;
}