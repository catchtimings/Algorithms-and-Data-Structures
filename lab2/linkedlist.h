#pragma once
#include <stdexcept>


template<typename T>
struct Node {
	T info;
	Node *prev, *next;

	Node(const T& data): info(data), next(nullptr), prev(nullptr) {}
};

template<typename T>
class LinkedList {
private:
	Node<T> *head, *tail;
public:

	LinkedList(): head(nullptr), tail(nullptr) {}

	LinkedList(const LinkedList& list) {
		Node<T>* p = list.head;
		while (p != nullptr) {
			push_tail(p->info);
			p = p->next;
		}
	}

	~LinkedList() {
		while (head != nullptr) {
			pop_head();
		}
	}

	Node<T>* get_head() const noexcept {
		return head;
	}

	Node<T>* get_tail() const noexcept {
		return tail;
	}

	void push_head(const T& data) {
		Node* ptr = new Node(data);

		if (head == nullptr) {
			head = ptr;
			tail = ptr;
		}
		head->prev = ptr;
		ptr->next = head;
		head = ptr;
	}

	void push_head(const LinkedList& list) {
		if (list.head == nullptr)
			return;

		if (head == nullptr) {
			head = list.head;
			tail = list.tail;
		}

		list.tail->next = head;
		head->prev = list.tail;
		head = list.head;
		
	}


	void push_tail(const T& data) {
		Node<T>* ptr = new Node(data);

		if (head == nullptr) {
			head = ptr;
		}
		tail->next = ptr;
		ptr->prev = tail;
		tail = ptr;
	}

	void push_tail(const LinkedList& list) {
		if (list.head == nullptr)
			return;

		if (head == nullptr) {
			head = list.head;
			tail = list.tail;
		}

		tail->next = list.head;
		list.head->prev = tail;
		tail = list.tail;
	}

	void pop_head() {
		Node<T>* ptr = head->next;
		if (head == nullptr) {
			throw std::logic_error("List is empty");
		}
		if (ptr != nullptr) {
			ptr->prev = nullptr;
		}
		delete head;
		head = ptr;
	}

	void pop_tail() {
		Node* ptr = tail->prev;

		if (tail == nullptr) {
			throw std::logic_error("List is empty");
		}
		if (ptr != nullptr) {
			ptr->next = nullptr;
		}
		delete tail;
		tail = ptr;
	}
};