#include <bits/stdc++.h>
using namespace std;

void readInput(string &base_name, vector<string> &process, vector<int> &time_taken,
               string &target_name, int &target_qty);

void printInput(const string &base_name, const vector<string> &process,
                const vector<int> &time_taken, const string &target_name, int target_qty);

//자원 -> idx
unordered_map<string,bool> check;
unordered_map<string,int> adapter;

unordered_map<int,int> dist;
int solution(string base_name, vector<string> process, vector<int> time_taken,
                string target_name, int target_qty)
{
    int trans=1;
    int answer = 0;
    // 여기에 코드 구현
    for(string str:process){
        stringstream ss(str);
        string s;
        int idx=0;
        string astr,bstr;
        int acount,bcount;
    return answer;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    string base_name, target_name;
    vector<string> process;
    vector<int> time_taken;
    int target_qty;

    readInput(base_name, process, time_taken, target_name, target_qty); // 입력
    // printInput(base_name, process, time_taken, target_name, target_qty); // 출력 (입력 확인용)

    int result = solution(base_name, process, time_taken, target_name, target_qty);
    cout << result << "\n";

    return 0;
}

void readInput(string &base_name, vector<string> &process, vector<int> &time_taken, string &target_name, int &target_qty)
{
    int n; // 레시피 개수
    cin >> n;
    cin >> base_name;

    cin.ignore();

    // 레시피 n줄을 그대로 읽기
    process.resize(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, process[i]);
    }

    // time_taken n개
    time_taken.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> time_taken[i];
    }

    // target
    cin >> target_name >> target_qty;
}

void printInput(const string &base_name, const vector<string> &process,
                const vector<int> &time_taken, const string &target_name, int target_qty)
{
    cout << "base_name: " << base_name << "\n";
    cout << "process:\n";
    for (auto &p : process) cout << p << "\n";

    cout << "time_taken:\n";
    for (auto &t : time_taken) cout << t << " ";
    cout << "\n";

    cout << "target_name: " << target_name << "\n";
    cout << "target_qty: " << target_qty << "\n";
}


/** 예제 1

2
iron_ore
iron_ore 1 iron_ingot 1
iron_ingot 2 iron_plate 1
3
2
iron_plate
3

 */

/** 예제 2

3
a
a 1 b 1
a 1 c 1
b 1 c 1 d 1
2
5
1
d
1

 */

/** 예제 3

4
a
a 2 b 1
a 1 c 1
b 1 c 2 d 1
d 1 a 3 e 1
3
2
4
5
e
1
 */
 /*
 a->b->...->d->e
 결국 e를 만드는데 a가 몇개필요하고 얼마나 걸리는지 나오게되어있다..


 target_qty=100
 10개로 100개를 만들수있는데 공정과정 100000초 (10초+100000초)
 vs
 100000개로 100개를 만드는데 공정과정이 1초(100000초+1초)
 target_qty=200
 10개로 100개를 만들수있는데 공정과정 100000초 (20초+100000초)
 vs
 100000개로 100개를 만드는데 공정과정이 1초(200000초+1초)
 
 최단경로 불가능..

 일단 start -> end 가 가능한 경로들 찾기
 경로들마다 필요 start개수,처리과정,end개수 가 나올것
 경로 1과 경로2가 있을때
 10번은 경로1로 한번은 경로2로 처럼 섞여서 걸릴수도있음..
 
 start개수 + 처리과정

 1->1개 만드는데 10초
 2->5개 만드는데 20초
 21개만들어

 9+10초
 vs
 8+20초

 28초걸림;;

start 2 -> end 1
start 6 -> end 3
6+5 정답


문제이해를 잘못했나..
1
2
3 병렬로 3개
4
5


모든 레시피는 서로 다른자원을 출력한다..
즉 경로는 하나다...

a->b 2초
a->c 5초
b,c->d 1초
start=2 처리과정 5
a->c=6초
a->b=3초

4b,c->d 1초

1   c
2   b
3   b
4   b B
5   b B
6   C B
7   B
8   D

a to d = 8초 왜?

a -> b 가 
                  왜?2
start=5 처리과정=3(2+1);

4a to 4b
(start+처리과정)
4+2
a to c
(start+처리과정)
1+5



b c to d =
start+min(처리과정)
vs
max(처리과정)
하나의 묶음으로 봐야되나
start+처리과정=처리과정으로?
  st,time
a=(1,5);
b=(1,1);
end=(a,b,1);
end=(출발시간,걸리는시간)


//
dist[b]=3;
dist[c]=2;
dist[d]=4;
dist[]

start개수+처리과정
vs
start개수+처리과정
중에 큰거?


일단 끝나는시간이 가장 오래걸리는 작업부터 
시작

그뒤로 오래안걸리는작업 시작
1a + 3b +5c 야
근데 a만드는작업이 10초걸리고
b만드는작업이 2초걸려
c도있어 ㅋㅋㅋ
c=1초걸려 ㅋㅋ

a+atime=11
a+b+btime=6
a+b+c+ctime=9+1=10
11초 가걸려 결국
1   a
2   b
3   b
4   b   B
5   c   B
6   c   B   C
7   c   C
8   c   C
9   c   C
10  C
11  A
12
13
14
요약해보자
start 9개가 필요했고 end가 되는데 11초 걸렸어

1d+5s=e

req time
1d(9, 11)
5s(1, 0)
11
vs
9+5=14

1e(10,14)이렇게 되는게 맞나 한번해보자

                        첫등장
        req  subtime + time  = first
iron_ingot(1    3)=     4초
iron_plate(2    2)=     7초
3*iron_plate=(6  5)=     11초
                time    =  준비물준비시간   내처리과정
                time    =  subtime     +   mytime
만약
iron_end=iron_ingot+3*iron_plate이고 처리과정은 5초야
    req time    first  
subtime=
3*(iron_plate_req)+(iron_plate_time)
vs
3*(ironignot_req)+1*(iron_ignot_req)+(iron_ignot_time)
=
6+5=11
vs
3+1+3=7
준비물준비시간
subtime=11
time=11+5=16

        필요개수    준비물시간 처리시간     첫등장
c=
        req         subtime + time      = first
ore     1           0         0         1
ingnot  1           1         3         4
plate   2           5         2         7
1plate  2           7         0         7
3*plate 6           11        0         11



*/