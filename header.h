#include <iostream>
#include <string>
#include <map>
#include <iterator>
using namespace std;

#ifndef _BinarySearch_
#define _BinarySearch_

template <class T>
struct Node {

	pair<T, int> element;
	Node * left;
	Node * right;
	Node(T first, int second): element(first,second), left(NULL), right(NULL) {}
	Node():  left(NULL), right(NULL) {}
};


template <class T> class BST {
private:
	Node<T> * root;

	void addToTree(Node<T> * ptr, T first, int second) {
		//recursive to the left pointer
		if(ptr->element.first > first) {

			Node<T> * child = ptr->left;
			if(child) {
				addToTree(child,first,second);
			}
			else {
				ptr->left = new Node<T>(first,second);
			}

		}
		else if(ptr->element.first < first) { //recursive to the right pointer
			Node<T> * child = ptr->right;
			if(child) {
				addToTree(child,first,second);
			}
			else {
				ptr->right = new Node<T>(first,second);
			}
		}
		else { //ptr->element.first == first found same node
			return;
		}
	}

	int searchTree(Node<T> * ptr, T first) {

		if(ptr->element.first > first) {
			Node<T> * child = ptr->left;
			if(child)
				return searchTree(child,first);
			else
				return -1;

		}
		else if(ptr->element.first < first) { //recursive to the right pointer
			Node<T> * child = ptr->right;
			if(child)
				return searchTree(child,first);
			else
				return -1;
		}
		else { //ptr->element.first == first found same node
			return ptr->element.second;
		}
	}

public:
	BST():root(NULL) {}

	void addToRoot(T first, int second) { 
		if (root == NULL)
			root = new Node<T>(first,second);
		else
			addToTree(root,first,second);
	}
	int searchRoot(T first) {
		if (root == NULL)
			return -1;
		else 
			return searchTree(root, first);
	}

};

#endif