#include <iostream>
#include "Queue.h"

using namespace std;

int main () {
	Queue<int> queue;
	for (int i = 0; i < 5; i++) {
		queue.enqueue (i);
		queue.printQueue ();
	}
	for (int i = 0; i < 5; i++) {
		queue.dequeue ();
		queue.printQueue ();
	}
	system ("pause");
	return 0;
}