#include <iostream>
#include <stack>
#include <string.h>
using namespace std;


int main()
{
    while(true){
        string str;
        getline(cin,str); 
        if(str.compare(".")==0) break; //종료료
        stack<char> s;
        bool good=true; //플래그그
        for(int i=0;i<str.length();i++)
        {
            char cur=str[i];
            if(cur=='('){s.push(cur);}
            if(cur=='['){s.push(cur);}
            if(cur==')'){
                if(s.empty()){  //닫는거 들어왔는데 스택이 비어있으면
                    good=false;
                    break;
                }
                if(s.top()=='('){   //스택 탑에 (들어있으면
                    s.pop();
                }
                else{   //나머지지
                    good=false; 
                    break;
                }
            }
            if(cur==']'){   //위와 동일일
                if(s.empty()){
                    good=false;
                    break;
                }
                if(s.top()=='['){
                    s.pop();
                }
                else{
                    good=false;
                    break;
                }
            }
        }
        if(!s.empty()) good=false;  //스택이 안비어있는경우 ex- ()()((
        if(good) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}