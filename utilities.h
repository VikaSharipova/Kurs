#pragma once
#include <iostream>
#include <string>
#include "constants.h"

template <typename T>
struct Node {
	T value;
	Node<T> * next = 0;
};

using namespace std;

string input_string_with_retries(int retriesNum);
int input_int_with_retries(int retriesNum);
int input_int_with_retries_and_borders(int retriesNum, int leftBorder, int rightBorder);

void check_sportsmans_parameter(int parameter);

template <typename T>
class MList {
public:
	MList(Node<T> * newHead);	
	MList();								
	MList(const MList<T>& copyFrom);		
	MList<T>& operator= (MList<T> other);	

	void show_list();
	void show_debug();
	void push_back(Node<T> * newNode);
	void push_back(T newValue);
	void pop();
	bool find(T valueOfInterest);
	T get(T valueOfInterest);
	unsigned int get_length();

	~MList();

	T operator[] (unsigned int pos);

private:
	Node<T> * head = 0;
	unsigned int length = 0;
};

template <typename T>
MList<T>::MList(Node<T> * newHead) : head(newHead), length(1) {}

template <typename T>
MList<T>::MList() : head(0), length(0) {}

template <typename T>
MList<T>::MList(const MList<T>& copyFrom) {

	Node<T> * lookingAtNode = copyFrom.head;
	while (lookingAtNode) {
		Node<T> * newNode = new Node<T>;
		newNode->value = lookingAtNode->value;
		this->push_back(newNode);
		lookingAtNode = lookingAtNode->next;
	}
}

template <typename T>
MList<T>& MList<T>::operator=(MList<T> other) {
	if (this == &other) {
		return *this;
	}

	while (this->get_length()) {
		this->pop();
	}
	Node<T> * lookingAtNode = other.head;
	while (lookingAtNode) {
		Node<T> * newNode = new Node<T>;
		newNode->value = lookingAtNode->value;
		this->push_back(newNode);
		lookingAtNode = lookingAtNode->next;
	}
	return *this;
}

template <typename T>
void MList<T>::show_list() {
	Node<T> * lookingAtNode = head;
	unsigned int counter = 0;
	while (lookingAtNode) {
		cout << counter << " : " << lookingAtNode->value << endl;
		lookingAtNode = lookingAtNode->next;
		counter++;
	}
}

template <typename T>
void MList<T>::show_debug() {
	cout << "Debug..." << endl;
	cout << "head: " << this->head << endl;
	cout << "size: " << this->length << endl;
	this->show_list();
	cout << "End of Debug..." << endl;
}

template <typename T>
unsigned int MList<T>::get_length() {
	return this->length;
}

template <typename T>
void MList<T>::push_back(Node<T> * newNode) {
	Node<T> * newListNode = new Node<T>;
	newListNode->next = 0;
	newListNode->value = newNode->value;

	if (this->length == 0) {
		this->head = newListNode;
		this->head->next = 0;
		this->length = 1;
		return;
	}

	Node<T> * lookingAtNode = head;
	while (lookingAtNode->next) {
		lookingAtNode = lookingAtNode->next;
	}
	lookingAtNode->next = newListNode;
	this->length++;
}

template <typename T>
void MList<T>::push_back(T newValue) {
	Node<T> * newListNode = new Node<T>;
	newListNode->next = 0;
	newListNode->value = newValue;

	if (this->length == 0) {
		this->head = newListNode;
		this->head->next = 0;
		this->length = 1;
		return;
	}

	Node<T> * lookingAtNode = head;
	while (lookingAtNode->next) {
		lookingAtNode = lookingAtNode->next;
	}
	lookingAtNode->next = newListNode;
	this->length++;
}

template <typename T>
void MList<T>::pop() {
	if (this->length == 0) {
		return;
	}

	if (this->length == 1) {
		this->head = NULL;
		this->length--;
		return;
	}

	Node<T> * previousNode = 0;
	Node<T> * lookingAtNode = head;
	while (lookingAtNode->next) {
		previousNode = lookingAtNode;
		lookingAtNode = lookingAtNode->next;
	}
	delete lookingAtNode;
	previousNode->next = 0;
	this->length--;
}

template <typename T>
bool MList<T>::find(T valueOfInterest) {
	Node<T> * lookingAtNode = head;
	while (lookingAtNode) {
		if (lookingAtNode->value == valueOfInterest) {
			return true;
		}
		lookingAtNode = lookingAtNode->next;
	}
	return false;
}

template <typename T>
T MList<T>::get(T valueOfInterest) {
	Node<T> * lookingAtNode = head;
	T result;
	while (lookingAtNode) {
		if (lookingAtNode->value == valueOfInterest) {
			result = lookingAtNode->value;
		}
		lookingAtNode = lookingAtNode->next;
	}
	return result;
}

template <typename T>
MList<T>::~MList() {
	while (this->length != 0) {
		this->pop();
	}
}

template <typename T>
T MList<T>::operator[] (unsigned int pos) {
	unsigned int counter = 0;
	Node<T> * lookingAtNode = head;

	// case to return
	if (pos == this->length - 1) {
		while (lookingAtNode->next) {
			lookingAtNode = lookingAtNode->next;
		}
		return lookingAtNode->value;
	}

	while (lookingAtNode->next) {
		if (counter == pos) {
			return lookingAtNode->value;
		}
		counter++;
		lookingAtNode = lookingAtNode->next;
	}

	try {
		throw 20;
		return this->head->value;
	}
	catch (int e) {
		cout << "Выход за пределы списка" << endl;
		exit(1);
	}
}
