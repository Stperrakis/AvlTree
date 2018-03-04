//
// Created by Jack on 9/5/2017.
//

#ifndef AVLTREE_AVL_H
#define AVLTREE_AVL_H

#include "Node.h"

class Avl {
private:
    Node *root;
public:
    Avl(Node *root);

    Avl(int id);

    int BalanceFactor(Node *node);

    void fixheight(Node *p);

    Node *insert(int id, Node *root);

    virtual ~Avl();

    void *Delete(int y);

    Node *Search(int x, Node *p);

    Node *Left(Node *root);

    Node *Right(Node *root);

    Node *Balance(Node *node);

    Node *getRoot() const;

    Node *FindMax(Node *node);

    void PrintAvl(Node *root, int level);

    Node *FindMin(Node *node);

    void setRoot(Node *root);

    void PreDelete(Node *p, int i);
};


#endif //AVLTREE_AVL_H
