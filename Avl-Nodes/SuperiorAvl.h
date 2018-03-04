//
// Created by Jack on 17/6/2017.
//

#ifndef AVLTREE_COPY_SUPERIORAVL_H
#define AVLTREE_COPY_SUPERIORAVL_H


#include "Avl.h"
#include "SuperiorAvlNode.h"

class SuperiorAvl {
private:
    SuperiorAvlNode *root;
public:

    SuperiorAvl(int id);

    virtual ~SuperiorAvl();

    int BalanceFactor(SuperiorAvlNode *node);

    void fixheight(SuperiorAvlNode *p);

    SuperiorAvlNode *insert(int id, SuperiorAvlNode *root);

    SuperiorAvlNode *insertSuperiorNode(SuperiorAvlNode *superiorNode, SuperiorAvlNode *root);

    SuperiorAvlNode *Search(int x, SuperiorAvlNode *p);

    SuperiorAvlNode *Left(SuperiorAvlNode *root);

    SuperiorAvlNode *Right(SuperiorAvlNode *root);

    SuperiorAvlNode *Balance(SuperiorAvlNode *node);

    SuperiorAvlNode *getRoot() const;

    SuperiorAvlNode *FindMax(SuperiorAvlNode *node);

    SuperiorAvlNode *FindMin(SuperiorAvlNode *node);

    void setRoot(SuperiorAvlNode *root);

    void PreDelete(SuperiorAvlNode *p, int i);

    SuperiorAvlNode *inorder(SuperiorAvlNode *node);

};



#endif //AVLTREE_COPY_SUPERIORAVL_H
