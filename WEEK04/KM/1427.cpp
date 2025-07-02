#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10];


int main()
{
    cin>>n;
    int size=0;
    int tmp=n;
    while(tmp>10){
        arr[size++]=tmp%10;
        tmp/=10;
    }
    arr[size++]=tmp;
    sort(arr,arr+size,greater<int>());
    for(int i=0;i<size;i++)
    cout<<arr[i];
    //2143 214 21 2
    //3    4   1
    return 0;
}