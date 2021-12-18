#pragma once
#include <stdexcept>

//Class for Nodes in Quene and Stack
class Node 
{
private:
	int data;
	Node* next;
public:
	Node(int data) { 
		this->data = data;
		next = nullptr;
	}
	int get_data() { return data; }
	void set_dete(int data) { this->data = data; }
	Node* get_next() { return next; }
	void set_next(Node* next) { this->next = next; }
};

//Base class for Quene and Stack
class List 
{
public:
	virtual void push(int data) = 0;
	virtual int pop() = 0;
	virtual bool isEmpty() = 0;
};

class Stack :public List
{
private:
	Node* top;
public:
	Stack() {
		top = nullptr;
	}
	~Stack() {
		while (!this->isEmpty()) {
			this->pop();
		}
	}

	void push(int data) override {
		Node* temp = new Node(data);
		temp->set_next(top);
		top = temp;
	}

	int pop() override {
		if (top == nullptr) {
			throw std::logic_error("Pop from empty stack");
		}
		Node* temp = top;
		top = top->get_next();
		int data = temp->get_data();
		delete temp;
		return data;
	}

	bool isEmpty() override {
		return top == nullptr;
	}
};

class Quene :public List {
private:
	Node* head;
	Node* tail;
public:
	Quene() {
		head = nullptr;
		tail = nullptr;
	}

	~Quene() {
		while (!this->isEmpty()) {
			this->pop();
		}
	}

	void push(int data) override {
		if (head == nullptr) {
			head = new Node(data);
			tail = head;
		}
		else {
			tail->set_next(new Node(data));
			tail = tail->get_next();
		}
	}

	int pop() override {
		if (head == nullptr) {
			throw std::logic_error("Pop from empty stack");
		}
		Node* temp = head;
		head = head->get_next();
		int data = temp->get_data();
		delete temp;
		return data;
	}

	bool isEmpty() override {
		return head == nullptr;
	}
};