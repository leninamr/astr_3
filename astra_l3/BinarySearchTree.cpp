#include "BinarySearchTree.h"
#include <stdexcept>

using namespace std;

BinarySearchTree::BinarySearchTree() {
	root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
	while (root != nullptr) {
		remove(root->data);
	}
	delete root;
}

// searching element in the tree by the key
bool BinarySearchTree::contains(int key) {
	Node* current = root;
	while (current != nullptr) {
		if (key > current->data)
			current = current->right;
		else
			if (key < current->data)
				current = current->left;
			else
				if (key == current->data)
					return true;
	}
	return false;
}
//adding element into tree by key. it must takes O(logN)
void BinarySearchTree::insert(int key) {
	
	if (root == nullptr)
		root = new Node(key);
	else {
		Node* current = root;
		while ( !((key >= current->data) && (current->right==nullptr)) && !((key <= current->data) && (current->left == nullptr))) {
			if (key >= current->data) 
				current = current->right;
			else
				if (key <= current->data) 
					current = current->left;
			if (current == nullptr) 
				break;
		}
		if (current != nullptr) {
			if ((key > current->data) && (current->right == nullptr))
				current->right = new Node(key, nullptr, nullptr, current);

			if ((key < current->data) && (current->left == nullptr))
				current->left = new Node(key, nullptr, nullptr, current);
		}
	}
}
//deleting element of tree by the key
void BinarySearchTree::remove(int key) {
	if (root == nullptr) 
		throw out_of_range("The tree is empty");
	else 
		if (root->left == nullptr && root->right == nullptr && root->data == key) {
			root = nullptr;
		}
		else 
			if (root->left == nullptr && root->right == nullptr && root->data != key) {
				throw out_of_range("This key dosen't exist");
			}
			else {
				Node* current = root;
				Node* child_elem;
				while (current != nullptr) {
					if (current->data == key) {
						if (current->left == nullptr && current->right == nullptr) {
							if ((current->parent)->left == current) 
								(current->parent)->left = nullptr;
							else 
								(current->parent)->right = nullptr;
							delete current;
						}
						else 
							if (current->left != nullptr && current->right == nullptr) {
								child_elem = current->left;
								current->data = child_elem->data;
								current->left = child_elem->left;
								current->right = child_elem->right;
								if (current->left != nullptr)
									current->left->parent = current;
								if (current->right != nullptr)
									current->right->parent = current;
								delete child_elem;
							}
							else 
								if (current->left == nullptr && current->right != nullptr) {
									child_elem = current->right;
									current->data = child_elem->data;
									current->left = child_elem->left;
									current->right = child_elem->right;
									if (current->left != nullptr) 
										current->left->parent = current;
									if (current->right != nullptr) 
										current->right->parent = current;
									delete child_elem;
								}
								else {
									child_elem = current->right;
									if (child_elem->left == nullptr) {
										current->right = child_elem->right;
										if (child_elem->right != nullptr) 
											(child_elem->right)->parent = current;
									}
									else {
										while (child_elem->left != nullptr && child_elem != nullptr) 
											child_elem = child_elem->left;
										(child_elem->parent)->left = child_elem->right;
										if (child_elem->right != nullptr) 
											child_elem->right->parent = child_elem->parent;
									}
									current->data = child_elem->data;
									delete child_elem;
								}
								return;
					}
					else 
						if (current->data > key)
							current = current->left;
						else 
							current = current->right;
				}
				throw out_of_range("This key dosen't exist");
			}
}

