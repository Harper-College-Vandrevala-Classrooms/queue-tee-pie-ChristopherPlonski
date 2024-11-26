#include <cassert>
#include <iostream>

#include "Queue.hpp"
#include "Cutie.hpp"

using namespace std;

class Puppy : public Cutie {
public:
	string description() override {
		return "A puppy.";
	}

	int cuteness_rating() override {
		return 9; 
	}
};

class Kitty : public Cutie {
public:
	string description() override {
		return "A kitty.";
	}

	int cuteness_rating() override {
		return 5;
	}
};

class Tortoise : public Cutie {
public:
	string description() override {
		return "A tortoise!";
	}

	int cuteness_rating() override {
		return 10;
	}
};

int main() {
	cout << "Starting QueueTeePie.\n";

	Puppy puppy = Puppy();
	Kitty kitty = Kitty();
	Tortoise tortoise = Tortoise();

	Queue queue = Queue(3);

	// Start enqueuing

	assert(queue.size() == 0);
	assert(queue.is_empty() == true);
	assert(queue.is_full() == false);

	queue.enqueue(&puppy);

	assert(queue.size() == 1);
	assert(queue.is_empty() == false);
	assert(queue.is_full() == false);

	queue.enqueue(&kitty);

	assert(queue.size() == 2);
	assert(queue.is_empty() == false);
	assert(queue.is_full() == false);

	queue.enqueue(&tortoise);

	assert(queue.size() == 3);
	assert(queue.is_empty() == false);
	assert(queue.is_full() == true);

	// Start dequeuing

	Cutie* cutieDequeued = queue.dequeue();

	assert(cutieDequeued->description() == "A puppy.");
	assert(cutieDequeued->cuteness_rating() == 9);
	assert(queue.size() == 2);
	assert(queue.is_empty() == false);
	assert(queue.is_full() == false);

	cutieDequeued = queue.dequeue();

	assert(cutieDequeued->description() == "A kitty.");
	assert(cutieDequeued->cuteness_rating() == 5);
	assert(queue.size() == 1);
	assert(queue.is_empty() == false);
	assert(queue.is_full() == false);

	cutieDequeued = queue.dequeue();

	assert(cutieDequeued->description() == "A tortoise!");
	assert(cutieDequeued->cuteness_rating() == 10);
	assert(queue.size() == 0);
	assert(queue.is_empty() == true);
	assert(queue.is_full() == false);

	// Test enqueuing again (as enqueued objects until filled, so should still work once all removed)

	queue.enqueue(&puppy);

	assert(queue.size() == 1);
	assert(queue.is_empty() == false);
	assert(queue.is_full() == false);

	queue.enqueue(&kitty);

	assert(queue.size() == 2);
	assert(queue.is_empty() == false);
	assert(queue.is_full() == false);

	cout << "QueueTeePie finished.\n";
}