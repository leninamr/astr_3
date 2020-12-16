#pragma once
#include "Iterator.h"

class Node {
public:
	Node* left;
	Node* right;
	Node* parent;
	int data;

	Node(int data, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr) {
		this->data = data;
		this->left = left;
		this->right = right;
		this->parent = parent;
	};
	~Node() {};
};

class BinarySearchTree
{
private:
	Node* root;

public:

	BinarySearchTree();
	~BinarySearchTree();

	bool contains(int); // поиск элемента в дереве по ключу
	void insert(int); // добавление элемента в дерево по ключу. Должен работать за O(logN)
	void remove(int); // удаление элемента дерева по ключу


	class Queue {
	private:
		class queue_Node {
		public:
			queue_Node(Node* element, queue_Node* next = nullptr) {
				this->element = element;
				this->next = next;
			};
			~queue_Node() {};
			Node* element;
			queue_Node* next;
		};
		queue_Node* first;
		queue_Node* last;
	public:
		Queue();
		~Queue();

		bool isEmpty();
		void push(Node*);
		Node* pop();
		Node* front();
	};
	Iterator* create_bft_iterator(); // создание итератора, реализующего методы обхода в ширину (breadth-first traverse)
	
	class bft_Iterator : public Iterator {
	public:
		bft_Iterator(Node* start);
		bool has_next() override;
		int next() override;
	private:
		Queue* queue;
	};



	class Stack {
	private:
		class stack_Node {
		public:
			stack_Node(Node* element, stack_Node* next = nullptr) {
				this->element = element;
				this->next = next;
			};
			~stack_Node() {};

			Node* element;
			stack_Node* next;
		};
		stack_Node* top;
	public:
		Stack();
		~Stack();

		void push(Node*);
		Node* pop();
		bool isEmpty();
		Node* getTop();
	};
	Iterator* create_dft_iterator(); // создание итератора, реализующего один из методов обхода в глубину (depth-first traverse)

	class dft_Iterator: public Iterator{
	public:
		dft_Iterator(Node* start);
		bool has_next() override;
		int next() override;
	private:
		Stack* stack;
	};
};