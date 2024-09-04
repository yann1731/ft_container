#ifndef BTREE_HPP
# define BTREE_HPP

# include <algorithm>

# define BLACK true
# define RED false

template<class Key, class T>
class RbtNode{
public:
	RbtNode(ft::pair<Key, T>& keyValPair, bool color = RED): key_value_pair_(keyValPair), color_(color), parent_(nullptr), left_(nullptr), right(nullptr) {};

	void setParent(RbtNode<Key, T>* parent) {
		this->parent_ = parent;
	};

	void setLeftChild(RbtNode<Key, T>* left) {
		this->left_ = left;
	};

	void setRightChild(RbtNode<Key, T>* right) {
		this->right_ = right;
	};

	void clearParent(void) {
		this->parent_ = nullptr;
	};

	void clearLeftChild(void) {
		this->left_ = nullptr;
	};

	void clearRightChild(void) {
		this->right_ = nullptr;
	};

	void clearTree(void) {//to be implemented

	};

	void swapNode(RbtNode<Key, T>* other) {
		std::swap(this->key_value_pair_, other->key_value_pair_);
		std::swap(this->parent_, other->parent_);
		std::swap(this->right_, other->right_);
		std::swap(this->left_, other->left_);
		std::swap(this->color_, other->color_);
	};
private:
	ft::pair<Key, T> key_value_pair_;
	bool color_;
	RbtNode* parent_;
	RbtNode* left_;
	RbtNode* right;
};

#endif