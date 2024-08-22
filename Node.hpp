#ifndef BST_HPP
# define BST_HPP
# include "pair.hpp"

template<class T1, class T2>
class Node {
public:
	Node(const ft::pair<T1, T2> &keyValPair): keyValuePair(keyValPair), right_(nullptr), left_(nullptr), parent_(nullptr) {};

	virtual void setRightChild(Node<T1, T2>* right) = 0;
	virtual void setLeftChild(Node<T1, T2>* left) = 0;
	virtual void setParent(Node<T1, T2>* parent) = 0;
	virtual void clearRightChild(void) = 0;
	virtual void clearLeftChild(void) = 0;
	virtual void clearParent(void) = 0;
	virtual void swapNode(Node<T1, T2>* other) = 0;

protected:
	ft::pair<T1, T2> key_value_pair_;
	Node *right_;
	Node *left_;
	Node *parent_;
};

#endif