#ifndef BTREE_HPP
# define BTREE_HPP
# include "Node.hpp"
# define RED 1;
# define BLACK 0;

template<class T1, class T2>
class RbtNode: public Node {
public:
	RbtNode(const ft::pair &keyValPair): Node(keyValPair), color(BLACK) {}
private:
	bool color;
};

#endif