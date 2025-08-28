#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int n = rows * columns;
    int arr[101][101];
    int num = 1;
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            arr[i][j] = num;
            num++;
        }
    }
    for(vector<int> query : queries){
        int min_val = 20000;
        int st_row = query[0];
        int st_col = query[1];
        int en_row = query[2];
        int en_col = query[3];
        queue<int> q;
        //
        q.push(arr[st_row + 1][st_col]);
        min_val = min(min_val, arr[st_row + 1][st_col]);
        for(int i = st_col; i <= en_col; i++){
            q.push(arr[st_row][i]);
            min_val = min(min_val, arr[st_row][i]);
        }
        for(int i = st_row + 1; i <= en_row - 1; i++){
            q.push(arr[i][en_col]);
            min_val = min(min_val, arr[i][en_col]);
        }
        for(int i = en_col; i >= st_col ; i--){
            q.push(arr[en_row][i]);
            min_val = min(min_val, arr[en_row][i]);
        }
        for(int i = en_row - 1; i >= st_row + 2; i--){
            q.push(arr[i][st_col]);
            min_val = min(min_val, arr[i][st_col]);
        }
        
        //큐에서 하나씩 빼서 넣기 
        for(int i = st_col; i <= en_col; i++){
            arr[st_row][i] = q.front(); q.pop();
        }
        for(int i = st_row + 1; i <= en_row - 1; i++){
            arr[i][en_col] = q.front(); q.pop();
        }
        for(int i = en_col; i >= st_col; i--){
            arr[en_row][i] = q.front(); q.pop();
        }
        for(int i = en_row - 1; i >= st_row + 1; i--){
            arr[i][st_col] = q.front(); q.pop();
        }
        //최솟값 저장
        answer.push_back(min_val);
    }
    
    return answer;
}
