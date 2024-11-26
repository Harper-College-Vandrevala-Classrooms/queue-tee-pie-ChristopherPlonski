#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Cutie.hpp"

class Queue {

public:
	Queue(int maxSize);
	void enqueue(Cutie *cutie);
	Cutie* dequeue();
	int size();
	bool is_empty();
	bool is_full();

private:
	void increase_end_index();
	void increase_start_index();
	const int MAX_SIZE;
	int currentSize;
	int startIndex;
	int endIndex;
	Cutie* *queueArray;

};

#endif // !QUEUE_HPP
