//
// Created by user on 6/1/2017.
//

#ifndef AVLTREE_COPY_SUPERIORAVLNODE_H
#define AVLTREE_COPY_SUPERIORAVLNODE_H
#include "Node.h"
#include "Avl.h"

class SuperiorAvlNode {
public:
    int id , height;
    SuperiorAvlNode *left, *right;
    int getId(){
        return id;
    }
    Avl *nestedAvl;

    SuperiorAvlNode(int id);

    virtual ~SuperiorAvlNode();

    SuperiorAvlNode();

    void setId(int id);

    int getHeight() const;

    void setHeight(int height);

};


#endif //AVLTREE_COPY_SUPERIORAVLNODE_H
