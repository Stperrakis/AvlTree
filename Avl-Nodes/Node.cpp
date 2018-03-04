//
// Created by user on 5/29/2017.
//

#include "Node.h"

Node::Node(int id) : id(id) {
    this->id=id;
    this->height = 1;
    this->right= nullptr;
    this->left = nullptr;

}

Node::~Node() {

}
int Node::getId(){
    return id;
}
Node::Node() {
    this->right= nullptr;
    this->left = nullptr;
    this->height=1;
}

int Node::getHeight() const {
    return height;
}

void Node::setHeight(int height) {
    Node::height = height;
}
