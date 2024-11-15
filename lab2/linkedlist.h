#pragma once


template<typename T>
struct Node {
	T info;
	Node *prev, *next;

	Node(const T& data): info(data), next(nullptr), prev(nullptr) {}
};

template<typename T>
class LinkedList {
private:
	Node *head, *tail;
public:

	LinkedList(): head(nullptr), tail(nullptr) {}

	LinkedList(const LinkedList& list) {
		Node* p = list.head;
		while (p != nullptr) {
			push_tail(p);
			p = p->next;
		}
	}

	void push_head(const T& data) {
		Node* ptr = new Node(data);

		ptr->next = head;
		if (head != nullptr) {
			head->prev = ptr;
		}
		if (tail == nullptr) {
			tail = ptr;
		}
		head = ptr;
	}

	void push_tail(const T& data) {
		Node* ptr = new Node(data);

		ptr->prev = tail;
		if (tail != nullptr) {
			tail->next = ptr;
		}
		if (head == nullptr) {
			head = ptr;
		}
		tail = ptr;
	}
};