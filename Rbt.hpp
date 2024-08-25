#ifndef RBT_HPP
# define RBT_HPP

# include "RbtNode.hpp"

/*
RED-BLACK TREE PROPERTIES
-Every node is colored either red or black
-The root is black
-Every leaf is black
-If a red node has children they are always black
-For each node, any simple path from this node to any of it's
descendant leaf has the same number of black nodes
*/

template <class T1, class T2>
class Rbt {
public:
    Rbt();
    Rbt(RbtNode<T1, T2>* root);
    ~Rbt();

    void insert(ft::pair<T1, T2> newNode);
    ft::pair<T1, T2> search(T1 key);
    void deleteNode(T1 key);

    void leftRotate(T1 key);
    void rightRotate(T1 key);
private:
    RbtNode<T1, T2>* root_;
};

#endif