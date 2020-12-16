#include "BinarySearchTree.h"
#include "Iterator.h"
#include <iostream>

using namespace std;

int main() {
	BinarySearchTree* tree;
	tree = new BinarySearchTree();
	tree->insert(9);
	tree->insert(10);
	tree->insert(6);
	tree->insert(8);
	tree->insert(4);
	tree->insert(5);
	
	Iterator* br = tree->create_bft_iterator();
	while (br->has_next()) {
		cout << br->next() << ' ';
	}
	cout << endl; 
	Iterator* de = tree->create_dft_iterator();
	while (de->has_next()) {
		cout << de->next() << ' ';
	}
	
	cout << endl;
	if (tree->contains(5)) cout << 1; 
	else cout << 0;
		
}
