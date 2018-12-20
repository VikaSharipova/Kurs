#pragma once

#include <iostream>
#include <string>

#include "constants.h"

template <typename T>
struct Node {
	T value;
	Node<T> *next = nullptr;
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
		
		void show_list();
		void show_debug();
		void push_back(Node<T> * newNode);
		void pop();
		bool find(T valueOfInterest);
		unsigned int get_length();
		
		~MList();
		
		T& operator[] (unsigned int pos);
		
	private:
		
		Node<T> *bufNode = nullptr;
		Node<T> *head;
		
		unsigned int length;
};


template <typename T>
MList<T>::MList(Node<T> * newHead) : head(newHead), length(1) {}

template <typename T>
MList<T>::MList() : length(0) {}

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
	cout << "DEBUG..." << endl;
	cout << "head: " << this->head << endl;
	cout << "size: " << this->length << endl;
	this->show_list();
	cout << "END OF DEBUG..." << endl;
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
void MList<T>::pop() {
	if (this->length == 0) {
		return;
	}

	if (this->length == 1) {
		delete this->head;
		this->head = nullptr;
		this->length--;
		return;
	}

	Node<T> * previousNode = 0;
	Node<T> * lookingAtNode = head;
	size_t i = 0;
	while (nullptr != lookingAtNode->next) {
		previousNode = lookingAtNode;
		lookingAtNode = lookingAtNode->next;
		
		if (i++ > this->length) {
			this->length = 0;
			return;
		}
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
MList<T>::~MList() {
	
	while (0 != this->length) {
		this->pop();
	}
}

template <typename T>
T& MList<T>::operator[] (unsigned int pos) {
	
	if (nullptr != bufNode) {
		delete bufNode;
		bufNode = nullptr;
	}
	
	bufNode = new Node<T>;
	*bufNode = *head;
	
	for (int i = 0; (nullptr != bufNode) && (i != pos); ++i) {
		*bufNode = *bufNode->next;

	}
	
	return bufNode->value;
}