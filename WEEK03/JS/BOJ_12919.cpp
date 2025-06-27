#include<bits/stdc++.h>
using namespace std;
//출력값
int is_possible = 0;
//입력 문자열을 뒤집어서 반환하는 함수 
string revStr(string str){
    string rev_str = "";
    int siz = str.size();
    for(int i = siz -1; i >= 0 ; i--){
        rev_str.push_back(str[i]);
    }
    return rev_str;
}
//백트래킹 함수 
void backtrack(string, string);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S = ""; //start
    string T = ""; //target
    //입력
    cin >> S >> T;
    backtrack(S, T);
    cout << is_possible;

    return 0;
}

void backtrack(string cur_str,string target){
    //종료 조건
    if (cur_str == target )
    {
        is_possible = 1;
        return;
    }
    
    //oper 1 = A추가 oper 2 = B 추가, 뒤집기
    for(int oper=1; oper<=2; oper++){
        if(oper == 1){
            string nxt_str = cur_str;
            nxt_str.push_back('A');  //A 추가한 문자열
            string rev_str = revStr(nxt_str); //A 추가하고 뒤집은 문자열
            //A추가한 문자열, 뒤집은 문자열 둘다 포함안되면 pass
            if(target.find(nxt_str) == string::npos && target.find(rev_str) == string::npos) continue;
            //포함되면 다음 level
            backtrack(nxt_str, target);
           
        }
        else{
            string nxt_str = cur_str;
            nxt_str.push_back('B');
            string rev_str = nxt_str; //B 추가한 문자열 (연산 처리 후 뒤집은 문자열)
            nxt_str = revStr(nxt_str);// B 추가하고 뒤집은 문자열 
            //둘다 포함안되면 pass
            if(target.find(nxt_str) == string::npos && target.find(rev_str) == string::npos) continue;
            //포함되면 다음 level
            backtrack(nxt_str, target);
            
        }
    }
}

