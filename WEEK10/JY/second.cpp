#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

void readInput(string &base_name, vector<string> &process, vector<int> &time_taken,
               string &target_name, int &target_qty);

void printInput(const string &base_name, const vector<string> &process,
                const vector<int> &time_taken, const string &target_name, int target_qty);

priority_queue<pair<int, int> > pq;

void func(string target, int qty, int limit, string base_name, vector<string> process, vector<int> time_taken) {

    if (target == base_name) {
        pq.push(make_pair(limit, qty));
        return;
    }

    for (int i=process.size()-1; i>=0; i--) {
        string info = process[i];
        vector<string> tokens;
        string token;

        // 문자열 자르기
        istringstream iss(info);
        while (iss >> token) {
            tokens.push_back(token);
        }

        // target 아니면 넘어감
        if (tokens[tokens.size()-2].compare(target) != 0) continue;

        for (int j=0; j<tokens.size()-2; j+=2) {
            func(tokens[j], qty * stoi(tokens[j+1]), limit + time_taken[i], base_name, process, time_taken);
        }

    }

}


int solution(string base_name, vector<string> process, vector<int> time_taken,
                string target_name, int target_qty)
{
    func(target_name, target_qty, 0, base_name, process, time_taken);

    int answer = 0;
    int sum = 0;
    while (!pq.empty()) {
        int x = pq.top().first;
        int y = pq.top().second;
        //cout << x << " " << y << "\n";
        sum += y;
        answer = max(answer, x + sum);
        pq.pop();
    }

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


/**
* 3
a
a 1 b 1
a 100 c 1
b 1 c 1 d 1
100
1
5
d
1
 */