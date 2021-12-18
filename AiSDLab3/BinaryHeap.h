#pragma once
#include "Iterator.h"
#include "Lists.h"
class BinaryHeap
{
private:
	//Increase capacity if necessary
	void increase_capacity();

	//Repair heap
	void heapify(int index);
	void siftDown(int index);
	void siftUp(int index);

	int capacity;
	int real_size;
	int* Heap;

public:
	//Constructors
	BinaryHeap();
	BinaryHeap(int capacity);

	//Destroctor
	~BinaryHeap();

	//Getters
	int get_data(int index) { return Heap[index]; }
	int get_size() { return real_size; }

	//Depth-first traversal iterator
	class DftIterator : public Iterator 
	{
	private:
		BinaryHeap* heap;
		Stack current;
	public:
		DftIterator(BinaryHeap* heap) {
			this->heap = heap;
			current.push(0);
		}
		int next() override;
		bool has_next() override;
	};

	//Breadth-first traversal iterator
	class BftIterator : public Iterator 
	{
	private:
		BinaryHeap* heap;
		Quene current;
	public:
		BftIterator(BinaryHeap* heap) {
			this->heap = heap;
			current.push(0);
		}
		int next() override;
		bool has_next() override;
	};

	//Check if there is an element with a given value
	bool contains(int key);

	//Insert an element with a given value
	void insert(int key);

	//Remove an element with a given value
	void remove(int key);

	//Create iterator to depth-first traversal
	Iterator* create_dft_iterator(); 

	//Create iterator to breadth-first traversal
	Iterator* create_bft_iterator();
};