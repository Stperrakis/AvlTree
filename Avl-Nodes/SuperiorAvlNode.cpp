//
// Created by user on 6/1/2017.
//

#include "SuperiorAvlNode.h"
#include "Avl.h"


SuperiorAvlNode::SuperiorAvlNode(int id) {
    this->id=id;
    this->height = 1;
    this->right= nullptr;
    this->left = nullptr;
    this->nestedAvl = nullptr;
}

SuperiorAvlNode::~SuperiorAvlNode() {

}

void SuperiorAvlNode::setId(int id) {
    SuperiorAvlNode::id = id;
}

int SuperiorAvlNode::getHeight() const {
    return height;
}

void SuperiorAvlNode::setHeight(int height) {
    SuperiorAvlNode::height = height;
}

SuperiorAvlNode::SuperiorAvlNode() {
    this->nestedAvl = nullptr;
}


