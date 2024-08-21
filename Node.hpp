#ifndef BST_HPP
# define BST_HPP
# include "pair.hpp"

template<class T1, class T2>
class Node {
public:
	Node(const ft::pair<T1, T2> &keyValPair): keyValuePair(keyValPair), right(nullptr), left(nullptr) {};

	virtual void setRightChild(Node<T1, T2>* right) = 0;
	virtual void setLeftChild(Node<T1, T2>* left) = 0;
	virtual void clearRightChild(void) = 0;
	virtual void clearLeftChild(void) = 0;

protected:
	ft::pair<T1, T2> keyValuePair;
	Node *right;
	Node *left;
};

#endif