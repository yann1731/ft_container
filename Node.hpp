#ifndef BST_HPP
# define BST_HPP
# include "pair.hpp"

template<class T1, class T2>
class Node {
public:

template<class T1, class T2>
	Node(const ft::pair<T1, T2> &keyValPair): keyValuePair(keyValPair) = 0;

private:
	ft::pair<T1, T2> keyValuePair;
};

#endif