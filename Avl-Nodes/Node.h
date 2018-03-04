//
// Created by Jack on 9/5/2017.
//

#ifndef AVLTREE_NODE_H
#define AVLTREE_NODE_H


class Node {

public:

    int id, height;
    Node *left,*right;
    void setHeight(int height);
    int getHeight() const;
    int getId();
    Node(int id);
    Node();
    virtual ~Node();



};


#endif //AVLTREE_NODE_H
