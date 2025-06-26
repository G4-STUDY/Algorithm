#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define X first
#define Y second

int board[102][102];

int N, apple_cnt, command_cnt;
int apple_x, apple_y;

queue<int> command_sec;
queue<char> command;
queue<pair<int, int>> Snake;

int Time_Sec;
int Snake_Head_x, Snake_Head_y;


int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int turn_val = 100;

void SnakeMove() {
	while (1) {
		pair<int, int> cur = { Snake_Head_x, Snake_Head_y };
		Snake.push(cur);
		if (!command.empty()) {
			if (command_sec.front() == Time_Sec) {
				command_sec.pop();
				if (command.front() == 'L') {
					turn_val--;
					command.pop();
				}
				else if (command.front() == 'D') {
					turn_val++;
					command.pop();
				}
			}
		}
		Snake_Head_x += dx[turn_val % 4];
		Snake_Head_y += dy[turn_val % 4];
		if (Snake_Head_x < 0 || Snake_Head_x >= N || Snake_Head_y < 0 || Snake_Head_y >= N) {
			Time_Sec++;
			return;
		}
		if (board[Snake_Head_x][Snake_Head_y] == 1) {
			Time_Sec++;
			return;
		}
		cur = Snake.front();
		if (board[Snake_Head_x][Snake_Head_y] != 4) {
			board[cur.X][cur.Y] = 0;
			Snake.pop();
		}
		board[Snake_Head_x][Snake_Head_y] = 1;
		
		Time_Sec++;
	}
}

int main(void) {
	cin >> N >> apple_cnt;
	for (int u = 0; u < N; u++) {
		for (int v = 0; v < N; v++) {
			board[u][v] = 0;
		}
	}
	for (int u = 0; u < apple_cnt; u++) {
		cin >> apple_x >> apple_y;
		board[apple_x - 1][apple_y - 1] = 4;
	}

	cin >> command_cnt;
	for (int u = 0; u < command_cnt; u++) {
		int tempint;
		char tempchar;
		cin >> tempint >> tempchar;
		command_sec.push(tempint);
		command.push(tempchar);
	}
	board[0][0] = 1;
	SnakeMove();
	cout << Time_Sec;
	return 0;
}
