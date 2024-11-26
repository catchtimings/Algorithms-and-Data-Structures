#pragma once
#include <iostream>
#include <stdexcept>

template<typename T>
struct Node {
	T data;
	Node *prev, *next;

	Node(const T& value): data(value), next(nullptr), prev(nullptr) {}
};

template<typename T>
class LinkedList {
private:
	Node<T>* head, * tail;
public:

	LinkedList() : head(nullptr), tail(nullptr) {}

	LinkedList(const LinkedList& list) : head(nullptr), tail(nullptr) {
		Node<T>* ptr = list.head;
		while (ptr != nullptr) {
			push_tail(ptr->data);
			ptr = ptr->next;
		}
	}

	~LinkedList() {
		while (head != nullptr) {
			pop_head();
		}
	}

	void push_head(const T& value) {
		Node<T>* ptr = new Node<T>(value);

		if (head == nullptr) {
			head = ptr;
			tail = ptr;
		}
		else {
			head->prev = ptr;
			ptr->next = head;
			head = ptr;
		}
	}

	void push_head(const LinkedList& list) {
		if (list.head == nullptr)
			return;

		/*if (head == nullptr) {
			head = list.head;
			tail = list.tail;
		}
		else {
			head->prev = list.tail;
			list.tail->next = head;
			head = list.head;
		}*/

		Node<T>* ptr = list.tail;
		while (ptr) {
			push_head(ptr->data);
			ptr = ptr->prev;
		}
	}


	void push_tail(const T& value) {
		Node<T>* ptr = new Node<T>(value);

		if (head == nullptr) {
			head = ptr;
			tail = ptr;
		}
		else {
			tail->next = ptr;
			ptr->prev = tail;
			tail = ptr;
		}
	}

	void push_tail(const LinkedList& list) {
		if (list.head == nullptr)
			return;

		/*if (head == nullptr) {
			head = list.head;
			tail = list.tail;
		}
		else {
			tail->next = list.head;
			list.head->prev = tail;
			tail = list.tail;
		}*/
		
		Node<T>* ptr = list.head;
		while (ptr) {
			push_tail(ptr->data);
			ptr = ptr->next;
		}
	}

	void pop_head() {
		if (head == nullptr) {
			return;
		}

		Node<T>* ptr = head->next;
		if (ptr != nullptr) {
			ptr->prev = nullptr;
		}
		else {
			tail = nullptr;
		}
		delete head;
		head = ptr;
	}

	void pop_tail() {
		if (tail == nullptr) {
			return;
		}
		Node<T>* ptr = tail->prev;

		if (ptr != nullptr) {
			ptr->next = nullptr;
		}
		else {
			head = nullptr;
		}
		delete tail;
		tail = ptr;
	}

	Node<T>* operator[](const size_t& index) {
		Node<T>* ptr = head;
		size_t count = 0;
		while (count != index) {
			if (ptr == nullptr) throw std::out_of_range("Invalid index");//return nullptr;
			ptr = ptr->next;
			count++;
		}
		return ptr;
	}

	void delete_node(const T& value) {
		Node<T>* ptr = head;

		while (ptr && (ptr->data != value)) {
			ptr = ptr->next;
		}

		if (ptr == nullptr) {
			return;
		}

		Node<T>* right = ptr->next;
		Node<T>* left = ptr->prev;

		left->next = right;
		right->prev = left;

		delete ptr;
	}

	friend std::ostream& operator<<(std::ostream & stream, const LinkedList<T>& list) {
		for (Node<T>* ptr = list.head; ptr != nullptr; ptr = ptr->next) {
			stream << ptr->data << " ";
		}
		return stream;
	}
};

//template<typename T>
//std::ostream& operator<<(std::ostream & stream, const LinkedList<T>& list) {
//	for (Node<T>* ptr = list.get_head(); ptr != nullptr; ptr = ptr->next) {
//		stream << ptr->data << " ";
//	}
//	return stream;
//}
