#include "BinaryHeap.h"

int min(int a, int b) {
	return a < b ? a : b;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//Increase capacity if necessary
void BinaryHeap::increase_capacity()
{
	capacity *= 2;
	int* tempHeap = new int [capacity] {};
	for (int i = 0; i < real_size; i++) {
		tempHeap[i] = Heap[i];
	}
	delete[] Heap;
	Heap = tempHeap;
}

//Repair heap
void BinaryHeap::heapify(int index)
{
	siftDown(index);
	siftUp(index);	
}

void BinaryHeap::siftDown(int index)
{
	//If element have 2 childrens
	if (real_size > index * 2 + 2) {
		if (Heap[index] > min(Heap[index * 2 + 1], Heap[index * 2 + 2])) {
			//swap element with the smaller of the children
			if (Heap[index * 2 + 1] < Heap[index * 2 + 2]) {
				swap(Heap[index * 2 + 1], Heap[index]);
				siftDown(index * 2 + 1);
			}
			else {
				swap(Heap[index * 2 + 2], Heap[index]);
				siftDown(index * 2 + 2);
			}
		}
		return;
	}
	//If element have only 1 children
	if (real_size > index * 2 + 1) {
		if (Heap[index] > Heap[index * 2 + 1]) {
			swap(Heap[index], Heap[index * 2 + 1]);
		}
	}
}

void BinaryHeap::siftUp(int index)
{
	//If element have parent
	if (index > 0) {
		//if parent larger than children
		if (Heap[((index - 1) - (index - 1) % 2) / 2] > Heap[index]) {
			swap(Heap[((index - 1) - (index - 1) % 2) / 2], Heap[index]);
			siftUp(((index - 1) - (index - 1) % 2) / 2);
		}
	}
}

//Constructor 1
BinaryHeap::BinaryHeap()
{
	capacity = 10;
	real_size = 0;
	Heap = new int[capacity] {};
}

//Constructor 2
BinaryHeap::BinaryHeap(int capacity)
{
	this->capacity = capacity;
	real_size = 0;
	Heap = new int[capacity] {};
}

//Destroctor
BinaryHeap::~BinaryHeap()
{
	delete[] Heap;
}

//Check if there is an element with a given value
bool BinaryHeap::contains(int key) {
	if (real_size == 0) {
		return false;
	}
	Iterator* iterator = create_bft_iterator();
	while (iterator->has_next()) {
		if (iterator->next() == key) {
			return true;
		}
	}
	return false;
}

//Insert an element with a given value
void BinaryHeap::insert(int key)
{
	if (real_size >= capacity) {
		increase_capacity();
	}
	Heap[real_size] = key;
	real_size++;
	heapify(real_size - 1);
}

//Remove an element with a given value
void BinaryHeap::remove(int key) {
	Iterator* iterator = create_bft_iterator();
	int index = 0;
	while (iterator->has_next()) {
		int temp = iterator->next();
		if (temp == key) {
			break;
		}
		index++;
	}
	if (index >= real_size) {
		return;
	}
	Heap[index] = Heap[real_size - 1];
	real_size--;
	heapify(index);
}

//Create iterator to depth-first traversal
Iterator* BinaryHeap::create_dft_iterator()
{
	return new DftIterator(this);
}

//Create iterator to breadth-first traversal
Iterator* BinaryHeap::create_bft_iterator()
{
	return new BftIterator(this);
}

//Depth-first traversal iterator logic
int BinaryHeap::DftIterator::next()
{
	if ((!has_next()) || (this->heap->get_size() == 0)) {
		throw std::out_of_range("No more elements");
	}
	int temp = current.pop();
	if ((temp * 2 + 2) < heap->get_size()) { current.push(temp * 2 + 2); }
	if ((temp * 2 + 1) < heap->get_size()) { current.push(temp * 2 + 1); }
	return heap->get_data(temp);
}

bool BinaryHeap::DftIterator::has_next()
{
	if (this->heap->get_size() == 0) {
		return false;
	}
	return !current.isEmpty();
}

//Bbreadth-first traversal iterator logic
int BinaryHeap::BftIterator::next()
{
	if ((!has_next())||(this->heap->get_size()==0)) {
		throw std::out_of_range("No more elements");
	}
	int temp = current.pop();
	if ((temp * 2 + 1) < heap->get_size()) { current.push(temp * 2 + 1); }
	if ((temp * 2 + 2) < heap->get_size()) { current.push(temp * 2 + 2); }
	return heap->get_data(temp);
}
bool BinaryHeap::BftIterator::has_next()
{
	if (this->heap->get_size() == 0) {
		return false;
	}
	return !current.isEmpty();
}