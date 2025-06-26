#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct _Egg {
	int def;
	int atk;
};
_Egg Egg[10];
_Egg EggTemp[10];

int N;
int arr[10];
int picked[10];
int broken[10];
int pattern[8][7] =
{ { 2, 3, 4, 5, 6, 7, 8},
  { 1, 3, 4, 5, 6, 7, 8},
  { 1, 2, 4, 5, 6, 7, 8},
  { 1, 2, 3, 5, 6, 7, 8},
  { 1, 2, 3, 4, 6, 7, 8},
  { 1, 2, 3, 4, 5, 7, 8},
  { 1, 2, 3, 4, 5, 6, 8},
  { 1, 2, 3, 4, 5, 6, 7} };

int pick, hit;
int Max = 0;
int temp;
void EggBreak(int cnt) {
	if (cnt == N) {
		for (int i = 1; i <= N; i++) {
			Egg[i].def = EggTemp[i].def;
			Egg[i].atk = EggTemp[i].atk;
			broken[i] = 0;
		}
		temp = 0;
		for (int i = 0; i < N; i++) {
			pick = i + 1;
			hit = pattern[i][arr[i]];
			if (broken[pick] == 1) {
				continue;
			}
			if (broken[hit] == 1) {
				return;
			}
			Egg[pick].def -= Egg[hit].atk;
			Egg[hit].def -= Egg[pick].atk;
			if (Egg[pick].def <= 0) {
				broken[pick] = 1;
				temp++;
			}
			if (Egg[hit].def <= 0) {
				broken[hit] = 1;
				temp++;
			}
			if (temp > Max) Max = temp;
		}
		return;
	}
	for (int u = 0; u < N - 1; u++) {
		arr[cnt] = u;
		EggBreak(cnt + 1);
		picked[u] = 0;
	}
}

int main(void) {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> Egg[i].def >> Egg[i].atk;
		EggTemp[i].def = Egg[i].def;
		EggTemp[i].atk = Egg[i].atk;
	}

	EggBreak(0);
	cout << Max;
	return 0;
}
