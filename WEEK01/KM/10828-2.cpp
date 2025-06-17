#include <iostream>

using namespace std;

int arr[10001];
int top=-1;
int n;
void mypush(int x)  //top증가시키고 top에 x넣기
{
    top++;
    arr[top]=x;
}

void mypop()    //비어있으면 -1출력, else top출력하고 빼기
{
    if(top==-1){
        cout<<-1<<'\n';
    }
    else{
        cout<<arr[top]<<'\n';
        top--;
    }
}

void mysize()   //size=top+1
{
    cout<<top+1<<'\n';
}

void myempty()  //top=-1이면 비어있다는뜻 1출력 else 0출력
{
    if(top==-1)
        cout<<1<<'\n';
    else
        cout<<0<<'\n';
}

void mytop()    //비어있으면 -1출력 else top에 있는원소 출력
{
    if(top==-1)
        cout<<-1<<'\n';
    else
        cout<<arr[top]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        int x;
        cin>>s;
        if(s=="push")
        {
            cin>>x;
            mypush(x);
        }
        else{
            if(s=="pop"){
                mypop();
            }
            else if(s=="empty"){
                myempty();
            }
            else if(s=="size"){
                mysize();
            }
            else if(s=="top"){
                mytop();
            }
        }
    }
    return 0;
}