#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    for(int i=1; i<=rows; i++){
        for(int j=1; j<=columns; j++){
            arr[i][j] = (i-1) * columns + j;
        }
    }

    for(vector<int> query : queries){
        int x1 = query[0];
        int y1 = query[1];
        int x2 = query[2];
        int y2 = query[3];

        int cur = arr[x1][y1];
        int nxt = arr[x1][y1+1];
        int minVal = 100000;

        for(int i=y1+1; i<=y2; i++){
            minVal = min(minVal, cur);
            arr[x1][i] = cur;
            cur = nxt;

            if(i == y2) nxt = arr[x1+1][i];
            else nxt = arr[x1][i+1];
        }

        for(int i=x1+1; i<=x2; i++){
            minVal = min(minVal, cur);
            arr[i][y2] = cur;
            cur = nxt;

            if(i == x2) nxt = arr[i][y2-1];
            else nxt = arr[i+1][y2];
        }

        for(int i=y2-1; i>=y1; i--){
            minVal = min(minVal, cur);
            arr[x2][i] = cur;
            cur = nxt;

            if(i == y1) nxt = arr[x2-1][i];
            else nxt = arr[x2][i-1];
        }

        for(int i=x2-1; i>=x1; i--){
            minVal = min(minVal, cur);
            arr[i][y1] = cur;
            cur = nxt;

            nxt = arr[i-1][y1];
        }

        answer.push_back(minVal);
    }


    return answer;
}