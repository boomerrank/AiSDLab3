#include <iostream>
#include "BinaryHeap.h"

int main()
{
	BinaryHeap heap;
	int num_of_elements;
	std::cout << "How many elements?\n";
	std::cin >> num_of_elements;
	std::cout << "Enter the elements:\n";
	for (int i = 0; i < num_of_elements; i++) {
		int newitem;
		std::cin >> newitem;
		heap.insert(newitem);
	}

	std::cout << "Breadth-first traversal:\n";
	Iterator* iter = heap.create_bft_iterator();
	while (iter->has_next()) {
		std::cout << iter->next() << ' ';
	}
	std::cout << '\n';
	delete iter;
	std::cout << "Depth-first traversal:\n";
	iter = heap.create_dft_iterator();
	while (iter->has_next()) {
		std::cout << iter->next() << ' ';
	}
	std::cout << '\n';
	delete iter;

	int removekey;
	std::cout << "Choose key to remove:\n";
	std::cin >> removekey;
	heap.remove(removekey);

	std::cout << "Breadth-first traversal:\n";
	iter = heap.create_bft_iterator();
	while (iter->has_next()) {
		std::cout << iter->next() << ' ';
	}
	std::cout << '\n';
	delete iter;
	std::cout << "Depth-first traversal:\n";
	iter = heap.create_dft_iterator();
	while (iter->has_next()) {
		std::cout << iter->next() << ' ';
	}
	std::cout << '\n';
	delete iter;

	int search_number;
	std::cout << "Enter the number:\n";
	std::cin >> search_number;
	std::cout << "There is" << (heap.contains(search_number) ? " " : " no ") << "that number in the heap\n";
}