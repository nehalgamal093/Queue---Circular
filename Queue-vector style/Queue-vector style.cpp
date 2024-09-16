#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{

	Queue <int> q;
	q.push(1);
	q.push(5);
	q.push(10);
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
}

