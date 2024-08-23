#ifndef BTREE_HPP
# define BTREE_HPP

# include <algorithm>

# define BLACK true
# define RED false

template<class T1, class T2>
class RbtNode{
public:
	RbtNode(ft::pair<T1, T2>& keyValPair, bool color): Node<T1, T2>(keyValPair), color_(color) {};

	void setRightChild(RbtNode<T1, T2>* right) {
		this->right_ = right;
	};
	void setLeftChild(RbtNode<T1, T2>* left) {
		this->left_ = left;
	};
	void setParent(RbtNode<T1, T2>* parent) {
		this->parent_ = parent;
	}
	void clearRightChild(void) {
		this->right_ = nullptr;
	};
	void clearLeftChild(void) {
		this->left_ = nullptr;
	};
	void clearParent(void) {
		this->parent_ = nullptr;
	};
	void swapNode(RbtNode<T1, T2>* other) {
		std::swap(this->key_value_pair_, other->key_value_pair_);
		std::swap(this->parent_, other->parent_);
		std::swap(this->right_, other->right_);
		std::swap(this->left_, other->left_);
		std::swap(this->color_, other->color_);
	};
private:
	bool color_;
	RbtNode* parent_;
	RbtNode* left_;
	RbtNode* right;
};

#endif