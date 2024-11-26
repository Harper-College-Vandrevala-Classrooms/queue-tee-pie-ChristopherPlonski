#include <iostream>

#include "Queue.hpp"

Queue::Queue(int maxSize) : MAX_SIZE(maxSize)
{
	this->queueArray = new Cutie*[MAX_SIZE];
	this->currentSize = 0;
	this->startIndex = 0;
	this->endIndex = 0;
}

void Queue::enqueue(Cutie *cutie)
{
	if (is_full()) {
		cout << "Queue is full!\n";
		return;
	}

	this->queueArray[this->endIndex] = cutie;
	increase_end_index();
	this->currentSize++;
}

Cutie* Queue::dequeue()
{
	if (is_empty()) {
		cout << "Queue is empty!\n";
		return nullptr;
	}

	Cutie* cutieToDequeue = this->queueArray[this->startIndex];
	this->currentSize--;
	increase_start_index();
	//cout << "Debug: in dequeue description: " << cutieToDequeue->description();
	return cutieToDequeue;
}

int Queue::size()
{
	return this->currentSize;
}

bool Queue::is_empty()
{
	return this->currentSize == 0;
}

bool Queue::is_full()
{
	return this->currentSize == this->MAX_SIZE;
}

void Queue::increase_end_index()
{
	this->endIndex++;

	if (this->endIndex == this->MAX_SIZE) {
		this->endIndex = 0;
	}

	//cout << "End index after increase: " << this->endIndex << endl;
}

void Queue::increase_start_index()
{
	this->startIndex++;

	if (this->startIndex == MAX_SIZE) {
		this->startIndex = 0;
	}

	//cout << "Start index after increase: " << this->startIndex << endl;
}