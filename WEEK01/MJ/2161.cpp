#include <queue>
#include <iostream>
using namespace std;

int main(void) {
	queue<long> myQueue;
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		myQueue.push(i);
	}
	while (myQueue.size() - 1)
	{
		cout << myQueue.front() << " ";
		myQueue.pop();
		myQueue.push(myQueue.front());
		myQueue.pop();
	}
	cout << myQueue.front();
}
