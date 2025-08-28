#include <string>
#include <vector>
#include <iostream>
using namespace std;

int map[103][103];

int Rotate(int x1, int y1, int x2, int y2) {
    int min = 10001;
    int temp1 = map[x1][y1];
    int temp2 = 0;
    for (int w = y1; w < y2; w++) {
        if (min > temp1) min = temp1;
        temp2 = map[x1][w + 1];
        map[x1][w + 1] = temp1;
        temp1 = temp2;
    }
    for (int w = x1; w < x2; w++) {
        if (min > temp1) min = temp1;
        temp2 = map[w + 1][y2];
        map[w + 1][y2] = temp1;
        temp1 = temp2;
    }
    for (int w = y2; w > y1; w--) {
        if (min > temp1) min = temp1;
        temp2 = map[x2][w - 1];
        map[x2][w - 1] = temp1;
        temp1 = temp2;
    }
    for (int w = x2; w > x1; w--) {
        if (min > temp1) min = temp1;
        temp2 = map[w - 1][y1];
        map[w - 1][y1] = temp1;
        temp1 = temp2;
    }
    return min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int temp = 1;
    for (int u = 1; u <= rows; u++) {
        for (int v = 1; v <= columns; v++) {
            map[u][v] = temp++;
        }
    }
    for (int u = 0; u < queries.size(); u++) answer.push_back(Rotate(queries[u][0], queries[u][1], queries[u][2], queries[u][3]));
    return answer;
}
