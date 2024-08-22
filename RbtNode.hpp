#ifndef BTREE_HPP
# define BTREE_HPP

# include "Node.hpp"

# define BLACK true
# define RED false

template<class T1, class T2>
class RbtNode: public Node<T1, T2> {
public:
	RbtNode(const ft::pair<T1, T2>& keyValPair, bool color): Node<T1, T2>(keyValPair), color(color) {};

	void setRightChild(Node<T1, T2>* right) {
		this->right = right;
	};
	void setLeftChild(Node<T1, T2>* left) {
		this->left = left;
	};
	void setParent(Node<T1, T2>* parent) {
		this->parent_ = parent;
	}
	void clearRightChild(void) {
		this->right = nullptr;
	};
	void clearLeftChild(void) {
		this->left = nullptr;
	};
	void clearParent(void) {
		this->parent_ = nullptr;
	};
private:
	bool color;
};

#endif